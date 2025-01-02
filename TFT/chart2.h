#include "lvgl/lvgl.h"
#include "charts_layout.h"
#include <math.h>

static lv_point_precise_t waveform_points2[600];

static lv_obj_t* waveform2_1;
static lv_obj_t* waveform2_2;

void create_chart2(lv_obj_t* container);
void draw_waveform2(lv_obj_t* container);
static void update_waveform_timer_cb2(lv_timer_t* timer);
