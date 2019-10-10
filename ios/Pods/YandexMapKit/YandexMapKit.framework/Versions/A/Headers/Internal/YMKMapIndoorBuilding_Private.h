#import <YandexMapKit/YMKMapIndoorBuilding.h>

#import <yandex/maps/mapkit/map/indoor_building.h>

#import <memory>

@interface YMKMapIndoorBuilding ()

- (id)initWithWrappedNative:(NSValue *)native;
- (id)initWithNative:(const std::shared_ptr<::yandex::maps::mapkit::map::IndoorBuilding>&)native;

- (std::shared_ptr<::yandex::maps::mapkit::map::IndoorBuilding>)nativeIndoorBuilding;
- (std::shared_ptr<::yandex::maps::mapkit::map::IndoorBuilding>)native;

@end
