#import <YandexMapKit/YMKAnimation.h>
#import <YandexMapKit/YMKBoundingBox.h>
#import <YandexMapKit/YMKCameraPosition.h>
#import <YandexMapKit/YMKGlyphsGlyphUrlProvider.h>
#import <YandexMapKit/YMKInertiaMoveListener.h>
#import <YandexMapKit/YMKLayer.h>
#import <YandexMapKit/YMKLayerOptions.h>
#import <YandexMapKit/YMKLayersGeoObjectTapListener.h>
#import <YandexMapKit/YMKLogo.h>
#import <YandexMapKit/YMKMapCameraListener.h>
#import <YandexMapKit/YMKMapIndoorStateListener.h>
#import <YandexMapKit/YMKMapInputListener.h>
#import <YandexMapKit/YMKMapLoadedListener.h>
#import <YandexMapKit/YMKMapType.h>
#import <YandexMapKit/YMKProjection.h>
#import <YandexMapKit/YMKResourceUrlProvider.h>
#import <YandexMapKit/YMKTileFormat.h>
#import <YandexMapKit/YMKTileProvider.h>
#import <YandexMapKit/YMKTilesUrlProvider.h>
#import <YandexMapKit/YMKUserLocationLayer.h>
#import <YandexMapKit/YMKVisibleRegion.h>
#import <YandexMapKit/YMKZoomRange.h>

#import <YandexRuntime/YRTPlatformBinding.h>

#import <UIKit/UIKit.h>

@class YMKIconSet;
@class YMKMapObjectCollection;
@class YMKSublayerManager;

typedef void(^YMKMapCameraCallback)(
    BOOL completed);

/**
 * The object that is used to interact with the map.
 */
@interface YMKMap : YRTPlatformBinding

/**
 * @return Current camera position. Target position must be within
 * latitude [-90, 90] and longitude [-180, 180].
 */
@property (nonatomic, readonly, nonnull) YMKCameraPosition *cameraPosition;

/**
 * Calculates the camera position that projects the specified area into
 * the view.
 */
- (nonnull YMKCameraPosition *)cameraPositionWithBoundingBox:(nonnull YMKBoundingBox *)boundingBox;


/**
 * @return The map region that is currently visible. Region IS bounded
 * by latitude limits [-90, 90] and IS NOT bounded by longitude limits
 * [-180, 180]. If the longitude exceeds its limits, we see the world's
 * edge and another instance of the world beyond this edge.
 */
@property (nonatomic, readonly, nonnull) YMKVisibleRegion *visibleRegion;

/**
 * @return The map region that is visible from the given camera
 * position. Region IS bounded by latitude limits [-90, 90] and IS NOT
 * bounded by longitude limits [-180, 180]. If the longitude exceeds its
 * limits, we see the world's edge and another instance of the world
 * beyond this edge.
 */
- (nonnull YMKVisibleRegion *)visibleRegionWithCameraPosition:(nonnull YMKCameraPosition *)cameraPosition;


/**
 * Changes camera position. Can cancel a previous unfinished movement.
 *
 * @param animationType Required. Defines animation parameters. Deferred
 * teleportation can be achieved via Animation::Step with the necessary
 * duration. @see Animation for more details.
 * @param cameraCallback A function that takes the bool argument marking
 * the camera action complete. Invoked when: 1) A camera action is
 * cancelled (for example, as a result of a subsequent request for
 * camera movement), passing false as an argument. 2) A camera action
 * finished successfully, passing true as an argument.
 *
 * Remark:
 * @param cameraCallback has optional type, it may be uninitialized.
 */
- (void)moveWithCameraPosition:(nonnull YMKCameraPosition *)cameraPosition
                 animationType:(nonnull YMKAnimation *)animationType
                cameraCallback:(nullable YMKMapCameraCallback)cameraCallback;


/**
 * Immediately changes the camera position. Can cancel a previous
 * unfinished movement.
 */
- (void)moveWithCameraPosition:(nonnull YMKCameraPosition *)cameraPosition;


/**
 * Sets piecewise linear tilt depending on the zoom. 'points' must be
 * sorted by x; x coordinates must be unique. If zoom < minZoom(points)
 * or zoom > maxZoom(points), it is set within the defined bounds before
 * applying the function. If points is null or points.empty() it erases
 * the previously set function. If points.size() == 1, tilt is constant
 * and equals point.y.
 */
- (void)setTiltFunctionWithPoints:(nonnull NSArray<NSValue *> *)points;


/**
 * Minimum available zoom level.
 */
- (float)getMinZoom;


/**
 * Maximum available zoom level.
 */
- (float)getMaxZoom;


/**
 * Adds a layer that displays tiles from the user-defined TileProvider.
 * Sublayers will be added after corresponding sublayers of the map
 * layer.
 */
- (nonnull YMKLayer *)addLayerWithLayerId:(nonnull NSString *)layerId
                              contentType:(nonnull NSString *)contentType
                             layerOptions:(nonnull YMKLayerOptions *)layerOptions
                             tileProvider:(nonnull id<YMKTileProvider>)tileProvider
                         imageUrlProvider:(nonnull id<YMKResourceUrlProvider>)imageUrlProvider
                               projection:(nonnull id<YMKProjection>)projection;


