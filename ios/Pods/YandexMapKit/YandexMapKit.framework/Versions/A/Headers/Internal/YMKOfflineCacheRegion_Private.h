#import <YandexMapKit/YMKOfflineCacheRegion.h>

#import <YandexRuntime/YRTSubscription.h>

#import <yandex/maps/mapkit/offline_cache/region.h>
#import <yandex/maps/runtime/ios/object.h>

#import <memory>

@interface YMKOfflineCacheRegion ()

- (id)initWithWrappedNative:(NSValue *)native;
- (id)initWithNative:(const std::shared_ptr<::yandex::maps::mapkit::offline_cache::Region>&)native;

- (std::shared_ptr<::yandex::maps::mapkit::offline_cache::Region>)nativeRegion;
- (std::shared_ptr<::yandex::maps::mapkit::offline_cache::Region>)native;

@end
