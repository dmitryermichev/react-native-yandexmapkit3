#import <YandexMapKit/YMKCarStatePublisher.h>

#import <yandex/maps/mapkit/carparks_detector/internal/carparks_detector_interface.h>
#import <yandex/maps/runtime/bindings/ios/to_native.h>
#import <yandex/maps/runtime/bindings/ios/to_platform.h>

namespace yandex {
namespace maps {
namespace mapkit {
namespace carparks_detector {
namespace internal {
namespace ios {

class CarStatePublisherBinding : public ::yandex::maps::mapkit::carparks_detector::internal::CarStatePublisher {
public:
    explicit CarStatePublisherBinding(
        id<YMKCarStatePublisher> platformListener);

    virtual void broadcastCarState(
        const ::yandex::maps::mapkit::carparks_detector::MyCarState& state) override;

    virtual void enable() override;

    virtual void disable() override;

    id<YMKCarStatePublisher> platformReference() const { return platformListener_; }

private:
    id<YMKCarStatePublisher> platformListener_;
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
struct ToNative<std::shared_ptr<::yandex::maps::mapkit::carparks_detector::internal::CarStatePublisher>, id<YMKCarStatePublisher>, void> {
    static std::shared_ptr<::yandex::maps::mapkit::carparks_detector::internal::CarStatePublisher> from(
        id<YMKCarStatePublisher> platformCarStatePublisher);
};
template <typename PlatformType>
struct ToNative<std::shared_ptr<::yandex::maps::mapkit::carparks_detector::internal::CarStatePublisher>, PlatformType> {
    static std::shared_ptr<::yandex::maps::mapkit::carparks_detector::internal::CarStatePublisher> from(
        PlatformType platformCarStatePublisher)
    {
        return ToNative<std::shared_ptr<::yandex::maps::mapkit::carparks_detector::internal::CarStatePublisher>, id<YMKCarStatePublisher>>::from(
            platformCarStatePublisher);
    }
};

template <>
struct ToPlatform<std::shared_ptr<::yandex::maps::mapkit::carparks_detector::internal::CarStatePublisher>> {
    static id<YMKCarStatePublisher> from(
        const std::shared_ptr<::yandex::maps::mapkit::carparks_detector::internal::CarStatePublisher>& nativeCarStatePublisher);
};

} // namespace internal
} // namespace ios
} // namespace bindings
} // namespace runtime
} // namespace maps
} // namespace yandex
