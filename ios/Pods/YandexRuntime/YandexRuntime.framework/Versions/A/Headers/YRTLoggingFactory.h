#import <YandexRuntime/YRTPlatformBinding.h>

@class YRTLogging;

@interface YRTLoggingFactory : YRTPlatformBinding

/// @cond EXCLUDE
+ (nonnull YRTLogging *)getLogging;
/// @endcond


@end
