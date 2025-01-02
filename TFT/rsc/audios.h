#include "lvgl/lvgl.h"
#if defined(__linux__)
#else
#include <windows.h>
#include <mmsystem.h>
#pragma comment(lib, "winmm.lib") // Vincula automáticamente winmm.lib
#endif

#ifndef IMAGES_H
#define IMAGES_H

void play_audio(void);

#endif