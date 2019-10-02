package com.example;

import android.os.Bundle;
import android.os.PersistableBundle;
import android.util.Log;

import com.facebook.react.ReactActivity;
import com.github.dmitryermichev.reactnative.yandexmapkit3.ReactNativeYandexmapkit3Module;

public class MainActivity extends ReactActivity {

    /**
     * Returns the name of the main component registered from JavaScript.
     * This is used to schedule rendering of the component.
     */
    @Override
    protected String getMainComponentName() {
        return "example";
    }

    @Override
    public void onCreate(Bundle savedInstanceState, PersistableBundle persistentState) {
        super.onCreate(savedInstanceState, persistentState);
    }

    @Override
    protected void onStart() {
        super.onStart();
        ReactNativeYandexmapkit3Module.init(this,"f70b7e51-b91f-4d73-9f7b-235a3d6b506a");
        ReactNativeYandexmapkit3Module.onStart();
    }

    @Override
    protected void onStop() {
        super.onStop();
        ReactNativeYandexmapkit3Module.onStop();
    }
}
