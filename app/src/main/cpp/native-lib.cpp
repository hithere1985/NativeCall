#include <jni.h>
#include <string>
#include <iostream>
#include "log_realone.h"

extern "C" JNIEXPORT jstring JNICALL
Java_kr_co_realone_nativecall_MainActivity_stringFromJNI(
        JNIEnv *env,
        jobject /* this */) {
    std::string hello = "Hello from C++";
    return env->NewStringUTF(hello.c_str());
}

extern "C"
JNIEXPORT void JNICALL
Java_kr_co_realone_nativecall_MainActivity_initNative(JNIEnv *env, jclass clazz) {
    // 함수 아이디 검색
    jmethodID noParamFunctionId = env->GetStaticMethodID(clazz, "sayHelloNoParams", "()V");
    LOGT("mid %p", noParamFunctionId);

    // 아무 인자가 없는 함수를 실행
    env->CallStaticVoidMethod(clazz, noParamFunctionId);

    // float array 만들기
    jfloatArray result;
    result = env->NewFloatArray(3);
    if (result == nullptr) {
        return; /* out of memory error thrown */
    }

    jfloat array1[3];
    array1[0] = 1;
    array1[1] = 2;
    array1[2] = 3;

    env->SetFloatArrayRegion(result, 0, 3, array1);

    // 함수 아이디 검색
    jmethodID paramFunctionId = env->GetStaticMethodID(clazz, "sayHello", "([F)V");
    LOGT("mid %p", paramFunctionId);

    // 만들어둔 jfloat Array를 넘긴다
    env->CallStaticVoidMethod(clazz, paramFunctionId, result);
}