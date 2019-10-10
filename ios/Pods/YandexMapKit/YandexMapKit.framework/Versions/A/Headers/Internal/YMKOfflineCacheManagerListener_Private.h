#import <YandexMapKit/YMKOfflineCacheManagerListener.h>

#import <yandex/maps/mapkit/offline_cache/offline_cache_manager_listener.h>
#import <yandex/maps/runtime/bindings/ios/to_native.h>
#import <yandex/maps/runtime/bindings/ios/to_platform.h>

namespace yandex {
namespace maps {
namespace mapkit {
namespace offline_cache {
namespace ios {

class OfflineCacheManagerListenerBinding : public ::yandex::maps::mapkit::offline_cache::OfflineCacheManagerListener {
public:
    explicit OfflineCacheManagerListenerBinding(
        id<YMKOfflineCacheManagerListener> platformListener);

    virtual void onListUpdated() override;

    virtual void onRegionStateUpdated(
        ::yandex::maps::mapkit::offline_cache::Region* region) override;

    id<YMKOfflineCacheManagerListener> platformReference() const { return platformListener_; }

private:
    __weak id<YMKOfflineCacheManagerListener> platformListener_;
};

} // namespace ios
} // namespace offline_cache
} // namespace mapkit
} // namespace maps
} // namespace yandex

namespace yandex {
namespace maps {
namespace runtime {
namespace bindings {
namespace ios {
namespace internal {

template <>
struct ToNative<std::shared_ptr<::yandex::maps::mapkit::offline_cache::OfflineCacheManagerListener>, id<YMKOfflineCacheManagerListener>, void> {
    static std::shared_ptr<::yandex::maps::mapkit::offline_cache::OfflineCacheManagerListener> from(
        id<YMKOfflineCacheManagerListener> platformOfflineCacheManagerListener);
};
template <typename PlatformType>
struct ToNative<std::shared_ptr<::yandex::maps::mapkit::offline_cache::OfflineCacheManagerListener>, PlatformType> {
    static std::shared_ptr<::yandex::maps::mapkit::offline_cache::OfflineCacheManagerListener> from(
        PlatformType platformOfflineCacheManagerListener)
    {
        return ToNative<std::shared_ptr<::yandex::maps::mapkit::offline_cache::OfflineCacheManagerListener>, id<YMKOfflineCacheManagerListener>>::from(
            platformOfflineCacheManagerListener);
    }
};

template <>
struct ToPlatform<std::shared_ptr<::yandex::maps::mapkit::offline_cache::OfflineCacheManagerListener>> {
    static id<YMKOfflineCacheManagerListener> from(
        const std::shared_ptr<::yandex::maps::mapkit::offline_cache::OfflineCacheManagerListener>& nativeOfflineCacheManagerListener);
};

} // namespace internal
} // namespace ios
} // namespace bindings
} // namespace runtime
} // namespace maps
} // namespace yandex
