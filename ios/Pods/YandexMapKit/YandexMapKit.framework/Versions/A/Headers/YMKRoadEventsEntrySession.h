#import <YandexMapKit/YMKRoadEventsEntry.h>

#import <YandexRuntime/YRTAuthPasswordRequiredError.h>
#import <YandexRuntime/YRTNetworkError.h>
#import <YandexRuntime/YRTNotFoundError.h>
#import <YandexRuntime/YRTPlatformBinding.h>
#import <YandexRuntime/YRTRemoteError.h>

@class YMKRoadEventsRoadEventFailedError;

/// @cond EXCLUDE
typedef void(^YMKRoadEventsEntrySessionResponseHandler)(
    YMKRoadEventsEntry *entry,
    NSError *error);

/**
 * Session for adding comments.
 */
@interface YMKRoadEventsEntrySession : YRTPlatformBinding

/**
 * One of the following errors can occur:
 * YMKRoadEventsRoadEventFailedError, YRTNotFoundError, YRTNetworkError,
 * YRTAuthPasswordRequiredError, YRTRemoteError.
 */
- (void)retryWithResponseHandler:(nonnull YMKRoadEventsEntrySessionResponseHandler)responseHandler;


- (void)cancel;


@end
/// @endcond

