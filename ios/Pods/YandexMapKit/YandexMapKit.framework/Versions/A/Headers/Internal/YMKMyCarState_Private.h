#import <YandexMapKit/YMKMyCarState.h>

#import <yandex/maps/mapkit/carparks_detector/my_car_state.h>
#import <yandex/maps/runtime/bindings/ios/to_native.h>
#import <yandex/maps/runtime/bindings/ios/to_platform.h>

namespace yandex {
namespace maps {
namespace runtime {
namespace bindings {
namespace ios {
namespace internal {

template <>
struct ToNative<::yandex::maps::mapkit::carparks_detector::MyCarState, YMKMyCarState, void> {
    static ::yandex::maps::mapkit::carparks_detector::MyCarState from(
        YMKMyCarState* platformMyCarState);
};

template <typename PlatformType>
struct ToNative<::yandex::maps::mapkit::carparks_detector::MyCarState, PlatformType,
        typename std::enable_if<
            std::is_convertible<PlatformType, YMKMyCarState*>::value>::type> {
    static ::yandex::maps::mapkit::carparks_detector::MyCarState from(
        PlatformType platformMyCarState)
    {
        return ToNative<::yandex::maps::mapkit::carparks_detector::MyCarState, YMKMyCarState>::from(
            platformMyCarState);
    }
};

template <>
struct ToPlatform<::yandex::maps::mapkit::carparks_detector::MyCarState> {
    static YMKMyCarState* from(
        const ::yandex::maps::mapkit::carparks_detector::MyCarState& myCarState);
};

} // namespace internal
} // namespace ios
} // namespace bindings
} // namespace runtime
} // namespace maps
} // namespace yandex
