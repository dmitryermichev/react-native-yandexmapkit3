//
//  RNYandexPlacemark.m
//  ReactNativeYandexmapkit3
//
//  Created by Dev on 10/10/2019.
//  Copyright © 2019 Facebook. All rights reserved.
//

#import <Foundation/Foundation.h>

#import "React/RCTViewManager.h"

@interface RCT_EXTERN_MODULE(RNYandexPlacemarkManager, RCTViewManager)
RCT_EXPORT_VIEW_PROPERTY(isOn, BOOL)
RCT_EXPORT_VIEW_PROPERTY(onStatusChange, RCTDirectEventBlock)
@end

