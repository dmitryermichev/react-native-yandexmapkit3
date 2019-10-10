#import <YandexMapKit/YMKElectionController.h>

#import <yandex/maps/mapkit/internal/election_controller.h>
#import <yandex/maps/runtime/bindings/ios/to_native.h>
#import <yandex/maps/runtime/bindings/ios/to_platform.h>

namespace yandex {
namespace maps {
namespace mapkit {
namespace internal {
namespace ios {

class ElectionControllerBinding : public ::yandex::maps::mapkit::internal::ElectionController {
public:
    explicit ElectionControllerBinding(
        id<YMKElectionController> platformListener);

    virtual void setElectionResultListener(
        ::yandex::maps::mapkit::internal::ElectionResultListener* electionResultListener) override;

    virtual void enable() override;

    virtual void disable() override;

    id<YMKElectionController> platformReference() const { return platformListener_; }

private:
    id<YMKElectionController> platformListener_;
};

} // namespace ios
} // namespace internal
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
struct ToNative<std::shared_ptr<::yandex::maps::mapkit::internal::ElectionController>, id<YMKElectionController>, void> {
    static std::shared_ptr<::yandex::maps::mapkit::internal::ElectionController> from(
        id<YMKElectionController> platformElectionController);
};
template <typename PlatformType>
struct ToNative<std::shared_ptr<::yandex::maps::mapkit::internal::ElectionController>, PlatformType> {
    static std::shared_ptr<::yandex::maps::mapkit::internal::ElectionController> from(
        PlatformType platformElectionController)
    {
        return ToNative<std::shared_ptr<::yandex::maps::mapkit::internal::ElectionController>, id<YMKElectionController>>::from(
            platformElectionController);
    }
};

template <>
struct ToPlatform<std::shared_ptr<::yandex::maps::mapkit::internal::ElectionController>> {
    static id<YMKElectionController> from(
        const std::shared_ptr<::yandex::maps::mapkit::internal::ElectionController>& nativeElectionController);
};

} // namespace internal
} // namespace ios
} // namespace bindings
} // namespace runtime
} // namespace maps
} // namespace yandex
