#import <YandexMapKit/YMKPoint.h>

/**
 * The waypoint and a point the path must go through.
 */
typedef NS_ENUM(NSUInteger, YMKRequestPointType) {

    /**
     * The target waypoint.
     */
    YMKRequestPointTypeWaypoint,

    /**
     * A point the route must pass through.
     */
    YMKRequestPointTypeViapoint
};


/**
 * There are two types of request points. A waypoint is a destination.
 * Use it when you plan to stop there. Via points (throughpoints)
 * correct the route to make it pass through all the via points.
 * Waypoints are guaranteed to be between sections in the resulting
 * route. Via points are embedded into sections.
 *
 * For each waypoint, you can provide a list of arrival points (for
 * example, if the request point is a building, you can provide a list
 * of entrances to that building). If there is at least one arrival
 * point, then the router will choose one of them and use it for
 * routing. The point member will be used only as a suggestion.
 * Otherwise, the point itself will be used for routing.
 */
@interface YMKRequestPoint : NSObject

/**
 * The request point.
 */
@property (nonatomic, readonly, nonnull) YMKPoint *point;

/**
 * Arrival points.
 */
@property (nonatomic, readonly, nonnull) NSArray<YMKPoint *> *arrivalPoints;

/**
 * The type of request point specified.
 */
@property (nonatomic, readonly) YMKRequestPointType type;


+ (nonnull YMKRequestPoint *)requestPointWithPoint:(nonnull YMKPoint *)point
                                     arrivalPoints:(nonnull NSArray<YMKPoint *> *)arrivalPoints
                                              type:( YMKRequestPointType)type;


@end

