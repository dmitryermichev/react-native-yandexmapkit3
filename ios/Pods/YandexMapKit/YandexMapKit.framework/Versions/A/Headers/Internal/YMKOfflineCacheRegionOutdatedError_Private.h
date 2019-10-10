#import <YandexMapKit/YMKOfflineCacheRegionOutdatedError.h>

#import <yandex/maps/mapkit/offline_cache/error.h>

#import <memory>

@interface YMKOfflineCacheRegionOutdatedError ()

- (id)initWithWrappedNative:(NSValue *)native;
- (id)initWithNative:(const std::shared_ptr<::yandex::maps::mapkit::offline_cache::RegionOutdatedError>&)native;

- (std::shared_ptr<::yandex::maps::mapkit::offline_cache::RegionOutdatedError>)nativeRegionOutdatedError;

@end
