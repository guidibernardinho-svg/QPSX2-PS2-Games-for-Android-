package com.qpsx2

import android.app.Activity
import android.os.Bundle
import android.widget.Button
import android.widget.LinearLayout
import android.widget.Toast

class MainActivity : Activity() {

    external fun initVulkan(): Boolean
    external fun renderFrame()

    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)

        val layout = LinearLayout(this)
        layout.orientation = LinearLayout.VERTICAL

        val startBtn = Button(this)
        startBtn.text = "Start QPSX2"

        val renderBtn = Button(this)
        renderBtn.text = "Render"

        startBtn.setOnClickListener {
            val ok = initVulkan()
            Toast.makeText(
                this,
                if (ok) "Vulkan Ready" else "Init Failed",
                Toast.LENGTH_SHORT
            ).show()
        }

        renderBtn.setOnClickListener {
            renderFrame()
        }

        layout.addView(startBtn)
        layout.addView(renderBtn)

        setContentView(layout)
    }

    companion object {
        init {
            System.loadLibrary("qpsx2")
        }
    }
}
