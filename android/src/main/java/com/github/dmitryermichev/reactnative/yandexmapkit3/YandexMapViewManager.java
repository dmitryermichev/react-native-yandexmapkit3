package com.github.dmitryermichev.reactnative.yandexmapkit3;

import com.facebook.react.bridge.ReadableMap;
import com.facebook.react.common.MapBuilder;
import com.facebook.react.uimanager.SimpleViewManager;
import com.facebook.react.uimanager.ThemedReactContext;
import com.facebook.react.uimanager.annotations.ReactProp;
import com.yandex.mapkit.MapKitFactory;
import com.yandex.mapkit.geometry.Point;
import com.yandex.mapkit.map.CameraPosition;

import java.util.Map;

import javax.annotation.Nonnull;
import javax.annotation.Nullable;

public class YandexMapViewManager extends SimpleViewManager<RNYandexMap> {
    public static final String REACT_CLASS = "RNYandexMap";

    @Override
    public String getName() {
        return REACT_CLASS;
    }

    @Override
    protected RNYandexMap createViewInstance(ThemedReactContext reactContext) {
        RNYandexMap view = new RNYandexMap(reactContext);
        view.onStart();
        return view;
    }

    @Override
    public void onDropViewInstance(@Nonnull RNYandexMap view) {
        super.onDropViewInstance(view);
        view.onStop();
    }

    @ReactProp(name="cameraPosition")
    public void setCameraPosition(RNYandexMap mapView, ReadableMap cameraPosition){
        ReadableMap location = cameraPosition.getMap("point");
        double latitude = 0;
        double longitude = 0;
        if (location != null) {
            latitude = location.getDouble("latitude");
            longitude = location.getDouble("longitude");
        }
        float zoom = (float) cameraPosition.getDouble("zoom");
        float azimuth = (float) cameraPosition.getDouble("azimuth");
        float tilt = (float) cameraPosition.getDouble("tilt");

        mapView.getMap().move(new CameraPosition(new Point(latitude, longitude), zoom, azimuth, tilt));
    }

    @Nullable
    @Override
    public Map<String, Object> getExportedCustomDirectEventTypeConstants() {
        MapBuilder.Builder<String, Object> builder = MapBuilder.builder();
        builder.put(RNYandexMap.MAP_EVENT,       MapBuilder.of("registrationName", RNYandexMap.MAP_EVENT));
        return builder.build();
    }

}
