import {BoundingBox, Location} from './YandexMap';


export const locationsToBoundingBox: (locations: Location[], gap: number) => BoundingBox = (locations: Location[], gap: number) => {
    let minLatitude: number = 90;
    let maxLatitude: number = -90;
    let minLongitude: number = 180;
    let maxLongitude: number = -180;
    locations.forEach(loc => {
        if (loc.latitude < minLatitude) {
            minLatitude = loc.latitude;
        }
        if (loc.latitude > maxLatitude) {
            maxLatitude = loc.latitude;
        }
        if (loc.longitude < minLongitude) {
            minLongitude = loc.longitude;
        }
        if (loc.longitude > maxLongitude) {
            maxLongitude = loc.longitude;
        }
    });

    return {
        southWest: {latitude: minLatitude, longitude: minLongitude},
        northEast: {latitude: maxLatitude, longitude: maxLongitude},
        gap: gap,
    }
};
