package com.github.dmitryermichev.reactnative.yandexmapkit3;

import android.content.Context;
import android.graphics.Bitmap;
import android.graphics.PointF;
import android.graphics.drawable.Drawable;
import android.net.Uri;
import android.util.Log;

import androidx.annotation.NonNull;

import com.bumptech.glide.Glide;
import com.bumptech.glide.request.target.CustomTarget;
import com.bumptech.glide.request.transition.Transition;
import com.facebook.react.bridge.Arguments;
import com.facebook.react.bridge.ReactContext;
import com.facebook.react.bridge.WritableMap;
import com.facebook.react.uimanager.events.RCTEventEmitter;
import com.facebook.react.views.view.ReactViewGroup;
import com.yandex.mapkit.geometry.Point;
import com.yandex.mapkit.map.IconStyle;
import com.yandex.mapkit.map.Map;
import com.yandex.mapkit.map.MapObject;
import com.yandex.mapkit.map.MapObjectTapListener;
import com.yandex.mapkit.map.PlacemarkMapObject;
import com.yandex.runtime.image.ImageProvider;

public class RNYandexPlacemark extends RNYandexMapObject {

    private Point point;
    private String imageUri;
    private PointF anchor = new PointF(0.5f, 0.5f);
    private float scale = 1.0f;

    private PlacemarkMapObject placemark;
    private Map map;
    private ReactContext reactContext;

    public RNYandexPlacemark(Context context) {
        super(context);

        this.reactContext = (ReactContext) context;
    }

    private void setPlacemark(PlacemarkMapObject pm) {
        this.placemark = pm;
        this.placemark.addTapListener(new MapObjectTapListener() {
            @Override
            public boolean onMapObjectTap(@NonNull MapObject mapObject, @NonNull Point point) {
                WritableMap payload = Arguments.createMap();
                reactContext.getJSModule(RCTEventEmitter.class).receiveEvent(RNYandexPlacemark.this.getId(), MAP_OBJECT_TAP_EVENT, payload);
                return true;
            }
        });
    }

    @Override
    public void addToMap(Map map) {
        this.map = map;
        final IconStyle iconStyle = new IconStyle();
        iconStyle.setAnchor(this.getAnchor());
        iconStyle.setScale(this.getScale());

        final Map targetMap = map;
        if (this.getImageUri() != null) {
            Log.d("RNYandexMap", "Loading marker image " + this.getImageUri());
            Glide.with(this)
                    .asBitmap()
                    .load(Uri.parse(this.getImageUri()))
                    .into(new CustomTarget<Bitmap>() {
                        @Override
                        public void onResourceReady(@NonNull Bitmap resource, @androidx.annotation.Nullable Transition<? super Bitmap> transition) {
                            PlacemarkMapObject placemark = targetMap.getMapObjects().addPlacemark(
                                    RNYandexPlacemark.this.getPoint(),
                                    ImageProvider.fromBitmap(resource, true, RNYandexPlacemark.this.getImageUri()),
                                    iconStyle
                            );
                            setPlacemark(placemark);
                        }

                        @Override
                        public void onLoadCleared(@androidx.annotation.Nullable Drawable placeholder) {

                        }
                    });

        } else {
            PlacemarkMapObject placemark = targetMap.getMapObjects().addPlacemark(
                    RNYandexPlacemark.this.getPoint(),
                    ImageProvider.fromResource(RNYandexPlacemark.this.getContext(), R.drawable.marker),
                    iconStyle
            );
            setPlacemark(placemark);
        }
    }

    @Override
    public void removeFromMap() {
        if (this.placemark != null && this.map != null) {
            map.getMapObjects().remove(this.placemark);
        }
    }

    public void setPoint(Point point) {
        this.point = point;
    }

    public Point getPoint() {
        return this.point;
    }

    public void setImageUri(String uri) {
        this.imageUri = uri;
    }

    public String getImageUri() {
        return this.imageUri;
    }

    public void setAnchor(PointF anchor) {
        this.anchor = anchor;
    }

    public PointF getAnchor() {
        return this.anchor;
    }

    public void setScale(float scale) {
        this.scale = scale;
    }

    public float getScale() {
        return this.scale;
    }
}
