#import <YandexMapKit/YMKCameraPosition.h>
#import <YandexMapKit/YMKLocationViewSource.h>
#import <YandexMapKit/YMKUserLocationObjectListener.h>
#import <YandexMapKit/YMKUserLocationTapListener.h>

#import <YandexRuntime/YRTPlatformBinding.h>

#import <UIKit/UIKit.h>

/**
 * Use the UserLocationLayer interface to manage the location icon: its
 * appearance, following mode, data source and so on.
 */
@interface YMKUserLocationLayer : YRTPlatformBinding

/**
 * Enables/disables layer functionality.
 */
@property (nonatomic, getter=isEnabled) BOOL enabled;

/**
 * Enables/disables heading mode. If heading mode is enabled, the map is
 * rotated. If heading mode is disabled, the location icon is rotated.
 */
@property (nonatomic, getter=isHeadingEnabled) BOOL headingEnabled;

/**
 * Sets the anchor to the specified position in pixels and enables
 * Anchor mode. (0, 0) denotes the top-left corner of the screen.
 *
 * @param anchorNormal The anchor position when the app is not on a
 * steady course; usually, the center of the screen.
 * @param anchorCourse An anchor position near the bottom line for
 * steady course mode.
 */
- (void)setAnchorWithAnchorNormal:(CGPoint)anchorNormal
                     anchorCourse:(CGPoint)anchorCourse;


/**
 * Resets anchor mode.
 */
- (void)resetAnchor;


/**
 * Returns true if anchor mode is set, and false otherwise.
 */
@property (nonatomic, readonly, getter=isAnchorEnabled) BOOL anchorEnabled;

/**
 * Enables/disables auto zoom.
 */
@property (nonatomic, getter=isAutoZoomEnabled) BOOL autoZoomEnabled;

/**
 * Calculates the camera position that projects the current location
 * into view. If the current location is unknown, returns none. If the
 * current location is known, returns the camera position that displays
 * the location position.
 */
- (nullable YMKCameraPosition *)cameraPosition;


/**
 * Sets/gets the data source.
 */
- (void)setSourceWithSource:(nonnull YMKLocationViewSource *)source;


/**
 * Sets/resets the tap listener.
 */
- (void)setTapListenerWithTapListener:(nonnull id<YMKUserLocationTapListener>)tapListener;


/**
 * Sets/resets the object listener.
 */
- (void)setObjectListenerWithObjectListener:(nonnull id<YMKUserLocationObjectListener>)objectListener;


/**
 * Tells if this object is valid or no. Any method called on an invalid
 * object will throw an exception. The object becomes invalid only on UI
 * thread, and only when its implementation depends on objects already
 * destroyed by now. Please refer to general docs about the interface for
 * details on its invalidation.
 */
@property (nonatomic, readonly, getter=isValid) BOOL valid;

@end

