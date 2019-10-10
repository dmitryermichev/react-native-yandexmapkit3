#import <YandexMapKit/YMKGeoObject.h>

#import <YandexRuntime/YRTPlatformBinding.h>

typedef void(^YMKGeoObjectSessionGeoObjectHandler)(
    YMKGeoObject *obj,
    NSError *error);

/**
 * The interface for working with the session.
 */
@interface YMKGeoObjectSession : YRTPlatformBinding

/**
 * Cancels the current request.
 */
- (void)cancel;


/**
 * Retries the last request. Cancels the current request if it is
 * active.
 */
- (void)retryWithGeoObjectHandler:(nonnull YMKGeoObjectSessionGeoObjectHandler)geoObjectHandler;


@end

