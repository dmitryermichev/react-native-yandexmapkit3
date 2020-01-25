//
//  RNYandexPlacemarkManager.m
//  mobileapp
//
//  Created by Dev on 14/10/2019.
//  Copyright © 2019 Facebook. All rights reserved.
//

#import <Foundation/Foundation.h>

#import <React/RCTViewManager.h>
#import "RNYandexPlacemark.h"
#import <React/RCTConvert.h>

@interface RNYandexPlacemarkManager : RCTViewManager
  @end

@implementation RNYandexPlacemarkManager
  
RCT_EXPORT_MODULE(RNYandexPlacemark)
  
RCT_EXPORT_VIEW_PROPERTY(onMapObjectTapEvent, RCTBubblingEventBlock);
  
RCT_CUSTOM_VIEW_PROPERTY(location, NSDictionary, RNYandexPlacemark)
  {
    double latitude = [RCTConvert double:json[@"latitude"]];
    double longitude = [RCTConvert double:json[@"longitude"]];
    view.location = [YMKPoint pointWithLatitude:latitude longitude:longitude];
  }
  
RCT_CUSTOM_VIEW_PROPERTY(anchor, NSDictionary, RNYandexPlacemark)
  {
    double x = [RCTConvert double:json[@"x"]];
    double y = [RCTConvert double:json[@"y"]];
    
    CGPoint anchor;
    anchor.x = x;
    anchor.y = y;
    view.anchor = [NSValue valueWithBytes:&anchor objCType:@encode(CGPoint)];
  }

  RCT_CUSTOM_VIEW_PROPERTY(scale, NSNumber, RNYandexPlacemark)
  {
    view.scale = [RCTConvert NSNumber:json];
    YMKIconStyle *is = [YMKIconStyle iconStyleWithAnchor:[view anchor] rotationType:nil zIndex:nil flat:nil visible:nil scale:view.scale tappableArea:nil];
    [view.placemark setIconStyleWithStyle:is];
  }
  
RCT_EXPORT_VIEW_PROPERTY(image, NSString)

  
- (UIView *)view
  {
    return [[RNYandexPlacemark alloc] init];
  }
  
  @end
