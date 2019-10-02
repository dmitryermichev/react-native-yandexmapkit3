import React from 'react';
import {NativeComponent, requireNativeComponent, ViewProps} from 'react-native';

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

class YandexMap extends React.PureComponent<YandexMapProps, any> {

    private prevCameraPosition: CameraPosition | null = null;
    private nativeMap: NativeComponent | null = null;

    componentDidMount() {
        const {cameraPosition} = this.props;
        if (cameraPosition && this.nativeMap) {
            this.nativeMap.setNativeProps({cameraPosition});
        }
    }

    componentWillUpdate(nextProps: YandexMapProps) {
        if (!this.prevCameraPosition || !nextProps.cameraPosition) {
            return;
        }
        if (
            this.prevCameraPosition.point.latitude !== nextProps.cameraPosition.point.latitude ||
            this.prevCameraPosition.point.longitude !== nextProps.cameraPosition.point.longitude ||
            this.prevCameraPosition.zoom !== nextProps.cameraPosition.zoom ||
            this.prevCameraPosition.azimuth !== nextProps.cameraPosition.azimuth ||
            this.prevCameraPosition.tilt !== nextProps.cameraPosition.tilt
        ) {
            this.nativeMap!.setNativeProps({cameraPosition: nextProps.cameraPosition});
        }
    }

    render() {
        // Omit region and set it via setNativeProps
        const {cameraPosition, ...rest} = this.props;
        return (
            <RNYandexMap ref={(map: NativeComponent) => {
                this.nativeMap = map
            }}
                         {...rest}
                         cameraPosition={cameraPosition}
                         onMapEvent={this.onMapEventInternal}
            />
        );
    }

    onMapEventInternal = (event: { nativeEvent: CameraPosition }) => {
        const cameraEvent = event.nativeEvent;
        this.prevCameraPosition = cameraEvent;
        if (this.props.onInteraction && cameraEvent.point.type === Event.UserEvent) {
            this.props.onInteraction(event.nativeEvent);
        }
    };

    // runCommand = (name: string, args: any) => {
    //   switch (Platform.OS) {
    //     case 'android':
    //       NativeModules.UIManager.dispatchViewManagerCommand(
    //         findNodeHandle(this.nativeMap),
    //         NativeModules.UIManager.RNYandexMap.Commands[name],
    //         args
    //       );
    //       break;
    //
    //     case 'ios':
    //       NativeModules.RNYandexMapViewManager[name].apply(
    //         NativeModules.RNYandexMapViewManager[name],
    //         [findNodeHandle(this.nativeMap), ...args]
    //       );
    //       break;
    //
    //     default:
    //       break;
    //   }
    // }

}

const RNYandexMap = requireNativeComponent('RNYandexMap', YandexMap);

export default YandexMap;