/**
 * Adds a layer that uses the network to load tiles from URLs obtained
 * through UrlProvider. Sublayers will be added after corresponding
 * sublayers of the map layer.
 *
 * @param layerId The id of the layer.
 * @param contentType Layer content type.
 * @param layerOptions Layer options.
 * @param urlProvider URL provider.
 * @param imageUrlProvider Image URL provider.
 * @param projection Projection.
 */
- (nonnull YMKLayer *)addLayerWithLayerId:(nonnull NSString *)layerId
                              contentType:(nonnull NSString *)contentType
                             layerOptions:(nonnull YMKLayerOptions *)layerOptions
                              urlProvider:(nonnull id<YMKTilesUrlProvider>)urlProvider
                         imageUrlProvider:(nonnull id<YMKResourceUrlProvider>)imageUrlProvider
                               projection:(nonnull id<YMKProjection>)projection;


/**
 * Adds a vector layer which uses the network to load tiles from URLs
 * obtained through UrlProvider, images, models and glyphs obtained
 * through their respective UrlProviders Sublayers will be added after
 * corresponding sublayers of the map layer.
 */
- (nonnull YMKLayer *)addLayerWithLayerId:(nonnull NSString *)layerId
                              contentType:(nonnull NSString *)contentType
                             layerOptions:(nonnull YMKLayerOptions *)layerOptions
                         tilesUrlProvider:(nonnull id<YMKTilesUrlProvider>)tilesUrlProvider
                         imageUrlProvider:(nonnull id<YMKResourceUrlProvider>)imageUrlProvider
                         modelUrlProvider:(nonnull id<YMKResourceUrlProvider>)modelUrlProvider
                         glyphUrlProvider:(nonnull id<YMKGlyphsGlyphUrlProvider>)glyphUrlProvider
                               projection:(nonnull id<YMKProjection>)projection
                               zoomRanges:(nonnull NSArray<YMKZoomRange *> *)zoomRanges;


/**
 * Adds a vector layer which uses the network to load tiles from URLs
 * obtained through UrlProvider, images, models, styles and glyphs
 * obtained through their respective UrlProviders Sublayers will be
 * added after corresponding sublayers of the map layer.
 */
- (nonnull YMKLayer *)addLayerWithLayerId:(nonnull NSString *)layerId
                              contentType:(nonnull NSString *)contentType
                                   format:(YMKTileFormat)format
                             layerOptions:(nonnull YMKLayerOptions *)layerOptions
                         tilesUrlProvider:(nonnull id<YMKTilesUrlProvider>)tilesUrlProvider
                         imageUrlProvider:(nonnull id<YMKResourceUrlProvider>)imageUrlProvider
                         modelUrlProvider:(nonnull id<YMKResourceUrlProvider>)modelUrlProvider
                         styleUrlProvider:(nonnull id<YMKResourceUrlProvider>)styleUrlProvider
                         glyphUrlProvider:(nonnull id<YMKGlyphsGlyphUrlProvider>)glyphUrlProvider
                               projection:(nonnull id<YMKProjection>)projection
                               zoomRanges:(nonnull NSArray<YMKZoomRange *> *)zoomRanges;


/**
 * If enabled, night mode will reduce map brightness and improve
 * contrast.
 */
@property (nonatomic, getter=isNightModeEnabled) BOOL nightModeEnabled;

/**
 * Enable/disable zoom gestures, for example: - pinch - double tap (zoom
 * in) - tap with two fingers (zoom out)
 */
@property (nonatomic, getter=isZoomGesturesEnabled) BOOL zoomGesturesEnabled;

/**
 * Enable/disable scroll gestures, such as the pan gesture.
 */
@property (nonatomic, getter=isScrollGesturesEnabled) BOOL scrollGesturesEnabled;

/**
 * Enable/disable tilt gestures, such as parallel pan with two fingers.
 */
@property (nonatomic, getter=isTiltGesturesEnabled) BOOL tiltGesturesEnabled;

/**
 * Enable/disable rotation gestures, such as rotation with two fingers.
 */
@property (nonatomic, getter=isRotateGesturesEnabled) BOOL rotateGesturesEnabled;

/**
 * Removes the 300 ms delay in emitting a tap gesture. However, a
 * double-tap will emit a tap gesture along with a double-tap.
 */
@property (nonatomic, getter=isFastTapEnabled) BOOL fastTapEnabled;

/**
 * Sets the base map type.
 */
@property (nonatomic) YMKMapType mapType;

/**
 * Enables/disables indoor floor plans on the map.
 */
@property (nonatomic, getter=isIndoorEnabled) BOOL indoorEnabled;

/**
 * Adds indoor listener to receive notifications on indoor-realted
 * events.
 */
- (void)addIndoorStateListenerWithIndoorStateListener:(nonnull id<YMKMapIndoorStateListener>)indoorStateListener;


/**
 * removes indoor listener to receive notifications on indoor-realted
 * events.
 */
