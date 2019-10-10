#import <YandexMapKit/YMKCarStateListener.h>

#import <yandex/maps/mapkit/carparks_detector/internal/carparks_detector_interface.h>

#import <memory>

@interface YMKCarStateListener ()

- (id)initWithWrappedNative:(NSValue *)native;
- (id)initWithNative:(const std::shared_ptr<::yandex::maps::mapkit::carparks_detector::internal::CarStateListener>&)native;

- (std::shared_ptr<::yandex::maps::mapkit::carparks_detector::internal::CarStateListener>)nativeCarStateListener;
- (std::shared_ptr<::yandex::maps::mapkit::carparks_detector::internal::CarStateListener>)native;

@end
