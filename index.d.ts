import {ViewProps} from 'react-native';
import * as React from 'react';

declare module "react-native-yandexmapkit3" {
    import {ImageRequireSource} from 'react-native';
    export type Location = {
        readonly latitude: number;
        readonly longitude: number;
    };

    export type OnInteractionResult = CameraPosition;

    export type OnInteractionCallback = (event: OnInteractionResult) => void;

    export interface CameraPosition {
        point: Location;
        zoom: number;
        azimuth: number;
        tilt: number;
    }

    export type YandexMapProps = {
        cameraPosition: CameraPosition;
        onInteraction?: OnInteractionCallback;
    } & ViewProps;

    export type Anchor = {
        x: number;
        y: number;
    }

    export type YandexPlacemarkProps = {
        location: Location;
        image?: ImageRequireSource;
        scale?: number;
        anchor?: Anchor;
        onTap?: () => void;
    } & ViewProps;

    export class YandexMap extends React.PureComponent<YandexMapProps, any> {
    }

    export class YandexPlacemark extends React.PureComponent<YandexPlacemarkProps, any> {
    }
}
