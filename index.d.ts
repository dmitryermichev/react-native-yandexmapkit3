import {ViewProps} from 'react-native';
import * as React from 'react';

declare module "react-native-yandexmapkit3" {
    export enum Event {
        UserEvent = 1,
        ApplicationEvent = 2
    }

    export type Location = {
        type: Event,
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

    export class YandexMap extends React.PureComponent<YandexMapProps, any> {
    }
}
