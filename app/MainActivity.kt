package com.qpsx2

import android.os.Bundle
import android.widget.Button
import androidx.appcompat.app.AppCompatActivity

class MainActivity : AppCompatActivity() {

    external fun initGPU()
    external fun renderGPU()

    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)

        initGPU()

        val btn = Button(this)
        btn.text = "Render Frame"

        btn.setOnClickListener {
            renderGPU()
        }

        setContentView(btn)
    }

    companion object {
        init {
            System.loadLibrary("qpsx2")
        }
    }
}
