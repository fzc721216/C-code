//
// Created by 86150 on 2023/3/28.
//
#include "clz_Register.h"
JNIEXPORT jstring JNICALL Java_clz_Register_helloworld
        (JNIEnv *env, jobject jobject){
    return (*env).NewStringUTF("helloworld");
}