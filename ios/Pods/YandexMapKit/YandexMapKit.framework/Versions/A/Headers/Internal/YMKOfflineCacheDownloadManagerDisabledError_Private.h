#import <YandexMapKit/YMKOfflineCacheDownloadManagerDisabledError.h>

#import <yandex/maps/mapkit/offline_cache/error.h>

#import <memory>

@interface YMKOfflineCacheDownloadManagerDisabledError ()

- (id)initWithWrappedNative:(NSValue *)native;
- (id)initWithNative:(const std::shared_ptr<::yandex::maps::mapkit::offline_cache::DownloadManagerDisabledError>&)native;

- (std::shared_ptr<::yandex::maps::mapkit::offline_cache::DownloadManagerDisabledError>)nativeDownloadManagerDisabledError;

@end
