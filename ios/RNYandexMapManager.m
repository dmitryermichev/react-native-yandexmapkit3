//
//  RNTMapManager.m
//  ReactNativeYMMap
//
//  Created by Дима on 11.09.2018.
//  Copyright © 2018 Facebook. All rights reserved.
//

#import <React/RCTViewManager.h>
#import <YandexMapKit/YMKMapKitFactory.h>
#import <YandexMapKit/YMKCameraPosition.h>
#import <YandexMapKit/YMKBoundingBox.h>
#import "RNYandexMapView.h"

@interface RNYandexMapViewManager: RCTViewManager
@end;

@implementation RNYandexMapViewManager

RCT_EXPORT_MODULE(RNYandexMap)

RCT_EXPORT_VIEW_PROPERTY(onMapEvent, RCTBubblingEventBlock);

RCT_CUSTOM_VIEW_PROPERTY(cameraPosition, NSDictionary, RNYandexMap)
{
  NSDictionary *point = [RCTConvert NSDictionary:json[@"point"]];
  if (point != nil) {
    double latitude = [RCTConvert double:point[@"latitude"]];
    double longitude = [RCTConvert double:point[@"longitude"]];
    double zoom = [RCTConvert double:json[@"zoom"]];
    double azimuth = [RCTConvert double:json[@"azimuth"]];
    double tilt = [RCTConvert double:json[@"tilt"]];
    YMKPoint *target = [YMKPoint pointWithLatitude:latitude longitude:longitude];
    [view.mapWindow.map moveWithCameraPosition:[YMKCameraPosition cameraPositionWithTarget:target
                                                                                      zoom:zoom
                                                                                   azimuth:azimuth
                                                                                      tilt:tilt]
     ];
  } else {
    NSDictionary *southWest = [RCTConvert NSDictionary:json[@"southWest"]];
    NSDictionary *northEast = [RCTConvert NSDictionary:json[@"northEast"]];
    double gap = [RCTConvert double:json[@"gap"]];

    if (southWest != nil && northEast != nil) {
      double southWestLat = [RCTConvert double:southWest[@"latitude"]];
      double southWestLon = [RCTConvert double:southWest[@"longitude"]];
      double northEastLat = [RCTConvert double:northEast[@"latitude"]];
      double northEastLon = [RCTConvert double:northEast[@"longitude"]];
      YMKPoint *southWestPoint = [YMKPoint pointWithLatitude:southWestLat longitude:southWestLon];
      YMKPoint *northEastPoint = [YMKPoint pointWithLatitude:northEastLat longitude:northEastLon];

      YMKBoundingBox *bbox = [YMKBoundingBox boundingBoxWithSouthWest:southWestPoint northEast:northEastPoint];

      YMKCameraPosition *exactPos = [view.mapWindow.map cameraPositionWithBoundingBox:bbox];

      YMKCameraPosition *newPos = [YMKCameraPosition cameraPositionWithTarget:exactPos.target zoom:15 - gap azimuth:exactPos.azimuth tilt:exactPos.tilt];

      [view.mapWindow.map moveWithCameraPosition:exactPos];
    }
  }

}

- (UIView *) view
{
  RNYandexMap *map = [RNYandexMap new];
  return map;
}

@end
