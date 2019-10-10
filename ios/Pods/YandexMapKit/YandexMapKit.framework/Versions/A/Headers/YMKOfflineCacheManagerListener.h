#import <Foundation/Foundation.h>

@class YMKOfflineCacheRegion;

/**
 * @attention This feature is not available in the free MapKit version.
 *
 *
 * The listener for offline information updates.
 */
@protocol YMKOfflineCacheManagerListener <NSObject>

/**
 * The map list was loaded from a DB or updated from the server. All
 * regions should be invalidated after this call.
 */
- (void)onListUpdated;


/**
 * Region state was updated.
 */
- (void)onRegionStateUpdatedWithRegion:(nonnull YMKOfflineCacheRegion *)region;


@end
