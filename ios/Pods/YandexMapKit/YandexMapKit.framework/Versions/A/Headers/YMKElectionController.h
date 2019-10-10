#import <Foundation/Foundation.h>

@class YMKElectionResultListener;

/// @cond EXCLUDE
@protocol YMKElectionController <NSObject>

/**
 * Set a listener after the election.
 */
- (void)setElectionResultListenerWithElectionResultListener:(nonnull YMKElectionResultListener *)electionResultListener;


/**
 * Mark this app as an election candidate.
 */
- (void)enable;


/**
 * Mark this app as a follower.
 */
- (void)disable;


@end
/// @endcond
