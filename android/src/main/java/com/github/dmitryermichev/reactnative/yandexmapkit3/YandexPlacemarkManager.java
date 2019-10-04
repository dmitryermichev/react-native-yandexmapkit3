package com.github.dmitryermichev.reactnative.yandexmapkit3;

import android.graphics.PointF;
import android.view.View;

import com.facebook.react.bridge.ReadableMap;
import com.facebook.react.common.MapBuilder;
import com.facebook.react.uimanager.ThemedReactContext;
import com.facebook.react.uimanager.ViewGroupManager;
import com.facebook.react.uimanager.annotations.ReactProp;
import com.yandex.mapkit.geometry.Point;
import com.yandex.mapkit.map.CameraPosition;
import com.yandex.mapkit.map.MapObjectCollection;

import java.util.Map;

import javax.annotation.Nonnull;
import javax.annotation.Nullable;

import static com.github.dmitryermichev.reactnative.yandexmapkit3.RNYandexMapObject.MAP_OBJECT_TAP_EVENT;

public class YandexPlacemarkManager extends ViewGroupManager<RNYandexPlacemark> {
    public static final String REACT_CLASS = "RNYandexPlacemark";

    @Override
    public String getName() {
        return REACT_CLASS;
    }

    @Override
    protected RNYandexPlacemark createViewInstance(ThemedReactContext reactContext) {
        RNYandexPlacemark placemark = new RNYandexPlacemark(reactContext);
        return placemark;
    }

    @Override
    public void onDropViewInstance(@Nonnull RNYandexPlacemark view) {
        super.onDropViewInstance(view);
        view.removeFromMap();
    }

    @ReactProp(name="location")
    public void setLocation(RNYandexPlacemark placemark, ReadableMap location){
        Point point = new Point(
                location.getDouble("latitude"),
                location.getDouble("longitude")
        );

        placemark.setPoint(point);
    }

    @ReactProp(name="image")
    public void setImage(RNYandexPlacemark placemark, String imageUri) {
        placemark.setImageUri(imageUri);
    }

    @ReactProp(name="anchor")
    public void setAnchor(RNYandexPlacemark placemark, ReadableMap anchor) {
        PointF anchorPoint = new PointF();
        anchorPoint.x = (float) anchor.getDouble("x");
        anchorPoint.y = (float) anchor.getDouble("y");
        placemark.setAnchor(anchorPoint);
    }

    @ReactProp(name="scale")
    public void setScale(RNYandexPlacemark placemark, double scale) {
        placemark.setScale((float) scale);
    }

    @Nullable
    @Override
    public Map<String, Object> getExportedCustomDirectEventTypeConstants() {
        MapBuilder.Builder<String, Object> builder = MapBuilder.builder();
        builder.put(MAP_OBJECT_TAP_EVENT,       MapBuilder.of("registrationName", MAP_OBJECT_TAP_EVENT));
        return builder.build();
    }
}
