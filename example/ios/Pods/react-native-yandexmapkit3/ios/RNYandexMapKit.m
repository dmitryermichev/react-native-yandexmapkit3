//
//  RNYandexMapKit.m
//  ReactNativeYMMap
//
//  Created by Дима on 12.09.2018.
//  Copyright © 2018 Facebook. All rights reserved.
//

#import "RNYandexMapKit.h"
#import <YandexMapKit/YMKMapKitFactory.h>

@implementation RNYandexMapKit

RCT_EXPORT_MODULE()

RCT_EXPORT_METHOD(setApiKey: (nonnull NSString *) apiKey) {
  NSLog(@"set api key called");
  [YMKMapKit setApiKey: apiKey];
}

@end

