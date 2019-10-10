#import <YandexMapKit/YMKLocationDelegate.h>
#import <YandexMapKit/YMKLocationLocationManager.h>

#import <YandexRuntime/YRTPlatformBinding.h>

/**
 * Handles location updates and changes.
 */
@interface YMKLocationManager : YRTPlatformBinding

/**
 * Subscribe for location update events. If listener was already
 * subscribed for updates from the LocationManager, subscription
 * settings will be updated. Use desiredAccuracy = 0 to obtain best
 * possible accuracy, minTime = 0 to ignore minTime and use minDistance
 * instead, minDistance = 0 to use only minTime. If both minTime and
 * minDistance are set to zero, subscription will use the same settings
 * as other LocationManager clients.
 *
 * @param desiredAccuracy Desired location accuracy, in meters. This
 * value is used to configure location services provided by host os. If
 * locations with desired accuracy are not available, updates may be
 * called with lower accuracy.
 * @param minTime Minimal time interval between events, in milliseconds.
 * @param minDistance Minimal distance between location updates, in
 * meters.
 * @param allowUseInBackground Defines if subscription can continue to
 * fetch notifications when the application is inactive. If
 * allowUseInBackground is true, set the `location` flag in
 * `UIBackgroundModes` for your application.
 * @param filteringMode Defines if locations should be filtered or not.
 * @param locationListener Location update listener.
 */
- (void)subscribeForLocationUpdatesWithDesiredAccuracy:(double)desiredAccuracy
                                               minTime:(long long)minTime
                                           minDistance:(double)minDistance
                                  allowUseInBackground:(BOOL)allowUseInBackground
                                         filteringMode:(YMKLocationFilteringMode)filteringMode
                                      locationListener:(nonnull id<YMKLocationDelegate>)locationListener;


/**
 * Subscribe for a single location update. If the listener was already
 * subscribed for location updates, previous subscription will be
 * removed.
 *
 * @param locationListener Location update listener.
 */
- (void)requestSingleUpdateWithLocationListener:(nonnull id<YMKLocationDelegate>)locationListener;


/**
 * Unsubscribe from location update events. Can be called for either
 * subscribeForLocationUpdates() or requestSingleUpdate(). In case of
 * requestSingleUpdate(), if event was already received, unsubscribe()
 * does not have any effect. If the listener is already unsubscribed,
 * method call is ignored.
 *
 * @param locationListener Listener passed to either
 * subscribeForLocationUpdates() or requestSingleUpdate().
 */
- (void)unsubscribeWithLocationListener:(nonnull id<YMKLocationDelegate>)locationListener;


/**
 * Stops updates for all subscriptions until resume() is called.
 */
- (void)suspend;


/**
 * Resumes updates stopped by call to the suspend() method.
 */
- (void)resume;


@end

