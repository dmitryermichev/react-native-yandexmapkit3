#import <Foundation/Foundation.h>

/**
 * @attention This feature is not available in the free MapKit version.
 *
 *
 * The state of the region.
 */
typedef NS_ENUM(NSUInteger, YMKOfflineCacheRegionState) {

    /**
     * Available for download on server.
     */
    YMKOfflineCacheRegionStateAvailable,

    /**
     * Download in progress (or paused).
     */
    YMKOfflineCacheRegionStateDownloading,

    /**
     * Download is paused.
     */
    YMKOfflineCacheRegionStatePaused,

    /**
     * Cache data is being installed.
     */
    YMKOfflineCacheRegionStateInstallation,

    /**
     * Cache data installation is finished.
     */
    YMKOfflineCacheRegionStateCompleted,

    /**
     * The region was completed but there is a newer version on server
     */
    YMKOfflineCacheRegionStateOutdated
};

