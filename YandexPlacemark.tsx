import React from 'react';
import {Image, ImageRequireSource, NativeComponent, requireNativeComponent, ViewProps} from 'react-native';
import {Location} from './YandexMap';

export type Anchor = {
    x: number;
    y: number;
}

export type YandexPlacemarkProps = {
    location: Location;
    image: ImageRequireSource;
    scale?: number;
    anchor?: Anchor;
    onTap?: () => void;
} & ViewProps;

class YandexPlacemark extends React.PureComponent<YandexPlacemarkProps, any> {

    private prevLocation: Location | null = null;
    private nativePlacemark: NativeComponent | null = null;

    constructor(props: YandexPlacemarkProps) {
        super(props);
        this.onMapObjectTapInternal.bind(this);
    }

    componentDidMount() {
        const {location} = this.props;
        if (location && this.nativePlacemark) {
            this.nativePlacemark.setNativeProps({location});
        }
    }

    componentWillUpdate(nextProps: YandexPlacemarkProps) {
        if (!this.prevLocation || !nextProps.location) {
            return;
        }
        if (
            this.prevLocation.latitude !== nextProps.location.latitude ||
            this.prevLocation.longitude !== nextProps.location.longitude
        ) {
            this.nativePlacemark!.setNativeProps({location: nextProps.location});
        }
    }

    onMapObjectTapInternal = (event: { nativeEvent: any }) => {
        if (this.props.onTap) {
            this.props.onTap();
        }
    };

    render() {
        // Omit region and set it via setNativeProps
        const {location, image, scale, anchor, ...rest} = this.props;
        return (
            <RNYandexPlacemark ref={(map: NativeComponent) => {
                this.nativePlacemark = map
            }}
                               {...rest}
                               location={location}
                               image={image ? Image.resolveAssetSource(image).uri : undefined}
                               scale={scale}
                               anchor={anchor}
                               onMapObjectTapEvent={this.onMapObjectTapInternal}
            />
        );
    }
}

const RNYandexPlacemark = requireNativeComponent('RNYandexPlacemark', YandexPlacemark);

export default YandexPlacemark;
