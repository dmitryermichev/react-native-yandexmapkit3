//
//  RNYandexPlacemark.m
//  mobileapp
//
//  Created by Dev on 14/10/2019.
//  Copyright © 2019 Facebook. All rights reserved.
//

#import "RNYandexPlacemark.h"
#import <YandexMapKit/YMKIconStyle.h>
#import <YandexMapKit/YMKIconStyle.h>
#import <YandexMapKit/YMKRotationType.h>

@implementation RNYandexPlacemark
  
  -(void)addToMap:(YMKMap *)map
  {
    self.map = map;
    if (self.image != nil) {
      if ([self.image hasPrefix:@"http"]) {
        dispatch_async(dispatch_get_global_queue(DISPATCH_QUEUE_PRIORITY_DEFAULT, 0), ^{
          NSData *data =[NSData dataWithContentsOfURL:[NSURL URLWithString:self.image]];
          dispatch_async(dispatch_get_main_queue(), ^{
            UIImage *image = [UIImage imageWithData:data];
            [self initPlacemark:image];
          });
        });
      } else {
        UIImage *image = [UIImage imageNamed:self.image];
        [self initPlacemark:image];
      }
      
    } else {
      [self initPlacemark:[UIImage imageNamed:@"Marker"]];
    }
  }

  -(void)removeFromMap
  {
    [self.map.mapObjects removeWithMapObject:self.placemark];
  }
  
  -(void) initPlacemark:(UIImage *)image
  {
    NSLog(@"%@", self.scale);
    YMKIconStyle *is = [YMKIconStyle iconStyleWithAnchor:[self anchor] rotationType:nil zIndex:nil flat:nil visible:nil scale:self.scale tappableArea:nil];
    self.placemark = [self.map.mapObjects addPlacemarkWithPoint:[self location] image:image style:is];
    
    [self.placemark addTapListenerWithTapListener:self];
  }
  
  - (BOOL)onMapObjectTapWithMapObject:(nonnull YMKMapObject *)mapObject
                                point:(nonnull YMKPoint *)point {
    self.onMapObjectTapEvent(@{
        @"latitude": @(point.latitude),
        @"longitude": @(point.longitude)
    });
    return YES;
  }

@end
