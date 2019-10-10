#import <YandexMapKit/YMKMyCarState.h>

#import <YandexRuntime/YRTPlatformBinding.h>

/// @cond EXCLUDE
@interface YMKCarStateListener : YRTPlatformBinding

/**
 * This method is called when a new car state is detected.
 */
- (void)onCarStateChangedWithState:(nonnull YMKMyCarState *)state;


/**
 * Tells if this object is valid or no. Any method called on an invalid
 * object will throw an exception. The object becomes invalid only on UI
 * thread, and only when its implementation depends on objects already
 * destroyed by now. Please refer to general docs about the interface for
 * details on its invalidation.
 */
@property (nonatomic, readonly, getter=isValid) BOOL valid;

@end
/// @endcond

