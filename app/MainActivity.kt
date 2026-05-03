package com.qpsx2

import android.os.Bundle
import android.widget.Button
import androidx.appcompat.app.AppCompatActivity

class MainActivity : AppCompatActivity() {

    external fun runPS2(isoPath: String)

    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)

        val btn = Button(this)
        btn.text = "Start PS2"

        btn.setOnClickListener {
            runPS2("/sdcard/PS2/game.iso")
        }

        setContentView(btn)
    }

    companion object {
        init {
            System.loadLibrary("qpsx2")
        }
    }
}
