#import <YandexRuntime/YRTPlatformBinding.h>

@interface YRTLogger : YRTPlatformBinding

/// @cond EXCLUDE
+ (void)errorWithStr:(nonnull NSString *)str;
/// @endcond


/// @cond EXCLUDE
+ (void)warnWithStr:(nonnull NSString *)str;
/// @endcond


/// @cond EXCLUDE
+ (void)infoWithStr:(nonnull NSString *)str;
/// @endcond


/// @cond EXCLUDE
+ (void)debugWithStr:(nonnull NSString *)str;
/// @endcond


@end
