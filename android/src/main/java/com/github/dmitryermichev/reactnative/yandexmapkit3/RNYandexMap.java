package com.github.dmitryermichev.reactnative.yandexmapkit3;

import android.Manifest;
import android.app.Activity;
import android.content.Context;
import android.content.ContextWrapper;
import android.content.pm.PackageManager;
import android.graphics.Color;
import android.graphics.PointF;
import android.util.AttributeSet;
import android.util.Log;

import com.facebook.react.bridge.Arguments;
import com.facebook.react.bridge.ReactContext;
import com.facebook.react.bridge.WritableMap;
import com.facebook.react.uimanager.events.RCTEventEmitter;
import com.yandex.mapkit.Animation;
import com.yandex.mapkit.MapKitFactory;
import com.yandex.mapkit.geometry.Point;
import com.yandex.mapkit.layers.ObjectEvent;
import com.yandex.mapkit.location.Location;
import com.yandex.mapkit.location.LocationListener;
import com.yandex.mapkit.location.LocationStatus;
import com.yandex.mapkit.logo.Alignment;
import com.yandex.mapkit.logo.HorizontalAlignment;
import com.yandex.mapkit.logo.VerticalAlignment;
import com.yandex.mapkit.map.CameraListener;
import com.yandex.mapkit.map.CameraPosition;
import com.yandex.mapkit.map.CameraUpdateSource;
import com.yandex.mapkit.map.Map;
import com.yandex.mapkit.map.MapObject;
import com.yandex.mapkit.mapview.MapView;
import com.yandex.mapkit.user_location.UserLocationLayer;
import com.yandex.mapkit.user_location.UserLocationObjectListener;
import com.yandex.mapkit.user_location.UserLocationView;

import java.math.BigDecimal;
import java.math.RoundingMode;

import javax.annotation.Nullable;

public class RNYandexMap extends MapView implements CameraListener {

    public static final String MAP_EVENT = "onMapEvent";

    public static final int USER_EVENT = 1;
    public static final int APPLICATION_EVENT = 2;

    public RNYandexMap(Context context) {
        super(context);
        this.onStart();
        this.getMap().addCameraListener(this);
        this.getMap().move(new CameraPosition(new Point(0, 0), 16, 0, 0));
        this.getMap().getLogo().setAlignment(new Alignment(HorizontalAlignment.RIGHT, VerticalAlignment.TOP));
    }

    public RNYandexMap(Context context, AttributeSet attributeSet) {
        super(context, attributeSet);
    }

    @Override
    public void onCameraPositionChanged(Map map, CameraPosition cameraPosition, CameraUpdateSource cameraUpdateSource, boolean finished) {
        if(finished) {
            Point mapCenter = cameraPosition.getTarget();
            int type = 0;
            if (cameraUpdateSource == CameraUpdateSource.GESTURES) {
                type = USER_EVENT;
            } else {
                type = APPLICATION_EVENT;
            }
            notifyPositionChanged(type, mapCenter);
        }
    }

    private void notifyPositionChanged(int type, Point position) {
        WritableMap payload = Arguments.createMap();
        double mapLatitude = BigDecimal.valueOf(position.getLatitude())
                .setScale(6, RoundingMode.HALF_UP)
                .doubleValue();
        double mapLongitude = BigDecimal.valueOf(position.getLongitude())
                .setScale(6, RoundingMode.HALF_UP)
                .doubleValue();

        CameraPosition currentCameraPosition = this.getMap().getCameraPosition();
        WritableMap point = Arguments.createMap();
        point.putInt("type", type);
        point.putDouble("latitude",  mapLatitude);
        point.putDouble("longitude", mapLongitude);

        payload.putDouble("zoom", currentCameraPosition.getZoom());
        payload.putDouble("azimuth", currentCameraPosition.getAzimuth());
        payload.putDouble("tilt", currentCameraPosition.getTilt());
        payload.putMap("point", point);

        ReactContext reactContext = (ReactContext) getContext();
        reactContext.getJSModule(RCTEventEmitter.class).receiveEvent(this.getId(), MAP_EVENT, payload);
    }

}
