#import <YandexRuntime/YRTPlatformBinding.h>

@class YMKLocationManager;
@class YMKLocationViewSource;

@interface YMKLocationViewSourceFactory : YRTPlatformBinding

/**
 * Location view source.
 */
+ (nonnull YMKLocationViewSource *)createLocationViewSourceWithLocationManager:(nonnull YMKLocationManager *)locationManager;


@end
