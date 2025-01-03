#include "chart1.h"

void create_chart1(lv_obj_t* container)
{
    lv_obj_t* chart1 = lv_obj_create(container);

    lv_obj_set_size(chart1, CHART_H_SIZE, CHART_V_SIZE); // Tamaño: 600x110 píxeles
    lv_obj_set_pos(chart1, 0, 0);      // Posición en la parte superior del contenedor
    lv_obj_set_style_bg_opa(chart1, LV_OPA_TRANSP, LV_PART_MAIN); // Hacerlo transparente
    lv_obj_set_style_border_width(chart1, 0, LV_PART_MAIN);       // Sin bordes
    lv_obj_clear_flag(chart1, LV_OBJ_FLAG_SCROLLABLE);
    //lv_obj_set_flex_flow(chart1, LV_FLEX_FLOW_ROW); // Arrange items in a column
    //lv_obj_set_flex_align(chart1, LV_FLEX_ALIGN_SPACE_BETWEEN, LV_FLEX_ALIGN_START, LV_FLEX_ALIGN_CENTER);
    lv_obj_set_style_pad_all(chart1, 0, LV_PART_MAIN); // No padding

    //lv_obj_set_style_border_width(TOP_layout, 2, LV_PART_MAIN); // Set border width
    //lv_obj_set_style_border_color(TOP_layout, lv_palette_main(LV_PALETTE_GREY), LV_PART_MAIN); // Set border color
    draw_waveform1(chart1);
}

void draw_waveform1(lv_obj_t* container)
{
    // Create a style for the line
    static lv_style_t line_style;
    lv_style_init(&line_style);

    lv_style_set_line_color(&line_style, lv_palette_main(LV_PALETTE_GREEN));// Set the line color (e.g., green)
    lv_style_set_line_width(&line_style, 1);// Set the line width
    lv_style_set_line_rounded(&line_style, true);// Set antialiasing

    for (int k = 0;k<120; k++)
    {
        waveform1[k] = lv_line_create(container);
        lv_obj_align(waveform1[k], LV_ALIGN_LEFT_MID, 0, 0);
        lv_obj_add_style(waveform1[k], &line_style, 0);// Apply the style to the line
    }

    for (int i = 0; i < CHART_H_SIZE; i++)
    {
        waveform_points1[i].y = 0;  // Sine wave equation
    }

    // Create a timer to update the phase and redraw the line
    lv_timer_t* timer = lv_timer_create(update_waveform_timer_cb1, 25, NULL);  // Update every 50 ms (20 fps)
}

// Timer callback to update the phase and trigger a redraw
static void update_waveform_timer_cb1(lv_timer_t* timer) {
    static int waveform_cnt = 0;
    static int waveform_sec = 0;

    for (int i = 0; i < 5; i++)
    {
        waveform_points1[waveform_cnt].y = CHART_V_SIZE / 2 + (int)(CHART_V_SIZE / 2 * sin((2 * PI * waveform_cnt) / 300));  // Sine wave equation

        if (waveform_cnt < 595)
        {
            if ((i == 4) && (waveform_cnt != 594))
            {
                waveform_points1[waveform_cnt + 6].y = 500;  // Sine wave equation
                waveform_points1[waveform_cnt + 6].x = i;
            }
            waveform_points1[waveform_cnt + 5].y = 500;  // Sine wave equation
            waveform_points1[waveform_cnt + 5].x = i;
        }
        else
        {
            waveform_points1[600 - waveform_cnt].y = 500;  // Sine wave equation
            waveform_points1[600 - waveform_cnt].x = i;
        }
        

        if (waveform_sec == 0)
        {
            waveform_points1[waveform_cnt].x = i;
        }
        else
        {
            if (i == 0)
            {
                waveform_points1[waveform_cnt-1].x = i;
            }
            waveform_points1[waveform_cnt].x = i + 1;
        }

        waveform_cnt++;
        if (waveform_cnt >= CHART_H_SIZE)
        {
            waveform_cnt = 0;
        }
    }

    if (waveform_sec == 0)
    {
        lv_line_set_points(waveform1[waveform_sec], &waveform_points1[waveform_sec * 5], 5);
        lv_line_set_points(waveform1[waveform_sec + 1], &waveform_points1[waveform_sec * 5 + 5], 6);
        lv_obj_align(waveform1[waveform_sec], LV_ALIGN_TOP_LEFT, waveform_sec * 5, 0);
    }
    else if (waveform_sec < 119)
    {
        lv_line_set_points(waveform1[waveform_sec], &waveform_points1[(waveform_sec * 5) - 1], 6);
        lv_line_set_points(waveform1[waveform_sec + 1], &waveform_points1[waveform_sec * 5 + 5], 6);
        lv_obj_align(waveform1[waveform_sec], LV_ALIGN_TOP_LEFT, (waveform_sec * 5) - 1, 0);
    }
    else if (waveform_sec <= 119)
    {
        lv_line_set_points(waveform1[waveform_sec], &waveform_points1[(waveform_sec * 5) - 1], 6);
        lv_line_set_points(waveform1[0], &waveform_points1[0], 5);
        lv_obj_align(waveform1[waveform_sec], LV_ALIGN_TOP_LEFT, (waveform_sec * 5) - 1, 0);
    }
    

    waveform_sec++;
    if (waveform_sec >= 120)
    {
        waveform_sec = 0;
    }
 }

