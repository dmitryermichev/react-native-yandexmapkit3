#import <YandexMapKit/YMKGeometry.h>
#import <YandexMapKit/YMKVisibleRegion.h>

#import <YandexRuntime/YRTPlatformBinding.h>

@interface YMKVisibleRegionUtils : YRTPlatformBinding

/**
 * Converts geometry to polygons.
 */
+ (nonnull YMKGeometry *)toPolygonWithVisibleRegion:(nonnull YMKVisibleRegion *)visibleRegion;


@end
