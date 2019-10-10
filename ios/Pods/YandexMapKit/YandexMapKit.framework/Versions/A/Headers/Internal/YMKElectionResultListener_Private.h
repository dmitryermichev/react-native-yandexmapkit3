#import <YandexMapKit/YMKElectionResultListener.h>

#import <yandex/maps/mapkit/internal/election_controller.h>

#import <memory>

@interface YMKElectionResultListener ()

- (id)initWithWrappedNative:(NSValue *)native;
- (id)initWithNative:(const std::shared_ptr<::yandex::maps::mapkit::internal::ElectionResultListener>&)native;

- (std::shared_ptr<::yandex::maps::mapkit::internal::ElectionResultListener>)nativeElectionResultListener;
- (std::shared_ptr<::yandex::maps::mapkit::internal::ElectionResultListener>)native;

@end
