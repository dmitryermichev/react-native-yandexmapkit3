#import <YandexMapKit/YMKMyCarStateManager.h>

#import <YandexRuntime/YRTSubscription.h>

#import <yandex/maps/mapkit/carparks_detector/my_car_state_manager.h>
#import <yandex/maps/runtime/ios/object.h>

#import <memory>

@interface YMKMyCarStateManager ()

- (id)initWithWrappedNative:(NSValue *)native;
- (id)initWithNative:(const std::shared_ptr<::yandex::maps::mapkit::carparks_detector::MyCarStateManager>&)native;

- (std::shared_ptr<::yandex::maps::mapkit::carparks_detector::MyCarStateManager>)nativeMyCarStateManager;
- (std::shared_ptr<::yandex::maps::mapkit::carparks_detector::MyCarStateManager>)native;

@end
