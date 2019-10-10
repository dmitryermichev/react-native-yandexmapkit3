#import <YandexRuntime/YRTPlatformBinding.h>

@class YRTEventLogging;

@interface YRTEventLoggingFactory : YRTPlatformBinding

/// @cond EXCLUDE
+ (nonnull YRTEventLogging *)getEventLogging;
/// @endcond


@end
