#import <YandexMapKit/YMKStorageErrorListener.h>

#import <yandex/maps/mapkit/storage/storage_error_listener.h>
#import <yandex/maps/runtime/bindings/ios/to_native.h>
#import <yandex/maps/runtime/bindings/ios/to_platform.h>

namespace yandex {
namespace maps {
namespace mapkit {
namespace storage {
namespace ios {

class StorageErrorListenerBinding : public ::yandex::maps::mapkit::storage::StorageErrorListener {
public:
    explicit StorageErrorListenerBinding(
        id<YMKStorageErrorListener> platformListener);

    virtual void onStorageError(
        ::yandex::maps::runtime::Error* error) override;

    id<YMKStorageErrorListener> platformReference() const { return platformListener_; }

private:
    __weak id<YMKStorageErrorListener> platformListener_;
};

} // namespace ios
} // namespace storage
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
struct ToNative<std::shared_ptr<::yandex::maps::mapkit::storage::StorageErrorListener>, id<YMKStorageErrorListener>, void> {
    static std::shared_ptr<::yandex::maps::mapkit::storage::StorageErrorListener> from(
        id<YMKStorageErrorListener> platformStorageErrorListener);
};
template <typename PlatformType>
struct ToNative<std::shared_ptr<::yandex::maps::mapkit::storage::StorageErrorListener>, PlatformType> {
    static std::shared_ptr<::yandex::maps::mapkit::storage::StorageErrorListener> from(
        PlatformType platformStorageErrorListener)
    {
        return ToNative<std::shared_ptr<::yandex::maps::mapkit::storage::StorageErrorListener>, id<YMKStorageErrorListener>>::from(
            platformStorageErrorListener);
    }
};

template <>
struct ToPlatform<std::shared_ptr<::yandex::maps::mapkit::storage::StorageErrorListener>> {
    static id<YMKStorageErrorListener> from(
        const std::shared_ptr<::yandex::maps::mapkit::storage::StorageErrorListener>& nativeStorageErrorListener);
};

} // namespace internal
} // namespace ios
} // namespace bindings
} // namespace runtime
} // namespace maps
} // namespace yandex
