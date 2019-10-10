#import <YandexMapKit/YMKMyCarState.h>

/// @cond EXCLUDE
@protocol YMKCarStatePublisher <NSObject>

/**
 * Send the new car state to followers.
 */
- (void)broadcastCarStateWithState:(nonnull YMKMyCarState *)state;


/**
 * Enable the current car state request handler.
 */
- (void)enable;


/**
 * Disable the current car state request handler.
 */
- (void)disable;


@end
/// @endcond
