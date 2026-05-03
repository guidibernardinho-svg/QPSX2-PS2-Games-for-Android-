#include <jni.h>

extern bool initVulkan();
extern void renderVulkanFrame();

extern "C"
JNIEXPORT jboolean JNICALL
Java_com_qpsx2_MainActivity_initVulkan(JNIEnv*, jobject) {
    return initVulkan();
}

extern "C"
JNIEXPORT void JNICALL
Java_com_qpsx2_MainActivity_renderFrame(JNIEnv*, jobject) {
    renderVulkanFrame();
}
