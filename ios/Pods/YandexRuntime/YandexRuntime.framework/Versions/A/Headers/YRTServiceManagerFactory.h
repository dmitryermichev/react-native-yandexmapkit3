#import <YandexRuntime/YRTPlatformBinding.h>

@class YRTServiceManager;

@interface YRTServiceManagerFactory : YRTPlatformBinding

/// @cond EXCLUDE
+ (nonnull YRTServiceManager *)getServiceManager;
/// @endcond


@end
