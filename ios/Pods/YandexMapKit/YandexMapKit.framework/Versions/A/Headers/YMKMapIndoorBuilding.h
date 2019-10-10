#import <YandexMapKit/YMKMapIndoorLevel.h>

#import <YandexRuntime/YRTPlatformBinding.h>

@interface YMKMapIndoorBuilding : YRTPlatformBinding

/**
 * List of all levels in indoor building, from bottom to top.
 */
@property (nonatomic, readonly, nonnull) NSArray<YMKMapIndoorLevel *> *levels;

/**
 * Gets/sets active level.
 */
@property (nonatomic) NSInteger activeLevelIndex;

/**
 * Tells if this object is valid or no. Any method called on an invalid
 * object will throw an exception. The object becomes invalid only on UI
 * thread, and only when its implementation depends on objects already
 * destroyed by now. Please refer to general docs about the interface for
 * details on its invalidation.
 */
@property (nonatomic, readonly, getter=isValid) BOOL valid;

@end

