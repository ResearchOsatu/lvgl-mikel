#include "lvgl/lvgl.h"
#include "charts_layout.h"
#include <math.h>

static lv_point_precise_t waveform_points3[600];

static lv_obj_t* waveform3_1;
static lv_obj_t* waveform3_2;

void create_chart3(lv_obj_t* container);
void draw_waveform3(lv_obj_t* container);
static void update_waveform_timer_cb3(lv_timer_t* timer);