- (void)removeIndoorStateListenerWithIndoorStateListener:(nonnull id<YMKMapIndoorStateListener>)indoorStateListener;


/**
 * Adds input listeners.
 */
- (void)addInputListenerWithInputListener:(nonnull id<YMKMapInputListener>)inputListener;


/**
 * Removes input listeners.
 */
- (void)removeInputListenerWithInputListener:(nonnull id<YMKMapInputListener>)inputListener;


/**
 * Adds camera listeners.
 */
- (void)addCameraListenerWithCameraListener:(nonnull id<YMKMapCameraListener>)cameraListener;


/**
 * Removes camera listeners.
 */
- (void)removeCameraListenerWithCameraListener:(nonnull id<YMKMapCameraListener>)cameraListener;


/**
 * Adds inertia move listeners.
 */
- (void)addInertiaMoveListenerWithInertiaMoveListener:(nonnull id<YMKInertiaMoveListener>)inertiaMoveListener;


/**
 * Removes inertia move listeners.
 */
- (void)removeInertiaMoveListenerWithInertiaMoveListener:(nonnull id<YMKInertiaMoveListener>)inertiaMoveListener;


/**
 * Sets a map loaded listener.
 *
 * Remark:
 * @param mapLoadedListener has optional type, it may be uninitialized.
 */
- (void)setMapLoadedListenerWithMapLoadedListener:(nullable id<YMKMapLoadedListener>)mapLoadedListener;


/**
 * @return List of map objects associated with the map.
 */
@property (nonatomic, readonly, nonnull) YMKMapObjectCollection *mapObjects;

/**
 * Adds a tap listener that is used to obtain brief geo object info.
 */
- (void)addTapListenerWithTapListener:(nonnull id<YMKLayersGeoObjectTapListener>)tapListener;


/**
 * Removes a tap listener that is used to obtain brief geo object info.
 */
- (void)removeTapListenerWithTapListener:(nonnull id<YMKLayersGeoObjectTapListener>)tapListener;


/**
 * Resets the currently selected geo object.
 */
- (void)deselectGeoObject;


/**
 * Selects a geo object with the specified objectId in the specified
 * layerId. If the object is not currently on the screen, it is selected
 * anyway, but the user will not actually see that. You need to move the
 * camera in addition to this call to be sure that the selected object
 * is visible for the user. Both objectId and layerId can be extracted
 * from the geo object's metadata container by using
 * geo_object_selection_metadata when the user taps on a geo object.
 */
- (void)selectGeoObjectWithObjectId:(nonnull NSString *)objectId
                            layerId:(nonnull NSString *)layerId;


/**
 * Yandex logo object.
 */
@property (nonatomic, readonly, nonnull) YMKLogo *logo;

/**
 * Layer with the user location icon.
 */
@property (nonatomic, readonly, nonnull) YMKUserLocationLayer *userLocationLayer;

/**
 * Enables/disables detailed 3D models on the map. Enabled by default.
 */
@property (nonatomic, getter=isModelsEnabled) BOOL modelsEnabled;

/// @cond EXCLUDE
/**
 * Enables/disables displaying map debug information on the screen.
 */
@property (nonatomic, getter=isDebugInfoEnabled) BOOL debugInfoEnabled;
/// @endcond

/// @cond EXCLUDE
/**
 * Enables/disables lite rendering mode.
 */
@property (nonatomic, getter=isLiteModeEnabled) BOOL liteModeEnabled;
/// @endcond

/**
 * Applies JSON style transformations to the map. Affects VectorMap and
 * Hybrid map types. Set to null to clear any previous custom styling.
 * Returns true if the style was successfully parsed, and false
 * otherwise. If the returned value is false, the current map style
 * remains unchanged.
 */
- (BOOL)setMapStyleWithStyle:(nonnull NSString *)style;


/**
 * The icon set provides an interface for adding custom icons to be used
 * in layer customization. Affects VectorMap and Hybrid map types.
 */
@property (nonatomic, readonly, nonnull) YMKIconSet *layerIconSet;

/**
 * Forces the map to be flat. true - All loaded tiles start showing the
 * "flatten out" animation; all new tiles do not start 3D animation.
 * false - All tiles start showing the "rise up" animation.
 */
- (void)set2DModeWithEnable:(BOOL)enable;


/**
 * Creates a new independent map object collection linked to the
 * specified layer ID. Sublayers will be added after corresponding
 * sublayers of the topmost layer.
 */
- (nonnull YMKMapObjectCollection *)addMapObjectLayerWithLayerId:(nonnull NSString *)layerId;


/**
 * Manages the collection of sublayers that define the drawing order.
 */
@property (nonatomic, readonly, nonnull) YMKSublayerManager *sublayerManager;

/**
 * Tells if this object is valid or no. Any method called on an invalid
 * object will throw an exception. The object becomes invalid only on UI
 * thread, and only when its implementation depends on objects already
 * destroyed by now. Please refer to general docs about the interface for
 * details on its invalidation.
 */
@property (nonatomic, readonly, getter=isValid) BOOL valid;

@end

