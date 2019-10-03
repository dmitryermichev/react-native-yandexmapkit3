package com.github.dmitryermichev.reactnative.yandexmapkit3;

import android.graphics.Bitmap;
import android.graphics.drawable.Drawable;
import android.net.Uri;
import android.util.Log;
import android.view.View;

import androidx.annotation.NonNull;

import com.bumptech.glide.Glide;
import com.bumptech.glide.request.target.CustomTarget;
import com.bumptech.glide.request.target.SimpleTarget;
import com.bumptech.glide.request.transition.Transition;
import com.facebook.react.bridge.Arguments;
import com.facebook.react.bridge.ReactContext;
import com.facebook.react.bridge.ReadableMap;
import com.facebook.react.bridge.WritableMap;
import com.facebook.react.common.MapBuilder;
import com.facebook.react.uimanager.ThemedReactContext;
import com.facebook.react.uimanager.ViewGroupManager;
import com.facebook.react.uimanager.annotations.ReactProp;
import com.facebook.react.uimanager.events.RCTEventEmitter;
import com.yandex.mapkit.geometry.Point;
import com.yandex.mapkit.map.CameraPosition;
import com.yandex.mapkit.map.IconStyle;
import com.yandex.mapkit.map.MapObject;
import com.yandex.mapkit.map.MapObjectCollection;
import com.yandex.mapkit.map.MapObjectTapListener;
import com.yandex.mapkit.map.RotationType;
import com.yandex.runtime.image.ImageProvider;

import java.util.Map;

import javax.annotation.Nonnull;
import javax.annotation.Nullable;

import static com.github.dmitryermichev.reactnative.yandexmapkit3.RNYandexMapObject.MAP_OBJECT_TAP_EVENT;

public class YandexMapViewManager extends ViewGroupManager<RNYandexMap> {
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

    @Override
    public void addView(RNYandexMap parent, View child, int index) {
        // Пропускаем добавление если объект не MapObject
        if (!(child instanceof RNYandexMapObject)) {
            return;
        }

        if (child instanceof RNYandexPlacemark) {
            ((RNYandexPlacemark) child).addToMap(parent.getMap());
        }
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
