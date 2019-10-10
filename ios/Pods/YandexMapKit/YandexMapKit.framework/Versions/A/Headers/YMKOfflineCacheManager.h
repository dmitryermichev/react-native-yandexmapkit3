#import <YandexMapKit/YMKOfflineCacheDataMoveListener.h>
#import <YandexMapKit/YMKOfflineCacheManagerListener.h>
#import <YandexMapKit/YMKStorageErrorListener.h>

#import <YandexRuntime/YRTPlatformBinding.h>

@class YMKOfflineCacheRegion;

typedef void(^YMKOfflineCacheManagerClearCallback)(
    );

typedef void(^YMKOfflineCacheManagerSizeCallback)(
    NSNumber *size);

typedef void(^YMKOfflineCacheManagerPathGetterListener)(
    NSString *path,
    NSError *error);

/**
 * @attention This feature is not available in the free MapKit version.
 *
 *
 * Offline cache manager.
 *
 * There are a number of asynchronous operations that shouldn't be
 * executed simultaneously. When multiple operations from the following
 * list are executed in parallel, there's no guarantee that they will
 * take effect in the order they were issued:
 * YMKOfflineCacheManager::computeCacheSizeWithSizeCallback:
 * YMKOfflineCacheManager::clearWithClearCallback:
 * YMKOfflineCacheManager::moveDataWithNewPath:dataMoveListener:
 * YMKOfflineCacheRegion::drop YMKOfflineCacheRegion::start
 */
@interface YMKOfflineCacheManager : YRTPlatformBinding

/**
 * Subscribes a listener for "download status" events. The listener will
 * receive the onListUpdated callback asynchronously after the call.
 *
 * @param managerListener Listener that will receive the events.
 */
- (void)addListenerWithManagerListener:(nonnull id<YMKOfflineCacheManagerListener>)managerListener;


/**
 * Unsubscribes the listener from manager events. Does nothing if the
 * listener was not subscribed.
 *
 * @param managerListener Listener to unsubscribe.
 */
- (void)removeListenerWithManagerListener:(nonnull id<YMKOfflineCacheManagerListener>)managerListener;


/**
 * Subscribes the listener to storage error events.
 *
 * @param errorListener Listener that will receive storage error events.
 */
- (void)addStorageErrorListenerWithErrorListener:(nonnull id<YMKStorageErrorListener>)errorListener;


/**
 * Unsubscribes the error listener from storage error events. Does
 * nothing if the error listener was not subscribed.
 *
 * @param errorListener Listener to unsubscribe.
 */
- (void)removeStorageErrorListenerWithErrorListener:(nonnull id<YMKStorageErrorListener>)errorListener;


/**
 * Returns a list of regions. An empty list indicates that the list is
 * still loading. When it is ready, onListUpdated event will be called
 * with the added/removed regions.
 */
- (nonnull NSArray<YMKOfflineCacheRegion *> *)regions;


/**
 * Indicates whether to allow downloading using cellular networks (3G,
 * LTE, etc.) Disallowed by default.
 */
- (void)allowUseCellularNetworkWithUseCellular:(BOOL)useCellular;


/**
 * Erases all data for downloads and regions and wipes the tile cache.
 * Forces reloading the list from the remote source.
 */
- (void)clearWithClearCallback:(nonnull YMKOfflineCacheManagerClearCallback)clearCallback;


/**
 * Calculates the full cache size in bytes.
 */
- (void)computeCacheSizeWithSizeCallback:(nonnull YMKOfflineCacheManagerSizeCallback)sizeCallback;


/**
 * Provides the data path for offline cache files.
 */
- (void)requestPathWithPathGetterListener:(nonnull YMKOfflineCacheManagerPathGetterListener)pathGetterListener;


/**
 * Moves offline caches to the specified folder. This operation is
 * non-cancellable. If there is already a pending operation to set the
 * cache path, it throws an error (Android). If the application exits
 * before the operation is completed, it does not take effect, but
 * garbage will not be cleared.
 *
 * @param newPath New path to store data.
 * @param dataMoveListener It will be unsubscribed automatically when
 * the operation is completed or fails with an error.
 */
- (void)moveDataWithNewPath:(nonnull NSString *)newPath
           dataMoveListener:(nonnull id<YMKOfflineCacheDataMoveListener>)dataMoveListener;


/**
 * Sets a new path for caches. If the specified path contains an
 * existing cache, this cache will be used; otherwise, a new cache will
 * be initialized. This takes effect after the application is restarted.
 */
- (void)setCachePathWithPath:(nonnull NSString *)path;


/**
 * Enables autoupdating downloaded caches when they become outdated.
 */
- (void)enableAutoUpdateWithEnable:(BOOL)enable;


/**
 * Returns a filtered list of regions. The filtered list is a subset of
 * the full list of regions. Note that if the full list of regions is
 * not ready yet, then the returned list of filtered regions will be
 * empty. The list will also be empty if there aren't any regions that
 * match the 'filter' expression.
 */
- (nonnull NSArray<YMKOfflineCacheRegion *> *)filterRegionsWithFilter:(nonnull NSString *)filter;


/// @cond EXCLUDE
/**
 * This method turns all to outated. Only for testing.
 */
- (void)simulateUpdate;
/// @endcond


/**
 * Tells if this object is valid or no. Any method called on an invalid
 * object will throw an exception. The object becomes invalid only on UI
 * thread, and only when its implementation depends on objects already
 * destroyed by now. Please refer to general docs about the interface for
 * details on its invalidation.
 */
@property (nonatomic, readonly, getter=isValid) BOOL valid;

@end

