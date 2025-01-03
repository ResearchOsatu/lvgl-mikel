#include "lvgl/lvgl.h"
#include "charts_layout.h"
#include <math.h>

static lv_point_precise_t waveform_points1[600];

static lv_obj_t* waveform1[120];

void create_chart1(lv_obj_t* container);
void draw_waveform1(lv_obj_t* container);
static void update_waveform_timer_cb1(lv_timer_t* timer);
