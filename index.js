import {NativeModules} from 'react-native';

import YandexMap, {
    CameraPosition,
    Event,
    Location,
    OnInteractionCallback,
    OnInteractionResult,
    YandexMapProps
} from "./YandexMap";

const {RNYandexMapKit} = NativeModules;

export {
    YandexMap,
    CameraPosition,
    Event,
    Location,
    OnInteractionResult,
    OnInteractionCallback,
    YandexMapProps
};
export default RNYandexMapKit;
