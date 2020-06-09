//
// Created by realone on 2020/06/03.
//

#ifndef B612_ANDROID_LOG_REALONE_H
#define B612_ANDROID_LOG_REALONE_H


#include <android/log.h>

#define LOGT(...) __android_log_print(ANDROID_LOG_DEBUG, "realone", __VA_ARGS__)


#endif //B612_ANDROID_LOG_REALONE_H
