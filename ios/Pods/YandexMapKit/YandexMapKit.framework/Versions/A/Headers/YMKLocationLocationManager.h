#import <Foundation/Foundation.h>

typedef NS_ENUM(NSUInteger, YMKLocationFilteringMode) {

    /**
     * Locations should be filtered (no unrealistic, spoofed locations,
     * locations from the past)
     */
    YMKLocationFilteringModeOn,

    /**
     * Only invalid (i.e. zero) locations should be filtered
     */
    YMKLocationFilteringModeOff
};

