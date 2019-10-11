//
//  RNTMapView.h
//  ReactNativeYMMap
//
//  Created by Дима on 11.09.2018.
//  Copyright © 2018 Facebook. All rights reserved.
//

#import <React/RCTComponent.h>
#import <YandexMapKit/YMKMapKitFactory.h>

@interface RNYandexMap: YMKMapView <YMKMapCameraListener>

@property (nonatomic, copy) RCTBubblingEventBlock onMapEvent;

@end;
