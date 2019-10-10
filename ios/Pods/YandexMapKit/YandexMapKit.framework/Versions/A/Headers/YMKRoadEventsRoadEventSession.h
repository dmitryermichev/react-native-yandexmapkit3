#import <YandexMapKit/YMKGeoObject.h>

#import <YandexRuntime/YRTAuthPasswordRequiredError.h>
#import <YandexRuntime/YRTNetworkError.h>
#import <YandexRuntime/YRTPlatformBinding.h>
#import <YandexRuntime/YRTRemoteError.h>

@class YMKRoadEventsRoadEventFailedError;

/// @cond EXCLUDE
typedef void(^YMKRoadEventsRoadEventSessionResponseHandler)(
    YMKGeoObject *event,
    NSError *error);

/**
 * Road event creation session.
 */
@interface YMKRoadEventsRoadEventSession : YRTPlatformBinding

/**
 * One of the following errors can happen:
 * YMKRoadEventsRoadEventFailedError, YRTNetworkError,
 * YRTAuthPasswordRequiredError, YRTRemoteError.
 */
- (void)retryWithResponseHandler:(nonnull YMKRoadEventsRoadEventSessionResponseHandler)responseHandler;


- (void)cancel;


@end
/// @endcond

