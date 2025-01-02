#include "message_box.h"

void create_message_box(lv_obj_t* container)
{
    // Create the principal box
    message_box = lv_obj_create(container);
    lv_obj_set_size(message_box, MESSAGE_BOX_H_SIZE, MESSAGE_BOX_V_SIZE); // Set the size of the box
    lv_obj_set_style_bg_color(message_box, lv_palette_main(LV_PALETTE_GREY), LV_PART_MAIN); // Set backgorund color
    lv_obj_set_style_border_width(message_box, 0, LV_PART_MAIN); // Set border width
    lv_obj_set_style_radius(message_box, 5, LV_PART_MAIN); // Rounded corners
    lv_obj_set_style_pad_all(message_box, 0, LV_PART_MAIN); // No padding

    //Position the box
    lv_obj_align(message_box, LV_ALIGN_TOP_LEFT, 0, 0);

    // Create a label for numbers inside the box
    message_label = lv_label_create(message_box);
    lv_obj_set_style_text_color(message_label, lv_palette_main(LV_PALETTE_DEEP_ORANGE), LV_PART_MAIN);

    static lv_style_t message_style;
    lv_style_init(&message_style);
    lv_style_set_text_font(&message_style, &lv_font_montserrat_24); // Use a larger font
    lv_obj_add_style(message_label, &message_style, 0);


    lv_obj_center(message_label); // Center the label inside the box
}

void message_Blink(void)
{
    message_blink_timer = lv_timer_create(blink_message_cb, 500, NULL); // 500 ms interval
}

void blink_message_cb(lv_timer_t* timer) {
    // Toggle the visibility
    bool is_hidden = lv_obj_has_flag(message_label, LV_OBJ_FLAG_HIDDEN);
    if (is_hidden) {
        lv_obj_clear_flag(message_label, LV_OBJ_FLAG_HIDDEN); // Show the label
        lv_timer_set_period(message_blink_timer, 2000);
    }
    else {
        lv_obj_add_flag(message_label, LV_OBJ_FLAG_HIDDEN);   // Hide the label
        lv_timer_set_period(message_blink_timer, 500);
    }
}

void message_set(const char* text)
{
    lv_label_set_text(message_label, text); // Set the number text
}
