#import <YandexMapKit/YMKCoverageRegion.h>

#import <YandexRuntime/YRTPlatformBinding.h>

/// @cond EXCLUDE
typedef void(^YMKCoverageRegionsSessionResponseHandler)(
    NSArray<YMKCoverageRegion *> *regions,
    NSError *error);

/**
 * Allows to repeat or cancel the request for a list of regions.
 */
@interface YMKCoverageRegionsSession : YRTPlatformBinding

/**
 * Repeats the specified request with the same parameters.
 */
- (void)retryWithResponseHandler:(nonnull YMKCoverageRegionsSessionResponseHandler)responseHandler;


/**
 * Cancels the request.
 */
- (void)cancel;


@end
/// @endcond

