#include "lvgl/lvgl.h"

#define SPO2_BOX_H_SIZE 200
#define SPO2_BOX_V_SIZE 100

static lv_obj_t* SPO2_box = NULL;
static lv_obj_t* SPO2_label = NULL;
static lv_timer_t* SPO2_blink_timer = NULL;

void create_SPO2_box(lv_obj_t* container);
void Switch_SPO2_position(void);
void blink_SPO2_label_cb(lv_timer_t* timer);
void SPO2_Blink(void);
