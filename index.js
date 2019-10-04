import {NativeModules} from 'react-native';

import YandexMap, {
    BoundingBox,
    CameraPosition,
    Event,
    Location,
    OnInteractionCallback,
    OnInteractionResult,
    YandexMapProps
} from "./YandexMap";

import {locationsToBoundingBox} from "./Utils";

import YandexPlacemark, {YandexPlacemarkProps,} from "./YandexPlacemark";

const {RNYandexMapKit} = NativeModules;

export {
    YandexMap,
    CameraPosition,
    Event,
    Location,
    BoundingBox,
    OnInteractionResult,
    OnInteractionCallback,
    YandexMapProps,
    YandexPlacemark,
    YandexPlacemarkProps,
    locationsToBoundingBox,
};
export default RNYandexMapKit;
