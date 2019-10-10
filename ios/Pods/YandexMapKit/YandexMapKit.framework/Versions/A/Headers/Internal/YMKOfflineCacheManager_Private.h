#import <YandexMapKit/YMKOfflineCacheManager.h>

#import <YandexRuntime/YRTSubscription.h>

#import <yandex/maps/mapkit/offline_cache/offline_cache_manager.h>
#import <yandex/maps/runtime/ios/object.h>

#import <memory>

namespace yandex {
namespace maps {
namespace mapkit {
namespace offline_cache {
namespace ios {

OfflineCacheManager::OnClearCompleted onClearCompleted(
    YMKOfflineCacheManagerClearCallback handler);

OfflineCacheManager::OnSizeComputed onSizeComputed(
    YMKOfflineCacheManagerSizeCallback handler);

OfflineCacheManager::OnPathReceived onPathReceived(
    YMKOfflineCacheManagerPathGetterListener handler);
OfflineCacheManager::OnPathReceiveError onPathReceiveError(
    YMKOfflineCacheManagerPathGetterListener handler);

} // namespace ios
} // namespace offline_cache
} // namespace mapkit
} // namespace maps
} // namespace yandex

@interface YMKOfflineCacheManager ()

- (id)initWithWrappedNative:(NSValue *)native;
- (id)initWithNative:(const std::shared_ptr<::yandex::maps::mapkit::offline_cache::OfflineCacheManager>&)native;

- (std::shared_ptr<::yandex::maps::mapkit::offline_cache::OfflineCacheManager>)nativeOfflineCacheManager;
- (std::shared_ptr<::yandex::maps::mapkit::offline_cache::OfflineCacheManager>)native;

@end
