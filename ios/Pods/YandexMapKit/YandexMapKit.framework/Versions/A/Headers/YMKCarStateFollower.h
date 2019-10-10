#import <Foundation/Foundation.h>

@class YMKCarStateListener;

/// @cond EXCLUDE
@protocol YMKCarStateFollower <NSObject>

/**
 * Set a listener for car state updates.
 */
- (void)subscribeWithCarStateListener:(nonnull YMKCarStateListener *)carStateListener;


/**
 * Disable the listener for car state updates.
 */
- (void)unsubscribeWithCarStateListener:(nonnull YMKCarStateListener *)carStateListener;


@end
/// @endcond
