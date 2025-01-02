#include "lvgl/lvgl.h"

#define MESSAGE_BOX_H_SIZE 800
#define MESSAGE_BOX_V_SIZE 50

static lv_obj_t* message_box = NULL;
static lv_obj_t* message_label = NULL;
static lv_timer_t* message_blink_timer = NULL;

void create_message_box(lv_obj_t* container);
void blink_message_cb(lv_timer_t* timer);
void message_Blink(void);
void message_set(const char* text);
