import {NativeModules} from 'react-native';

import YandexMap, {
    CameraPosition,
    Event,
    Location,
    OnInteractionCallback,
    OnInteractionResult,
    YandexMapProps
} from "./YandexMap";

import YandexPlacemark, {YandexPlacemarkProps,} from "./YandexPlacemark";

const {RNYandexMapKit} = NativeModules;

export {
    YandexMap,
    CameraPosition,
    Event,
    Location,
    OnInteractionResult,
    OnInteractionCallback,
    YandexMapProps,
    YandexPlacemark,
    YandexPlacemarkProps,
};
export default RNYandexMapKit;
