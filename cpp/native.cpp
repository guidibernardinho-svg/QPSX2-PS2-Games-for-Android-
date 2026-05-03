#include <jni.h>

extern "C"
JNIEXPORT void JNICALL
Java_com_qpsx2_MainActivity_runPS2(JNIEnv *env, jobject thiz, jstring path) {
    const char *iso = env->GetStringUTFChars(path, 0);

    // Aqui entraria o emulador real (PCSX2 core futuramente)
    // por enquanto só placeholder
    // start_emulation(iso);

    env->ReleaseStringUTFChars(path, iso);
}
