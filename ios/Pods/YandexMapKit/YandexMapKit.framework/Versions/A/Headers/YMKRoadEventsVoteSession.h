#import <YandexRuntime/YRTAuthPasswordRequiredError.h>
#import <YandexRuntime/YRTNetworkError.h>
#import <YandexRuntime/YRTNotFoundError.h>
#import <YandexRuntime/YRTPlatformBinding.h>
#import <YandexRuntime/YRTRemoteError.h>

@class YMKRoadEventsRoadEventFailedError;

/// @cond EXCLUDE
typedef void(^YMKRoadEventsVoteSessionResponseHandler)(
    NSError *error);

/**
 * Session for voting for or against events.
 */
@interface YMKRoadEventsVoteSession : YRTPlatformBinding

/**
 * One of the following errors can occur:
 * YMKRoadEventsRoadEventFailedError, YRTNotFoundError, YRTNetworkError,
 * YRTAuthPasswordRequiredError, YRTRemoteError.
 */
- (void)retryWithResponseHandler:(nonnull YMKRoadEventsVoteSessionResponseHandler)responseHandler;


- (void)cancel;


@end
/// @endcond

