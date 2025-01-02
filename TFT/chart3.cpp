#include "chart3.h"

void create_chart3(lv_obj_t* container)
{
    lv_obj_t* chart3 = lv_obj_create(container);

    lv_obj_set_size(chart3, CHART_H_SIZE, CHART_V_SIZE); // Tamaño: 600x110 píxeles
    lv_obj_set_pos(chart3, 0, 0);      // Posición en la parte superior del contenedor
    lv_obj_set_style_bg_opa(chart3, LV_OPA_TRANSP, LV_PART_MAIN); // Hacerlo transparente
    lv_obj_set_style_border_width(chart3, 0, LV_PART_MAIN);       // Sin bordes
    lv_obj_clear_flag(chart3, LV_OBJ_FLAG_SCROLLABLE);
    lv_obj_set_flex_flow(chart3, LV_FLEX_FLOW_ROW); // Arrange items in a column
    lv_obj_set_flex_align(chart3, LV_FLEX_ALIGN_SPACE_BETWEEN, LV_FLEX_ALIGN_START, LV_FLEX_ALIGN_CENTER);
    lv_obj_set_style_pad_all(chart3, 0, LV_PART_MAIN); // No padding

    //lv_obj_set_style_border_width(TOP_layout, 2, LV_PART_MAIN); // Set border width
    //lv_obj_set_style_border_color(TOP_layout, lv_palette_main(LV_PALETTE_GREY), LV_PART_MAIN); // Set border color
    draw_waveform3(chart3);
}

void draw_waveform3(lv_obj_t* container)
{
    waveform3_1 = lv_line_create(container);
    waveform3_2 = lv_line_create(container);

    lv_obj_align(waveform3_1, LV_ALIGN_LEFT_MID, 0, 0);  // Align to the left side of the container
    lv_obj_align(waveform3_2, LV_ALIGN_LEFT_MID, 0, 0);  // Align to the left side of the container

    // Create a style for the line
    static lv_style_t line_style;
    lv_style_init(&line_style);
    
    lv_style_set_line_color(&line_style, lv_palette_main(LV_PALETTE_RED));// Set the line color (e.g., green)
    lv_style_set_line_width(&line_style, 2);// Set the line width
    lv_style_set_line_rounded(&line_style, true);// Set antialiasing
    lv_obj_add_style(waveform3_1, &line_style, 0);// Apply the style to the line
    lv_obj_add_style(waveform3_2, &line_style, 0);// Apply the style to the line

    for (int i = 0; i < CHART_H_SIZE; i++)
    {
        waveform_points3[i].x = i;
        waveform_points3[i].y = 0;  // Sine wave equation
    }

    // Create a timer to update the phase and redraw the line
    lv_timer_t* timer = lv_timer_create(update_waveform_timer_cb3, 25, NULL);  // Update every 50 ms (20 fps)
}

// Timer callback to update the phase and trigger a redraw
static void update_waveform_timer_cb3(lv_timer_t* timer) {
    static int waveform_cnt = 0;
    static bool first_round = TRUE;

    for (int i = 0; i < 5; i++)
    {
        waveform_points3[waveform_cnt].y = CHART_V_SIZE/2 + (int)(CHART_V_SIZE/2 * sin((2 * PI * waveform_cnt) / 150));  // Sine wave equation

        waveform_cnt++;
        if (waveform_cnt >= CHART_H_SIZE)
        {
            waveform_cnt = 0;
            first_round = FALSE;
        }
    }

    lv_line_set_points(waveform3_1, waveform_points3, waveform_cnt);
    if (!first_round)
    {
        lv_line_set_points(waveform3_2, &waveform_points3[waveform_cnt + 5], CHART_H_SIZE - waveform_cnt - 5);
    }
 }

