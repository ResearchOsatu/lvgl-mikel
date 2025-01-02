#include "lvgl/lvgl.h"
#include <time.h>

void create_time_layout(lv_obj_t* container);
static void update_labels(lv_timer_t* timer);
void get_current_date(char* date_str);
void get_current_time(char* time_str);
void get_elapsed_time(char* elapsed_str);
static lv_timer_t* Time_timer = NULL;
static lv_obj_t* label_date;
static lv_obj_t* label_time;
static lv_obj_t* label_elapsed;
static time_t start_time;  // To store the time when the app starts