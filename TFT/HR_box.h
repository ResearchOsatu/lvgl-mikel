#include "lvgl/lvgl.h"

#define HR_BOX_H_SIZE 200
#define HR_BOX_V_SIZE 100

static lv_obj_t* HR_box = NULL;

void create_HR_box(lv_obj_t* container);
void Switch_HR_position(void);
