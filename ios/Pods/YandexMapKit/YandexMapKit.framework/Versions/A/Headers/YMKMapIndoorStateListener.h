#import <Foundation/Foundation.h>

@class YMKMapIndoorBuilding;

@protocol YMKMapIndoorStateListener <NSObject>

/**
 * Notifies when user view focuses on a new building or building leaves
 * focus(in this case @building will be null) Might be called after
 * content update. This call is guaranteed to happen before
 * onLevelActivated call. Prior to this call activeLevel will be set to
 * default level or previously selected level.
 *
 * @param activeBuilding is valid until next call
 */
- (void)onActiveBuildingChangedWithActiveBuilding:(nonnull YMKMapIndoorBuilding *)activeBuilding;


@end
