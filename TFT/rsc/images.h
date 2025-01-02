#include "lvgl/lvgl.h"

#ifndef IMAGES_H
#define IMAGES_H

void create_icon(lv_obj_t* container, int img_id);
void hide_icon(int img_id);
void show_icon(int img_id);

static lv_obj_t* img[10];

#endif