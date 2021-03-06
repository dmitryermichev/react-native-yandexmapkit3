package com.github.dmitryermichev.reactnative.yandexmapkit3;

import android.content.Context;
import android.graphics.Bitmap;
import android.graphics.PointF;
import android.graphics.drawable.Drawable;
import android.net.Uri;
import android.util.Log;
import android.widget.Toast;

import androidx.annotation.NonNull;

import com.bumptech.glide.Glide;
import com.bumptech.glide.RequestBuilder;
import com.bumptech.glide.RequestManager;
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

public class RNYandexPlacemark extends RNYandexMapObject implements MapObjectTapListener {

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
        this.placemark.addTapListener(this);
    }

    @Override
    public void addToMap(Map map) {
        this.map = map;
        final IconStyle iconStyle = new IconStyle();
        iconStyle.setAnchor(this.getAnchor());
        iconStyle.setScale(this.getScale());

        final Map targetMap = map;
        if (this.getImageUri() != null) {
            String imageUrl = this.getImageUri();
            boolean isUrl = imageUrl.startsWith("http");
            RequestBuilder<Bitmap> rm = Glide.with(this).asBitmap();
            if (isUrl) {
                rm = rm.load(Uri.parse(this.getImageUri()));
            } else {
                int resourceId = this.reactContext.getResources().getIdentifier(imageUrl, "drawable", reactContext.getPackageName());
                rm = rm.load(resourceId);
            }

            rm.into(new CustomTarget<Bitmap>() {
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
        if (this.placemark != null) {
            final IconStyle iconStyle = new IconStyle();
            iconStyle.setAnchor(this.getAnchor());
            iconStyle.setScale(this.getScale());
            this.placemark.setIconStyle(iconStyle);
        }
    }

    public float getScale() {
        return this.scale;
    }

    public boolean onMapObjectTap(@NonNull MapObject mapObject, @NonNull Point point) {
        WritableMap payload = Arguments.createMap();
        reactContext.getJSModule(RCTEventEmitter.class).receiveEvent(RNYandexPlacemark.this.getId(), MAP_OBJECT_TAP_EVENT, payload);
        return true;
    }
}
