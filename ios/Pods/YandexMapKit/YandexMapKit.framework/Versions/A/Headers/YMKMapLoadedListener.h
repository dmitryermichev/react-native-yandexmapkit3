#import <YandexMapKit/YMKMapLoadStatistics.h>

/**
 * Checks if the map is loaded.
 */
@protocol YMKMapLoadedListener <NSObject>

/**
 * Called after the map has finished loading tiles and all labeling is
 * complete. Will not be called if some tiles failed to load or if the
 * map is constantly updating due to ongoing user interaction.
 */
- (void)onMapLoadedWithStatistics:(nonnull YMKMapLoadStatistics *)statistics;


@end
