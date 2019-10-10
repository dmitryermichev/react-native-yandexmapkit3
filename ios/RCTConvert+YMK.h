//
//  RCTConvert+YMK.h
//  ReactNativeYMMap
//
//  Created by Дима on 12.09.2018.
//  Copyright © 2018 Facebook. All rights reserved.
//
 
#import <React/RCTConvert.h>
#import <CoreLocation/CoreLocation.h>
#import <React/RCTConvert+CoreLocation.h>

@interface RCTConvert (YMK)

+ (CLLocationCoordinate2D)CLLocationCoordinate2D:(id)json;

@end
