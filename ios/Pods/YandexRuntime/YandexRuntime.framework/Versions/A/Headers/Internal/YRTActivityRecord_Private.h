#import <YandexRuntime/YRTActivityRecord.h>

#import <yandex/maps/runtime/bindings/ios/to_native.h>
#import <yandex/maps/runtime/bindings/ios/to_platform.h>
#import <yandex/maps/runtime/sensors/activity_record.h>

namespace yandex {
namespace maps {
namespace runtime {
namespace bindings {
namespace ios {
namespace internal {

template <>
struct ToNative<::yandex::maps::runtime::sensors::ActivityRecord, YRTActivityRecord, void> {
    static ::yandex::maps::runtime::sensors::ActivityRecord from(
        YRTActivityRecord* platformActivityRecord);
};

template <typename PlatformType>
struct ToNative<::yandex::maps::runtime::sensors::ActivityRecord, PlatformType,
        typename std::enable_if<
            std::is_convertible<PlatformType, YRTActivityRecord*>::value>::type> {
    static ::yandex::maps::runtime::sensors::ActivityRecord from(
        PlatformType platformActivityRecord)
    {
        return ToNative<::yandex::maps::runtime::sensors::ActivityRecord, YRTActivityRecord>::from(
            platformActivityRecord);
    }
};

template <>
struct ToPlatform<::yandex::maps::runtime::sensors::ActivityRecord> {
    static YRTActivityRecord* from(
        const ::yandex::maps::runtime::sensors::ActivityRecord& activityRecord);
};

} // namespace internal
} // namespace ios
} // namespace bindings
} // namespace runtime
} // namespace maps
} // namespace yandex
