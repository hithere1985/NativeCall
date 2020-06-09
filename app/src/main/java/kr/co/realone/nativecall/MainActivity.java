package kr.co.realone.nativecall;

import android.os.Bundle;
import android.util.Log;
import android.widget.TextView;

import androidx.appcompat.app.AppCompatActivity;

public class MainActivity extends AppCompatActivity {
    private static String TAG = "realone";

    // Used to load the 'native-lib' library on application startup.
    static {
        System.loadLibrary("native-lib");
        initNative();
    }

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        // Example of a call to a native method
        TextView tv = findViewById(R.id.sample_text);
        tv.setText(stringFromJNI());
    }

    /**
     * A native method that is implemented by the 'native-lib' native library,
     * which is packaged with this application.
     */
    public native String stringFromJNI();

    public native static void initNative();

    public static void sayHello(float[] data) {
        Log.i(TAG, "param size is " + data.length);
        for (float x : data) {
            Log.i(TAG, "value: " + x);
        }
    }

    public static void sayHelloNoParams() {
        Log.i(TAG, "hello no param");
    }
}
