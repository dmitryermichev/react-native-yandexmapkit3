#import <YandexMapKit/YMKAnimatedIcon.h>

#import <yandex/maps/mapkit/map/animated_icon.h>

#import <memory>

@interface YMKAnimatedIcon ()

- (id)initWithWrappedNative:(NSValue *)native;
- (id)initWithNative:(const std::shared_ptr<::yandex::maps::mapkit::map::AnimatedIcon>&)native;

- (std::shared_ptr<::yandex::maps::mapkit::map::AnimatedIcon>)nativeAnimatedIcon;
- (std::shared_ptr<::yandex::maps::mapkit::map::AnimatedIcon>)native;

@end
