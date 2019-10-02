/**
 * Sample React Native App
 *
 * adapted from App.js generated by the following command:
 *
 * react-native init example
 *
 * https://github.comApp/facebook/react-native
 */

import React from 'react';
import {StyleSheet} from 'react-native';
import {CameraPosition, Event, YandexMap} from 'react-native-yandexmapkit3';

type Props = {}

const initialCameraPosition: CameraPosition = {
    point: {
        type: Event.UserEvent,
        latitude: 43.0000,
        longitude: 41.0167,
    },
    zoom: 15,
    azimuth: 0,
    tilt: 0,
};

export default class App extends React.PureComponent<Props> {
    constructor(props: Props) {
        super(props);
    }


    render() {
        return (
            <YandexMap style={styles.container}
                       cameraPosition={initialCameraPosition}
                       onInteraction={(event) => console.warn(event)}
            >
            </YandexMap>
        );
    }
}

const styles = StyleSheet.create({
    container: {
        flex: 1,
        justifyContent: 'center',
        alignItems: 'center',
        backgroundColor: '#F5FCFF',
    },
    welcome: {
        fontSize: 20,
        textAlign: 'center',
        margin: 10,
    },
    instructions: {
        textAlign: 'center',
        color: '#333333',
        marginBottom: 5,
    },
});