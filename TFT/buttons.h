#include "lvgl/lvgl.h"

#define BUTTONS_H_SIZE 800
#define BUTTONS_V_SIZE 50
#define BUTTON_H_SIZE 100
#define BUTTON_SPACE_H_SIZE 75
#define BUTTONS_N 5

static lv_obj_t* buttons = NULL;
static lv_obj_t* button[BUTTONS_N] = { NULL };
static lv_obj_t* buttons_label[BUTTONS_N] = { NULL };
static int button_id[BUTTONS_N] = { 0 };
static lv_obj_t* buttons_space[BUTTONS_N - 1] = { NULL };

void create_buttons(lv_obj_t* container);
void button_set(int button, const char* text);
char* button_get(int button);
static void button_event_cb(lv_event_t* e);
