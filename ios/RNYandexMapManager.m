//
//  RNTMapManager.m
//  ReactNativeYMMap
//
//  Created by Дима on 11.09.2018.
//  Copyright © 2018 Facebook. All rights reserved.
//

#import <React/RCTViewManager.h>
#import <YandexMapKit/YMKMapKitFactory.h>
#import "RNYandexMapView.h" 
#import "RCTConvert+YMK.h"

@interface RNYandexMapViewManager: RCTViewManager
@end;

@implementation RNYandexMapViewManager

RCT_EXPORT_MODULE()

RCT_EXPORT_VIEW_PROPERTY(onMapEvent, RCTBubblingEventBlock);

RCT_CUSTOM_VIEW_PROPERTY(location, CLLocationCoordinate2D, RNYandexMap)
{
  YMKCameraPosition *position = view.mapWindow.map.cameraPosition;
  CLLocationCoordinate2D location = [RCTConvert CLLocationCoordinate2D:json];
  YMKPoint *target = [YMKPoint pointWithLatitude:location.latitude longitude:location.longitude];
  [view.mapWindow.map moveWithCameraPosition:[YMKCameraPosition cameraPositionWithTarget:target
      zoom:position.zoom
      azimuth:position.azimuth
      tilt:position.tilt]
   ];
}

RCT_EXPORT_METHOD(animateToCoordinate:(CLLocationCoordinate2D *) location)
{
  if (location == nil) {
    NSLog(@"Location null");
  } else {
    NSLog(@"Location is not null");
  }
  
}

- (UIView *) view
{
  RNYandexMap *map = [RNYandexMap new];
  return map;
}

@end
