#import <Foundation/Foundation.h>

/// @cond EXCLUDE
typedef NS_ENUM(NSUInteger, YRTActivityType) {

    /**
     * Unrecognized activity
     */
    YRTActivityTypeUnknown,

    /**
     * The device is not moving
     */
    YRTActivityTypeStill,

    /**
     * The device is on a user who is walking This is a sub-activity of
     * ON_FOOT
     */
    YRTActivityTypeWalking,

    /**
     * The device is on a user who is running This is a sub-activity of
     * ON_FOOT
     */
    YRTActivityTypeRunning,

    /**
     * The device is in a vehicle, such as a car or bus
     */
    YRTActivityTypeInVehicle,

    /**
     * The device is on a bicycle
     */
    YRTActivityTypeOnBicycle,

    /**
     * The device angle relative to gravity changed significantly Set on
     * android platform only
     */
    YRTActivityTypeTilting,

    /**
     * The device is on a user who is walking or running
     */
    YRTActivityTypeOnFoot
};
/// @endcond


/// @cond EXCLUDE
@interface YRTActivityRecord : NSObject

@property (nonatomic, readonly) YRTActivityType type;

/**
 * Describes how confident the reporter is that the event occured.
 * Range: [0, 1]; 1 - means absolutely confident
 */
@property (nonatomic, readonly) float confidence;

@property (nonatomic, readonly, nonnull) NSDate *time;


+ (nonnull YRTActivityRecord *)activityRecordWithType:( YRTActivityType)type
                                           confidence:( float)confidence
                                                 time:(nonnull NSDate *)time;


@end
/// @endcond

