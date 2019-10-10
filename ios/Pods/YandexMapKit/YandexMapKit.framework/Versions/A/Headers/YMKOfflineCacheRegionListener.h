#import <Foundation/Foundation.h>

@class YMKOfflineCacheRegion;

/**
 * @attention This feature is not available in the free MapKit version.
 *
 *
 * Listener to handle region information.
 */
@protocol YMKOfflineCacheRegionListener <NSObject>

/**
 * Region state was changed.
 */
- (void)onRegionStateChangedWithRegion:(nonnull YMKOfflineCacheRegion *)region;


/**
 * Progress of specific region download was updated.
 */
- (void)onRegionProgressWithRegion:(nonnull YMKOfflineCacheRegion *)region;


/**
 * Error occurred while downloading the specific region. The download of
 * other regions will continue.
 *
 * @param error Error has occurred. Expected error types: 1.
 * RemoteError: server is unable to provide a specific region. 2.
 * LocalError: unable to store region on disk. General error. 3.
 * DiskFullError: not enough space to store region on disk. 4.
 * RegionOutdatedError: downloaded map is out of date.
 */
- (void)onRegionErrorWithRegion:(nonnull YMKOfflineCacheRegion *)region
                          error:(nonnull NSError *)error;


@end
