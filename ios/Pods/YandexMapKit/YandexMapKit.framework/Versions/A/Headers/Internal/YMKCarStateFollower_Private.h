#import <YandexMapKit/YMKCarStateFollower.h>

#import <yandex/maps/mapkit/carparks_detector/internal/carparks_detector_interface.h>
#import <yandex/maps/runtime/bindings/ios/to_native.h>
#import <yandex/maps/runtime/bindings/ios/to_platform.h>

namespace yandex {
namespace maps {
namespace mapkit {
namespace carparks_detector {
namespace internal {
namespace ios {

class CarStateFollowerBinding : public ::yandex::maps::mapkit::carparks_detector::internal::CarStateFollower {
public:
    explicit CarStateFollowerBinding(
        id<YMKCarStateFollower> platformListener);

    virtual void subscribe(
        ::yandex::maps::mapkit::carparks_detector::internal::CarStateListener* carStateListener) override;

    virtual void unsubscribe(
        ::yandex::maps::mapkit::carparks_detector::internal::CarStateListener* carStateListener) override;

    id<YMKCarStateFollower> platformReference() const { return platformListener_; }

private:
    id<YMKCarStateFollower> platformListener_;
};

} // namespace ios
} // namespace internal
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
struct ToNative<std::shared_ptr<::yandex::maps::mapkit::carparks_detector::internal::CarStateFollower>, id<YMKCarStateFollower>, void> {
    static std::shared_ptr<::yandex::maps::mapkit::carparks_detector::internal::CarStateFollower> from(
        id<YMKCarStateFollower> platformCarStateFollower);
};
template <typename PlatformType>
struct ToNative<std::shared_ptr<::yandex::maps::mapkit::carparks_detector::internal::CarStateFollower>, PlatformType> {
    static std::shared_ptr<::yandex::maps::mapkit::carparks_detector::internal::CarStateFollower> from(
        PlatformType platformCarStateFollower)
    {
        return ToNative<std::shared_ptr<::yandex::maps::mapkit::carparks_detector::internal::CarStateFollower>, id<YMKCarStateFollower>>::from(
            platformCarStateFollower);
    }
};

template <>
struct ToPlatform<std::shared_ptr<::yandex::maps::mapkit::carparks_detector::internal::CarStateFollower>> {
    static id<YMKCarStateFollower> from(
        const std::shared_ptr<::yandex::maps::mapkit::carparks_detector::internal::CarStateFollower>& nativeCarStateFollower);
};

} // namespace internal
} // namespace ios
} // namespace bindings
} // namespace runtime
} // namespace maps
} // namespace yandex
