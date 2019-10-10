#import <YandexMapKit/YMKMapIndoorLevel.h>

#import <yandex/maps/mapkit/map/indoor_building.h>
#import <yandex/maps/runtime/bindings/ios/to_native.h>
#import <yandex/maps/runtime/bindings/ios/to_platform.h>

namespace yandex {
namespace maps {
namespace runtime {
namespace bindings {
namespace ios {
namespace internal {

template <>
struct ToNative<::yandex::maps::mapkit::map::IndoorLevel, YMKMapIndoorLevel, void> {
    static ::yandex::maps::mapkit::map::IndoorLevel from(
        YMKMapIndoorLevel* platformIndoorLevel);
};

template <typename PlatformType>
struct ToNative<::yandex::maps::mapkit::map::IndoorLevel, PlatformType,
        typename std::enable_if<
            std::is_convertible<PlatformType, YMKMapIndoorLevel*>::value>::type> {
    static ::yandex::maps::mapkit::map::IndoorLevel from(
        PlatformType platformIndoorLevel)
    {
        return ToNative<::yandex::maps::mapkit::map::IndoorLevel, YMKMapIndoorLevel>::from(
            platformIndoorLevel);
    }
};

template <>
struct ToPlatform<::yandex::maps::mapkit::map::IndoorLevel> {
    static YMKMapIndoorLevel* from(
        const ::yandex::maps::mapkit::map::IndoorLevel& indoorLevel);
};

} // namespace internal
} // namespace ios
} // namespace bindings
} // namespace runtime
} // namespace maps
} // namespace yandex
