#import <YandexMapKit/YMKPoint.h>

/// @cond EXCLUDE
typedef NS_ENUM(NSUInteger, YMKMyCarStateType) {

    YMKMyCarStateTypeParked,

    YMKMyCarStateTypeUnparked,

    YMKMyCarStateTypeUnknown
};
/// @endcond


/// @cond EXCLUDE
@interface YMKMyCarState : NSObject

@property (nonatomic, readonly) YMKMyCarStateType state;

/**
 * Optional property, can be null.
 */
@property (nonatomic, readonly, nullable) YMKPoint *location;


+ (nonnull YMKMyCarState *)myCarStateWithState:( YMKMyCarStateType)state
                                      location:(nullable YMKPoint *)location;


@end
/// @endcond

