#include "time_layout.h"

void create_time_layout(lv_obj_t* container)
{
    lv_obj_t* time_layout = lv_obj_create(container);

    lv_obj_set_size(time_layout, 100, 50); // Tamaño: 800x380 píxeles
    lv_obj_set_pos(time_layout, 0, 0);      // Posición en la parte superior del contenedor
    lv_obj_set_style_bg_opa(time_layout, LV_OPA_TRANSP, LV_PART_MAIN); // Hacerlo transparente
    lv_obj_set_style_border_width(time_layout, 0, LV_PART_MAIN);       // Sin bordes
    lv_obj_clear_flag(time_layout, LV_OBJ_FLAG_SCROLLABLE);
    lv_obj_set_style_pad_all(time_layout, 0, LV_PART_MAIN); // No padding
    lv_obj_set_flex_flow(time_layout, LV_FLEX_FLOW_COLUMN); // Arrange items in a column
    lv_obj_set_flex_align(time_layout, LV_FLEX_ALIGN_START, LV_FLEX_ALIGN_START, LV_FLEX_ALIGN_CENTER);
    lv_obj_set_style_pad_row(time_layout, 0, LV_PART_MAIN); // Remove row padding

    lv_obj_t* time_date_layout = lv_obj_create(time_layout);

    lv_obj_set_size(time_date_layout, 100, 25); // Tamaño: 800x380 píxeles
    lv_obj_set_pos(time_date_layout, 0, 0);      // Posición en la parte superior del contenedor
    lv_obj_set_style_bg_opa(time_date_layout, LV_OPA_TRANSP, LV_PART_MAIN); // Hacerlo transparente
    lv_obj_set_style_border_width(time_date_layout, 0, LV_PART_MAIN);       // Sin bordes
    lv_obj_clear_flag(time_date_layout, LV_OBJ_FLAG_SCROLLABLE);
    lv_obj_set_style_pad_all(time_date_layout, 0, LV_PART_MAIN); // No padding
    lv_obj_set_flex_flow(time_date_layout, LV_FLEX_FLOW_ROW); // Arrange items in a column
    lv_obj_set_flex_align(time_date_layout, LV_FLEX_ALIGN_START, LV_FLEX_ALIGN_START, LV_FLEX_ALIGN_CENTER);
    lv_obj_set_style_pad_row(time_date_layout, 0, LV_PART_MAIN); // Remove row padding

    label_date = lv_label_create(time_date_layout);
    lv_label_set_text(label_date, " ");
    lv_obj_set_style_text_color(label_date, lv_palette_main(LV_PALETTE_YELLOW), LV_PART_MAIN);

    label_time = lv_label_create(time_date_layout);
    lv_label_set_text(label_time, " ");
    lv_obj_set_style_text_color(label_time, lv_palette_main(LV_PALETTE_YELLOW), LV_PART_MAIN);

    label_elapsed = lv_label_create(time_layout);
    lv_label_set_text(label_elapsed, " ");
    lv_obj_set_style_text_color(label_elapsed, lv_palette_main(LV_PALETTE_YELLOW), LV_PART_MAIN);

    Time_timer = lv_timer_create(update_labels, 500, NULL); // 500 ms interval

    //lv_obj_set_style_border_width(TOP_layout, 2, LV_PART_MAIN); // Set border width
    //lv_obj_set_style_border_color(TOP_layout, lv_palette_main(LV_PALETTE_GREY), LV_PART_MAIN); // Set border color
}

// Función que se ejecuta periódicamente para actualizar la hora
static void update_labels(lv_timer_t* timer) {
    char date_str[20];
    char time_str[9];
    char elapsed_str[20];

    get_current_date(date_str);
    get_current_time(time_str);
    get_elapsed_time(elapsed_str);

    lv_label_set_text(label_date, date_str);
    lv_label_set_text(label_time, time_str);
    lv_label_set_text(label_elapsed, elapsed_str);
}

// Function to get the current date as a string
void get_current_date(char* date_str) {
    time_t rawtime;
    struct tm* timeinfo;

    time(&rawtime);
    timeinfo = localtime(&rawtime);

    // Format: YYYY-MM-DD
    strftime(date_str, sizeof(date_str), "%b-%d", timeinfo);
}

// Function to get the current time as a string
void get_current_time(char* time_str) {
    time_t rawtime;
    struct tm* timeinfo;

    time(&rawtime);
    timeinfo = localtime(&rawtime);

    // Format: HH:MM:SS
    strftime(time_str, 9, "%H:%M", timeinfo);
}

// Function to get the elapsed time since start (in seconds)
void get_elapsed_time(char* elapsed_str) {
    static bool first_time = TRUE;
    time_t current_time;
    struct tm* timeinfo;

    if (first_time)
    {
        time(&start_time);
        first_time = FALSE;
    }
    time(&current_time);

    // Calculate elapsed time in seconds
    time_t elapsed = current_time - start_time;
    
    timeinfo = gmtime(&elapsed);

    strftime(elapsed_str, 9, "%H:%M:%S", timeinfo);

    // Format: Elapsed time: mm:ss
    //snprintf(elapsed_str, 20, "Elapsed: %02ld:%02ld", seconds / 60, seconds % 60);
}
