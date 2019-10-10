#import <Foundation/Foundation.h>

@interface YMKMapIndoorLevel : NSObject

/**
 * Localized display name of the level.
 */
@property (nonatomic, readonly, nonnull) NSString *name;

/**
 * true if level is under ground
 */
@property (nonatomic, readonly) BOOL isUnderground;


+ (nonnull YMKMapIndoorLevel *)indoorLevelWithName:(nonnull NSString *)name
                                     isUnderground:( BOOL)isUnderground;


@end

