#import <YandexMapKit/YMKMapIndoorStateListener.h>

#import <yandex/maps/mapkit/map/indoor_state_listener.h>
#import <yandex/maps/runtime/bindings/ios/to_native.h>
#import <yandex/maps/runtime/bindings/ios/to_platform.h>

namespace yandex {
namespace maps {
namespace mapkit {
namespace map {
namespace ios {

class IndoorStateListenerBinding : public ::yandex::maps::mapkit::map::IndoorStateListener {
public:
    explicit IndoorStateListenerBinding(
        id<YMKMapIndoorStateListener> platformListener);

    virtual void onActiveBuildingChanged(
        ::yandex::maps::mapkit::map::IndoorBuilding* activeBuilding) override;

    id<YMKMapIndoorStateListener> platformReference() const { return platformListener_; }

private:
    __weak id<YMKMapIndoorStateListener> platformListener_;
};

} // namespace ios
} // namespace map
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
struct ToNative<std::shared_ptr<::yandex::maps::mapkit::map::IndoorStateListener>, id<YMKMapIndoorStateListener>, void> {
    static std::shared_ptr<::yandex::maps::mapkit::map::IndoorStateListener> from(
        id<YMKMapIndoorStateListener> platformIndoorStateListener);
};
template <typename PlatformType>
struct ToNative<std::shared_ptr<::yandex::maps::mapkit::map::IndoorStateListener>, PlatformType> {
    static std::shared_ptr<::yandex::maps::mapkit::map::IndoorStateListener> from(
        PlatformType platformIndoorStateListener)
    {
        return ToNative<std::shared_ptr<::yandex::maps::mapkit::map::IndoorStateListener>, id<YMKMapIndoorStateListener>>::from(
            platformIndoorStateListener);
    }
};

template <>
struct ToPlatform<std::shared_ptr<::yandex::maps::mapkit::map::IndoorStateListener>> {
    static id<YMKMapIndoorStateListener> from(
        const std::shared_ptr<::yandex::maps::mapkit::map::IndoorStateListener>& nativeIndoorStateListener);
};

} // namespace internal
} // namespace ios
} // namespace bindings
} // namespace runtime
} // namespace maps
} // namespace yandex
