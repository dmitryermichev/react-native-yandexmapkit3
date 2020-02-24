# react-native-yandexmapkit3

## Установка

`$ npm install react-native-yandexmapkit3 --save`

## Настройка

Для корректной работы карты необходимо инициализировать модуль при старте и указать ключ для доступа к картам. 

### Android

```java
public class MainActivity extends ReactActivity {

    /**
     * Returns the name of the main component registered from JavaScript.
     * This is used to schedule rendering of the component.
     */
    @Override
    protected String getMainComponentName() {
        return "mapsTest";
    }

    @Override
    protected void onStart() {
        super.onStart();
        ReactNativeYandexmapkit3Module.init(this, "YANDEX_MAP_API_KEY");
        ReactNativeYandexmapkit3Module.onStart();
    }

    @Override
    protected void onStop() {
        super.onStop();
        ReactNativeYandexmapkit3Module.onStop();
    }
}
```

### IOS

```objective-c
/**
 * Copyright (c) Facebook, Inc. and its affiliates.
 *
 * This source code is licensed under the MIT license found in the
 * LICENSE file in the root directory of this source tree.
 */

#import "AppDelegate.h"

#import <React/RCTBridge.h>
#import <React/RCTBundleURLProvider.h>
#import <React/RCTRootView.h>
#import <YandexMapKit/YMKMapKitFactory.h>

// Yandex Map api key
NSString * const YANDEX_MAP_KEY = @"YANDEX_MAP_API_KEY";

@implementation AppDelegate

- (BOOL)application:(UIApplication *)application didFinishLaunchingWithOptions:(NSDictionary *)launchOptions
{
  RCTBridge *bridge = [[RCTBridge alloc] initWithDelegate:self launchOptions:launchOptions];
  RCTRootView *rootView = [[RCTRootView alloc] initWithBridge:bridge
                                                   moduleName:@"mapsTest"
                                            initialProperties:nil];

  rootView.backgroundColor = [[UIColor alloc] initWithRed:1.0f green:1.0f blue:1.0f alpha:1];

  self.window = [[UIWindow alloc] initWithFrame:[UIScreen mainScreen].bounds];
  UIViewController *rootViewController = [UIViewController new];
  rootViewController.view = rootView;
  self.window.rootViewController = rootViewController;
  [self.window makeKeyAndVisible];
  
  // Init MapKit with your key
  [YMKMapKit setApiKey: YANDEX_MAP_KEY];
  return YES;
}

- (NSURL *)sourceURLForBridge:(RCTBridge *)bridge
{
#if DEBUG
  return [[RCTBundleURLProvider sharedSettings] jsBundleURLForBundleRoot:@"index" fallbackResource:nil];
#else
  return [[NSBundle mainBundle] URLForResource:@"main" withExtension:@"jsbundle"];
#endif
}

@end

```

## Пример использования (typescript)

```typescript

import * as React from 'react';
import {StatusBar, StyleSheet, View, Text, Button, Alert} from 'react-native';

import {Colors,} from 'react-native/Libraries/NewAppScreen';
import {CameraPosition, YandexMap, YandexPlacemark} from "react-native-yandexmapkit3";
import {useState} from "react";

const initialPosition: CameraPosition = {
  point: {
    latitude: 55.755833,
    longitude: 37.617222,
  },
  azimuth: 0,
  zoom: 15,
  tilt: 0,
};

const App = () => {
  const [cameraPosition, setCameraPosition] = useState(initialPosition);
  const [markerLocations, setMarkerLocations] = useState([initialPosition.point]);
  return (
    <>
      <StatusBar barStyle="dark-content" />
      <YandexMap style={{flex: 1}}
                 cameraPosition={cameraPosition}
                 onInteraction={cp => setCameraPosition(cp)}
      >
        {markerLocations.map(loc => <YandexPlacemark
            location={loc}
            onTap={() => Alert.alert("Нажат маркер", JSON.stringify(loc))}
            />
        )}
      </YandexMap>

      <View style={styles.bottom}>
        <View style={styles.locationInfoContainer}>
            <Text style={styles.locationInfo}>Широта: {round(cameraPosition.point.latitude)}</Text>
            <Text style={styles.locationInfo}>Долгота: {round(cameraPosition.point.longitude)}</Text>
        </View>
        <View style={styles.buttonContainer}>
            <Button title={"Добавить маркер"} onPress={() => {
                setMarkerLocations([...markerLocations, cameraPosition.point])
            }}/>
        </View>
      </View>
    </>
  );
};

function round(num: number) {
    return Math.round(num * 100000) / 100000;
}

const styles = StyleSheet.create({
    locationInfo: {
        fontSize: 16,
    },
    locationInfoContainer: {
        flex: 1,
        height: 50,
        flexDirection: 'row',
        justifyContent: 'space-around',
        alignItems: 'center'
    },
    bottom: {
        backgroundColor: '#ffffff80',
        position: 'absolute',
        bottom: 0,
        left: 0,
        right: 0,
        flexDirection: 'column',
    },
    buttonContainer: {
        flex: 1,
        height: 50,
        justifyContent: 'center',
        alignItems: 'center'
    },
});

export default App;


```
