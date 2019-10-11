# react-native-yandexmapkit3

## Getting started

`$ npm install react-native-yandexmapkit3 --save`

### Mostly automatic installation

`$ react-native link react-native-yandexmapkit3`

### Manual installation


#### iOS

1. In XCode, in the project navigator, right click `Libraries` ➜ `Add Files to [your project's name]`
2. Go to `node_modules` ➜ `react-native-yandexmapkit3` and add `ReactNativeYandexmapkit3.xcodeproj`
3. In XCode, in the project navigator, select your project. Add `libReactNativeYandexmapkit3.a` to your project's `Build Phases` ➜ `Link Binary With Libraries`
4. Run your project (`Cmd+R`)<

#### Android

1. Open up `android/app/src/main/java/[...]/MainApplication.java`
  - Add `import com.github.dmitryermichev.reactnative.yandexmapkit3.ReactNativeYandexmapkit3Package;` to the imports at the top of the file
  - Add `new ReactNativeYandexmapkit3Package()` to the list returned by the `getPackages()` method
2. Append the following lines to `android/settings.gradle`:
  	```
  	include ':react-native-yandexmapkit3'
  	project(':react-native-yandexmapkit3').projectDir = new File(rootProject.projectDir, 	'../node_modules/react-native-yandexmapkit3/android')
  	```
3. Insert the following lines inside the dependencies block in `android/app/build.gradle`:
  	```
      compile project(':react-native-yandexmapkit3')
  	```


## Usage
```javascript
import ReactNativeYandexmapkit3 from 'react-native-yandexmapkit3';

// TODO: What to do with the module?
ReactNativeYandexmapkit3;
```
