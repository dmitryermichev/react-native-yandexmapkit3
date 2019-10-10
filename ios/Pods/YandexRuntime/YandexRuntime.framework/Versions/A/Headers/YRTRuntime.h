#import <YandexRuntime/YRTPlatformBinding.h>

typedef void(^YRTFailedAssertionListener)(
    NSString *file,
    NSInteger line,
    NSString *condition,
    NSString *message,
    NSArray<NSString *> *stack);

@interface YRTRuntime : YRTPlatformBinding

+ (nonnull NSString *)version;


/// @cond EXCLUDE
+ (void)setFailedAssertionListener:(nonnull YRTFailedAssertionListener)failedAssertionListener;
/// @endcond


@end
