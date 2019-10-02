package com.github.dmitryermichev.reactnative.yandexmapkit3;

import android.content.Context;

import com.facebook.react.bridge.ReactApplicationContext;
import com.facebook.react.bridge.ReactContextBaseJavaModule;
import com.facebook.react.bridge.ReactMethod;
import com.facebook.react.bridge.Callback;
import com.yandex.mapkit.MapKitFactory;

public class ReactNativeYandexmapkit3Module extends ReactContextBaseJavaModule {

    private final ReactApplicationContext reactContext;

    public ReactNativeYandexmapkit3Module(ReactApplicationContext reactContext) {
        super(reactContext);
        this.reactContext = reactContext;
    }

    @Override
    public String getName() {
        return "RNYandexMapKit";
    }

    public static void init(Context activity, String apiKey){
        MapKitFactory.setApiKey(apiKey);
        MapKitFactory.initialize(activity);
    }

    public static void onStop() {
        MapKitFactory.getInstance().onStop();
    }

    public static void onStart() {
        MapKitFactory.getInstance().onStart();
    }
}
