#pragma once

#import <YandexRuntime/YRTPlatformBinding.h>

@interface YRTObjectRegistry: NSObject

+ (void)initialize;

+ (void)registerObject:(id<YRTDeinitializableObject>)object;

+ (void)unregisterObject:(id<YRTDeinitializableObject>)object;

+ (void)deinitialize;

@end

