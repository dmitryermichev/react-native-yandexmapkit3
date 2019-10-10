#import <YandexMapKit/YMKGeoObject.h>

#import <YandexRuntime/YRTNotFoundError.h>
#import <YandexRuntime/YRTPlatformBinding.h>
#import <YandexRuntime/YRTRemoteError.h>

/// @cond EXCLUDE
typedef void(^YMKRoadEventsEventInfoSessionResponseHandler)(
    YMKGeoObject *event,
    NSError *error);

/**
 * Session for requesting road event info.
 */
@interface YMKRoadEventsEventInfoSession : YRTPlatformBinding

/**
 * One of the following errors can happen: YRTNotFoundError,
 * {@runtime.network.NetworkError}, YRTRemoteError.
 */
- (void)retryWithResponseHandler:(nonnull YMKRoadEventsEventInfoSessionResponseHandler)responseHandler;


- (void)cancel;


@end
/// @endcond

