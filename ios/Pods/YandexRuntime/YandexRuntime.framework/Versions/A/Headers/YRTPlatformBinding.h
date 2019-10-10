#pragma once

#import <Foundation/Foundation.h>

@protocol YRTDeinitializableObject

- (void)deinitialize;

@end

@interface YRTPlatformBinding: NSObject<YRTDeinitializableObject>
@end
