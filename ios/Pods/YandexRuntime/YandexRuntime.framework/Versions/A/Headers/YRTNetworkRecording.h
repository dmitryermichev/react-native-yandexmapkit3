#import <YandexRuntime/YRTPlatformBinding.h>

@class YRTNetworkPlayer;
@class YRTNetworkRecorder;

typedef void(^YRTFileOperationsListener)(
    NSError *error);

@interface YRTNetworkRecording : YRTPlatformBinding

/// @cond EXCLUDE
+ (nullable YRTNetworkRecorder *)createRecorder;
/// @endcond


/// @cond EXCLUDE
+ (nullable YRTNetworkPlayer *)createPlayer;
/// @endcond


@end
