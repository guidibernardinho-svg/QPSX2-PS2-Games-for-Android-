#include <jni.h>

extern void initRenderer();
extern void renderFrame();

extern "C"
JNIEXPORT void JNICALL
Java_com_qpsx2_MainActivity_initGPU(JNIEnv*, jobject) {
    initRenderer();
}

extern "C"
JNIEXPORT void JNICALL
Java_com_qpsx2_MainActivity_renderGPU(JNIEnv*, jobject) {
    renderFrame();
}
