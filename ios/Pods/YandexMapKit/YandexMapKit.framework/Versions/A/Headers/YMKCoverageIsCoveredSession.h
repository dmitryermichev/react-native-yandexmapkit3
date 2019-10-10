#import <YandexRuntime/YRTPlatformBinding.h>

/// @cond EXCLUDE
typedef void(^YMKCoverageIsCoveredSessionResponseHandler)(
    BOOL isCovered,
    NSError *error);

/**
 * Allows to repeat or cancel the request in Coverage.
 */
@interface YMKCoverageIsCoveredSession : YRTPlatformBinding

/**
 * Repeats the specified request with the same parameters.
 */
- (void)retryWithResponseHandler:(nonnull YMKCoverageIsCoveredSessionResponseHandler)responseHandler;


/**
 * Cancels the request.
 */
- (void)cancel;


@end
/// @endcond

