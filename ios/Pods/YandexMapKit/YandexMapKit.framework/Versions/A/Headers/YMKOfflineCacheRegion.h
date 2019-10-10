#import <YandexMapKit/YMKLocalizedValue.h>
#import <YandexMapKit/YMKOfflineCacheRegionListener.h>
#import <YandexMapKit/YMKOfflineCacheRegionState.h>
#import <YandexMapKit/YMKPoint.h>

#import <YandexRuntime/YRTPlatformBinding.h>

/**
 * @attention This feature is not available in the free MapKit version.
 *
 *
 * Region information.
 */
@interface YMKOfflineCacheRegion : YRTPlatformBinding

/**
 * Subscribe the listener to receive all manager notifications.
 */
- (void)addListenerWithRegionListener:(nonnull id<YMKOfflineCacheRegionListener>)regionListener;


/**
 * Unsubscribe the listener from receiving all manager notifications.
 */
- (void)removeListenerWithRegionListener:(nonnull id<YMKOfflineCacheRegionListener>)regionListener;


/**
 * Add the map to the download queue. The download will be started
 * (resumed) immediately.
 */
- (void)start;


/**
 * Cancel the download, if any.
 */
- (void)stop;


/**
 * Pause the download.
 */
- (void)pause;


/**
 * Drop region data from the device. If data is being downloaded then
 * downloading is cancelled.
 */
- (void)drop;


/**
 * Name of the region.
 */
@property (nonatomic, readonly, nonnull) NSString *name;

/**
 * Country of the region.
 */
@property (nonatomic, readonly, nonnull) NSString *country;

/**
 * Cities inside the region.
 */
@property (nonatomic, readonly, nonnull) NSArray<NSString *> *cities;

/**
 * Center point.
 */
@property (nonatomic, readonly, nonnull) YMKPoint *center;

/**
 * Region ID.
 */
@property (nonatomic, readonly) NSUInteger regionId;

/**
 * State of the region.
 */
@property (nonatomic, readonly) YMKOfflineCacheRegionState state;

/**
 * Returns the download progress (0..1).
 */
@property (nonatomic, readonly) float progress;

/**
 * Returns the size of the download in bytes.
 */
@property (nonatomic, readonly, nonnull) YMKLocalizedValue *downloadSize;

/**
 * Returns the region creation time.
 */
@property (nonatomic, readonly, nonnull) NSDate *releaseTime;

/**
 * Returns true if available disk space might not be enough for
 * installation of the region data.
 */
- (BOOL)mayBeOutOfAvailableSpace;


/**
 * Tells if this object is valid or no. Any method called on an invalid
 * object will throw an exception. The object becomes invalid only on UI
 * thread, and only when its implementation depends on objects already
 * destroyed by now. Please refer to general docs about the interface for
 * details on its invalidation.
 */
@property (nonatomic, readonly, getter=isValid) BOOL valid;

@end

