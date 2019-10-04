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
import {Dimensions, StyleSheet, Text, TouchableOpacity} from 'react-native';
import {
    BoundingBox,
    CameraPosition,
    locationsToBoundingBox,
    YandexMap,
    YandexPlacemark,
} from 'react-native-yandexmapkit3';

type Props = {}

const initialCameraPosition: CameraPosition = {
    point: {
        latitude: 43.0000,
        longitude: 41.0167,
    },
    zoom: 15,
    azimuth: 0,
    tilt: 0,
};

const initialBoundingBox: BoundingBox = {
    gap: 0.8,
    northEast: {latitude: 43.0000, longitude: 41.0167},
    southWest: {latitude: 44.0000, longitude: 42.0167},
};

const markers = [
    {latitude: 43.0030, longitude: 41.0167},
    {latitude: 43.0020, longitude: 41.0157},
    {latitude: 43.0010, longitude: 41.0147},
];

type State = {
    displayMarkers: boolean;
    cameraPosition: CameraPosition | BoundingBox;
}


export default class App extends React.PureComponent<Props, State> {
    constructor(props: Props) {
        super(props);

        this.state = {
            displayMarkers: true,
            cameraPosition: locationsToBoundingBox(markers, 0.5),
        }
    }

    toggleMarkers() {
        this.setState(prevState => ({...prevState, displayMarkers: !prevState.displayMarkers}))
    }

    render() {
        return (
            <>
                <YandexMap style={styles.container}
                           cameraPosition={this.state.cameraPosition}
                           onInteraction={(position) => this.setState(prevState => ({
                               ...prevState,
                               cameraPosition: position
                           }))}>
                    {this.state.displayMarkers
                        ? markers.map(marker => (<YandexPlacemark
                            image={require('./assets/marker.png')}
                            location={marker}
                            anchor={{x: 0.5, y: 1}}
                            scale={0.4}
                            onTap={() => console.warn('marker tapped')}
                        />))
                        : null}


                </YandexMap>
                <TouchableOpacity style={styles.bottomButton}
                                  onPress={() => this.toggleMarkers()}>
                    <Text style={styles.buttonText}>Makrers toggle</Text>
                </TouchableOpacity>
            </>
        );
    }
}

const styles = StyleSheet.create({
    bottomButton: {
        position: 'absolute',
        bottom: 0,
        height: 50,
        width: Dimensions.get("window").width,
        flex: 1,
        backgroundColor: '#0d7a2f',
        justifyContent: 'center',
        alignItems: 'center',
    },
    buttonText: {
        color: '#fff',
    },
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
