#import <YandexMapKit/YMKMyCarState.h>

/// @cond EXCLUDE
@protocol YMKMyCarStateListener <NSObject>

- (void)onMyCarStateUpdateWithState:(nonnull YMKMyCarState *)state;


@end
/// @endcond
