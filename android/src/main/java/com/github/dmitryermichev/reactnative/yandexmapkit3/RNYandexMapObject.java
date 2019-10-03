package com.github.dmitryermichev.reactnative.yandexmapkit3;

import android.content.Context;

import com.facebook.react.views.view.ReactViewGroup;
import com.yandex.mapkit.map.Map;

public abstract class RNYandexMapObject extends ReactViewGroup {
    public static final String MAP_OBJECT_TAP_EVENT = "onMapObjectTapEvent";

    public RNYandexMapObject(Context context) {
        super(context);
    }

    public abstract void addToMap(Map map);
}
