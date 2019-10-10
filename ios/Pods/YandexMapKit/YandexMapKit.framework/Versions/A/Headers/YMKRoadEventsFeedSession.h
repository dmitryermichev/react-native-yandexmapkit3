#import <YandexMapKit/YMKRoadEventsFeed.h>

#import <YandexRuntime/YRTNetworkError.h>
#import <YandexRuntime/YRTNotFoundError.h>
#import <YandexRuntime/YRTPlatformBinding.h>
#import <YandexRuntime/YRTRemoteError.h>

/// @cond EXCLUDE
typedef void(^YMKRoadEventsFeedSessionResponseHandler)(
    YMKRoadEventsFeed *feed,
    NSError *error);

/**
 * Session for requesting the comments feed.
 */
@interface YMKRoadEventsFeedSession : YRTPlatformBinding

- (BOOL)hasNextPage;


/**
 * One of the following errors can occur: YRTNotFoundError,
 * YRTNetworkError, YRTRemoteError.
 */
- (void)fetchNextPageWithResponseHandler:(nonnull YMKRoadEventsFeedSessionResponseHandler)responseHandler;


- (void)cancel;


@end
/// @endcond

