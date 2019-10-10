#import <YandexMapKit/YMKLayer.h>

#import <yandex/maps/mapkit/layers/layer.h>

#import <memory>

@interface YMKLayer ()

- (id)initWithWrappedNative:(NSValue *)native;
- (id)initWithNative:(const std::shared_ptr<::yandex::maps::mapkit::layers::Layer>&)native;

- (std::shared_ptr<::yandex::maps::mapkit::layers::Layer>)nativeLayer;
- (std::shared_ptr<::yandex::maps::mapkit::layers::Layer>)native;

@end
