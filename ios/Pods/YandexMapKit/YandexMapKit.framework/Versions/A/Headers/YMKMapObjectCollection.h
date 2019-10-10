#import <YandexMapKit/YMKCircle.h>
#import <YandexMapKit/YMKIconStyle.h>
#import <YandexMapKit/YMKMapObject.h>
#import <YandexMapKit/YMKMapObjectCollectionListener.h>
#import <YandexMapKit/YMKMapObjectVisitor.h>
#import <YandexMapKit/YMKPoint.h>
#import <YandexMapKit/YMKPolygon.h>
#import <YandexMapKit/YMKPolyline.h>

#import <YandexRuntime/YRTAnimatedImageProvider.h>
#import <YandexRuntime/YRTViewProvider.h>

#import <UIKit/UIKit.h>

@class YMKCircleMapObject;
@class YMKColoredPolylineMapObject;
@class YMKPlacemarkMapObject;
@class YMKPlacemarksStyler;
@class YMKPolygonMapObject;
@class YMKPolylineMapObject;

/**
 * The way conflicts are resolved.
 */
typedef NS_ENUM(NSUInteger, YMKConflictResolvingMode) {

    /**
     * Placemarks in this collection displace intersected placemarks in map
     * layers. Placemark map objects do not displace each other.
     */
    YMKConflictResolvingModeParticipate,

    /**
     * Placemarks in this collection do not participate in conflict
     * resolving.
     */
    YMKConflictResolvingModeIgnore
};


/**
 * A collection of map objects that can hold any set of MapObject items,
 * including nested collections.
 */
@interface YMKMapObjectCollection : YMKMapObject

/**
 * Creates a new empty placemark and adds it to the current collection.
 */
- (nonnull YMKPlacemarkMapObject *)addEmptyPlacemarkWithPoint:(nonnull YMKPoint *)point;


/**
 * Creates a new placemark with the default icon and style, and adds it
 * to the current collection.
 */
- (nonnull YMKPlacemarkMapObject *)addPlacemarkWithPoint:(nonnull YMKPoint *)point;


/**
 * Creates a new placemark with the default style and adds it to the
 * current collection.
 */
- (nonnull YMKPlacemarkMapObject *)addPlacemarkWithPoint:(nonnull YMKPoint *)point
                                                   image:(nonnull UIImage *)image;


/**
 * Creates a new placemark and adds it to the current collection.
 */
- (nonnull YMKPlacemarkMapObject *)addPlacemarkWithPoint:(nonnull YMKPoint *)point
                                                   image:(nonnull UIImage *)image
                                                   style:(nonnull YMKIconStyle *)style;


/**
 * Creates a new view placemark with default style and adds it to the
 * current collection.
 */
- (nonnull YMKPlacemarkMapObject *)addPlacemarkWithPoint:(nonnull YMKPoint *)point
                                                    view:(nonnull YRTViewProvider *)view;


/**
 * Creates a new view placemark and adds it to the current collection.
 */
- (nonnull YMKPlacemarkMapObject *)addPlacemarkWithPoint:(nonnull YMKPoint *)point
                                                    view:(nonnull YRTViewProvider *)view
                                                   style:(nonnull YMKIconStyle *)style;


/**
 * Creates a new animated placemark and adds it to the current
 * collection.
 */
- (nonnull YMKPlacemarkMapObject *)addPlacemarkWithPoint:(nonnull YMKPoint *)point
                                           animatedImage:(nonnull id<YRTAnimatedImageProvider>)animatedImage
                                                   style:(nonnull YMKIconStyle *)style;


/**
 * Creates a new polyline and adds it to the current collection.
 */
- (nonnull YMKPolylineMapObject *)addPolylineWithPolyline:(nonnull YMKPolyline *)polyline;


/**
 * Creates a new colored polyline and adds it to the current collection.
 */
- (nonnull YMKColoredPolylineMapObject *)addColoredPolylineWithPolyline:(nonnull YMKPolyline *)polyline;


/**
 * Creates a new colored polyline with an empty geometry and adds it to
 * the current collection.
 */
- (nonnull YMKColoredPolylineMapObject *)addColoredPolyline;


/**
 * Creates a new polygon and adds it to the current collection.
 */
- (nonnull YMKPolygonMapObject *)addPolygonWithPolygon:(nonnull YMKPolygon *)polygon;


/**
 * Creates a new circle with the specified style and adds it to the
 * current collection.
 */
- (nonnull YMKCircleMapObject *)addCircleWithCircle:(nonnull YMKCircle *)circle
                                        strokeColor:(nonnull UIColor *)strokeColor
                                        strokeWidth:(float)strokeWidth
                                          fillColor:(nonnull UIColor *)fillColor;


/**
 * Creates a new nested collection of map objects.
 */
- (nonnull YMKMapObjectCollection *)addCollection;


/**
 * Traverses through the collection with a visitor object. Used for
 * iteration over map objects in the collection.
 */
- (void)traverseWithMapObjectVisitor:(nonnull id<YMKMapObjectVisitor>)mapObjectVisitor;


/**
 * Removes the given map object from the collection.
 */
- (void)removeWithMapObject:(nonnull YMKMapObject *)mapObject;


/**
 * Removes all map objects from the collection.
 */
- (void)clear;


/**
 * Adds a listener to track notifications of changes to the collection.
 */
- (void)addListenerWithCollectionListener:(nonnull id<YMKMapObjectCollectionListener>)collectionListener;


/**
 * Sets conflict resolving mode for placemarks in this collection. Child
 * collections inherit value of this property, but can override it.
 * Default value is Ignore.
 */
- (void)setConflictResolvingModeWithMode:(YMKConflictResolvingMode)mode;


/**
 * A styler for all placemarks in this collection, including placemarks
 * in child collections.
 */
- (nonnull YMKPlacemarksStyler *)placemarksStyler;


@end

