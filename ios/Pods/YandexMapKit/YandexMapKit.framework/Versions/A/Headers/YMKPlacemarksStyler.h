#import <YandexRuntime/YRTPlatformBinding.h>

#import <UIKit/UIKit.h>

/**
 * Represents a styler for all placemarks in the map object collection,
 * including placemarks in child collections. When a new placemark is
 * added to a collection, the placemark tries to get style properties
 * from the collection where it has been added. If this collection
 * doesn't have a style property, the placemark tries to get it from the
 * closest parent collection. If this collection and the parent
 * collections don't have a specific style property, the placemark sets
 * this property to the default.
 */
@interface YMKPlacemarksStyler : YRTPlatformBinding

/**
 * Sets piecewise linear scale depending on the zoom. 'points' must be
 * sorted by x; x coordinates must be unique. If zoom < minZoom(points)
 * or zoom > maxZoom(points), it is set within the defined bounds before
 * applying the function. By default, the scale function is defined by a
 * single point (1, 1). If a point is null or points.empty() it resets
 * the function to default. If points.size() == 1, the scale is constant
 * and equals point.y.
 */
- (void)setScaleFunctionWithPoints:(nonnull NSArray<NSValue *> *)points;


/**
 * Tells if this object is valid or no. Any method called on an invalid
 * object will throw an exception. The object becomes invalid only on UI
 * thread, and only when its implementation depends on objects already
 * destroyed by now. Please refer to general docs about the interface for
 * details on its invalidation.
 */
@property (nonatomic, readonly, getter=isValid) BOOL valid;

@end

