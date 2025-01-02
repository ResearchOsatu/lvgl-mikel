#include "images.h"

void create_icon(lv_obj_t* container, int img_id)
{
    img[img_id] = lv_img_create(container);  // Create an image object
#if defined(__linux__)
    lv_img_set_src(img[img_id], "images/lvgl_logo.png");  // Set the file path
#else
    lv_img_set_src(img[img_id], "C:/Users/miel_/Documents/GitHub/LVGL/TFT/rsc/images/lvgl_logo.png");  // Set the file path
#endif
    lv_obj_align(img[img_id], LV_ALIGN_CENTER, 0, 0);  // Center the image on the screen
}

void hide_icon(int img_id)
{
    lv_obj_add_flag(img[img_id], LV_OBJ_FLAG_HIDDEN);  // Hide the image
}

void show_icon(int img_id)
{
    lv_obj_remove_flag(img[img_id], LV_OBJ_FLAG_HIDDEN);
}