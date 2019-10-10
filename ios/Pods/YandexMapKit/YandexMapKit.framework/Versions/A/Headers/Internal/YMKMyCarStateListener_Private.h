#import <YandexMapKit/YMKMyCarStateListener.h>

#import <yandex/maps/mapkit/carparks_detector/my_car_state_manager.h>
#import <yandex/maps/runtime/bindings/ios/to_native.h>
#import <yandex/maps/runtime/bindings/ios/to_platform.h>

namespace yandex {
namespace maps {
namespace mapkit {
namespace carparks_detector {
namespace ios {

class MyCarStateListenerBinding : public ::yandex::maps::mapkit::carparks_detector::MyCarStateListener {
public:
    explicit MyCarStateListenerBinding(
        id<YMKMyCarStateListener> platformListener);

    virtual void onMyCarStateUpdate(
        const ::yandex::maps::mapkit::carparks_detector::MyCarState& state) override;

    id<YMKMyCarStateListener> platformReference() const { return platformListener_; }

private:
    __weak id<YMKMyCarStateListener> platformListener_;
};

} // namespace ios
} // namespace carparks_detector
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
struct ToNative<std::shared_ptr<::yandex::maps::mapkit::carparks_detector::MyCarStateListener>, id<YMKMyCarStateListener>, void> {
    static std::shared_ptr<::yandex::maps::mapkit::carparks_detector::MyCarStateListener> from(
        id<YMKMyCarStateListener> platformMyCarStateListener);
};
template <typename PlatformType>
struct ToNative<std::shared_ptr<::yandex::maps::mapkit::carparks_detector::MyCarStateListener>, PlatformType> {
    static std::shared_ptr<::yandex::maps::mapkit::carparks_detector::MyCarStateListener> from(
        PlatformType platformMyCarStateListener)
    {
        return ToNative<std::shared_ptr<::yandex::maps::mapkit::carparks_detector::MyCarStateListener>, id<YMKMyCarStateListener>>::from(
            platformMyCarStateListener);
    }
};

template <>
struct ToPlatform<std::shared_ptr<::yandex::maps::mapkit::carparks_detector::MyCarStateListener>> {
    static id<YMKMyCarStateListener> from(
        const std::shared_ptr<::yandex::maps::mapkit::carparks_detector::MyCarStateListener>& nativeMyCarStateListener);
};

} // namespace internal
} // namespace ios
} // namespace bindings
} // namespace runtime
} // namespace maps
} // namespace yandex
