//
//  RNYandexPlacemark.h
//  mobileapp
//
//  Created by Dev on 14/10/2019.
//  Copyright © 2019 Facebook. All rights reserved.
//


#import <React/RCTComponent.h>
#import <YandexMapKit/YMKMapKitFactory.h>
#import <YandexMapKit/YMKPoint.h>
#import <YandexMapKit/YMKMap.h>
#import <YandexMapKit/YMKPlacemarkMapObject.h>
#import <YandexMapKit/YMKPoint.h>

@interface RNYandexPlacemark: UIView <YMKMapObjectTapListener>
  
  @property (nonatomic, copy) RCTBubblingEventBlock onMapObjectTapEvent;
  
  @property YMKPoint *location;
  @property YMKMap *map;
  @property NSString *image;
  @property NSValue *anchor;
  @property NSNumber *scale;
  
  @property YMKPlacemarkMapObject *placemark;
  
  -(void)addToMap:(YMKMap *)map;
  -(void)removeFromMap;
  
  @end;
