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
            <Text style={styles.locationInfo}>Широта: {cameraPosition.point.latitude}</Text>
            <Text style={styles.locationInfo}>Долгота: {cameraPosition.point.longitude}</Text>
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
