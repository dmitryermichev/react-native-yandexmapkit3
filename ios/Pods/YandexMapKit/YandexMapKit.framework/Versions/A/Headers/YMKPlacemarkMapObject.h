#import <YandexMapKit/YMKCallback.h>
#import <YandexMapKit/YMKIconStyle.h>
#import <YandexMapKit/YMKMapObject.h>
#import <YandexMapKit/YMKModelStyle.h>
#import <YandexMapKit/YMKPoint.h>

#import <YandexRuntime/YRTViewProvider.h>

#import <UIKit/UIKit.h>

@class YMKAnimatedIcon;
@class YMKCompositeIcon;

/**
 * Represents a geo-positioned object on the map.
 */
@interface YMKPlacemarkMapObject : YMKMapObject

/**
 * Position of the object.
 */
@property (nonatomic, nonnull) YMKPoint *geometry;

/**
 * Angle between the direction of an object and the direction to north.
 * Measured in degrees. Default: 0.f.
 */
@property (nonatomic) float direction;

/**
 * Opacity multiplicator for the placemark content. Values below 0 will
 * be set to 0. Default: 1.
 */
@property (nonatomic) float opacity;

/**
 * Sets an icon with the default style for the placemark. Resets the
 * animated icon, the composite icon, the view and the model.
 */
- (void)setIconWithImage:(nonnull UIImage *)image;


/**
 * Sets an icon with the given style for the placemark. Resets the
 * animated icon, the composite icon, the view and the model.
 */
- (void)setIconWithImage:(nonnull UIImage *)image
                   style:(nonnull YMKIconStyle *)style;


/**
 * Sets an icon with the default style for the placemark. Resets the
 * animated icon, the composite icon, the view and the model. The
 * callback is called immediately after the image finished loading. This
 * means you can, for example, change the placemark visibility with a
 * new icon.
 *
 * @param onFinished Called when the icon is loaded.
 */
- (void)setIconWithImage:(nonnull UIImage *)image
                callback:(nonnull YMKCallback)callback;


/**
 * Sets an icon with the given style for the placemark. Resets the
 * animated icon, the composite icon, the view and the model. The
 * callback is called immediately after the image finished loading. This
 * means you can, for example, change the placemark visibility with a
 * new icon.
 *
 * @param onFinished Called when the icon is loaded.
 */
- (void)setIconWithImage:(nonnull UIImage *)image
                   style:(nonnull YMKIconStyle *)style
                callback:(nonnull YMKCallback)callback;


/**
 * Changes the icon style. Valid only for the single icon, the view and
 * the animated icon.
 */
- (void)setIconStyleWithStyle:(nonnull YMKIconStyle *)style;


/**
 * Sets and returns the composite icon. Resets the single icon, the
 * animated icon, the view and the model.
 */
- (nonnull YMKCompositeIcon *)useCompositeIcon;


/**
 * Sets and returns the animated icon. Resets the single icon, the
 * composite icon, the view and the model.
 */
- (nonnull YMKAnimatedIcon *)useAnimatedIcon;


/**
 * Changes the model style.
 */
- (void)setModelStyleWithModelStyle:(nonnull YMKModelStyle *)modelStyle;


/**
 * Sets the model. Resets icons and the view.
 */
- (void)setModelWithObj:(nonnull NSString *)obj
        textureProvider:(nonnull UIImage *)textureProvider
                  style:(nonnull YMKModelStyle *)style;


/**
 * Sets the model. Resets icons and the view. The callback will be
 * called immediately after model loading finishes.
 */
- (void)setModelWithObj:(nonnull NSString *)obj
        textureProvider:(nonnull UIImage *)textureProvider
                  style:(nonnull YMKModelStyle *)style
               callback:(nonnull YMKCallback)callback;


/**
 * Sets the view with the default style to the placemark. Resets icons
 * and the model.
 */
- (void)setViewWithView:(nonnull YRTViewProvider *)view;


/**
 * Sets the view with the given style for the placemark. Resets icons
 * and the model.
 */
- (void)setViewWithView:(nonnull YRTViewProvider *)view
                  style:(nonnull YMKIconStyle *)style;


/**
 * Sets the view with the default style for the placemark. Resets icons
 * and the model. The callback will be called immediately after the view
 * finished loading.
 *
 * @param onFinished Called when the icon is loaded.
 */
- (void)setViewWithView:(nonnull YRTViewProvider *)view
               callback:(nonnull YMKCallback)callback;


/**
 * Sets the view with the given style for the placemark. Resets icons
 * and the model. The callback will be called immediately after the view
 * finished loading.
 *
 * @param onFinished Called when the icon is loaded.
 */
- (void)setViewWithView:(nonnull YRTViewProvider *)view
                  style:(nonnull YMKIconStyle *)style
               callback:(nonnull YMKCallback)callback;


/**
 * Sets piecewise linear scale depending on the zoom. 'points' must be
 * sorted by x; x coordinates must be unique. If zoom < minZoom(points)
 * or zoom > maxZoom(points), it is set within the defined bounds before
 * applying the function. By default, the scale function is defined by a
 * single point (1, 1). If a point is null or points.empty() it resets
 * the function to default. If points.size() == 1, scale is constant and
 * equals point.y.
 */
- (void)setScaleFunctionWithPoints:(nonnull NSArray<NSValue *> *)points;


@end

