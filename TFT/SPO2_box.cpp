#include "SPO2_box.h"

void create_SPO2_box(lv_obj_t* container)
{
    // Create the principal box
    SPO2_box = lv_obj_create(container);
    lv_obj_set_size(SPO2_box, SPO2_BOX_H_SIZE, SPO2_BOX_V_SIZE); // Set the size of the box
    lv_obj_set_style_bg_color(SPO2_box, lv_color_hex(0x000000), LV_PART_MAIN); // Set backgorund color
    lv_obj_set_style_border_width(SPO2_box, 5, LV_PART_MAIN); // Set border width
    lv_obj_set_style_border_color(SPO2_box, lv_palette_main(LV_PALETTE_YELLOW), LV_PART_MAIN); // Set border color
    lv_obj_set_style_radius(SPO2_box, 0, LV_PART_MAIN); // Rounded corners
    lv_obj_set_style_pad_all(SPO2_box, 0, LV_PART_MAIN); // No padding

    //Position the box
    lv_obj_align(SPO2_box, LV_ALIGN_TOP_LEFT, 0, 0);

    // Create a label for numbers inside the box
    SPO2_label = lv_label_create(SPO2_box);
    lv_label_set_text(SPO2_label, "120"); // Set the number text
    lv_obj_set_style_text_color(SPO2_label, lv_palette_main(LV_PALETTE_YELLOW), LV_PART_MAIN);
    lv_obj_center(SPO2_label); // Center the label inside the box
}

void Switch_SPO2_position(void)
{
    lv_obj_move_to_index(SPO2_box, 0); // Move box1 to the second position
}

void SPO2_Blink(void)
{
    SPO2_blink_timer = lv_timer_create(blink_SPO2_label_cb, 500, NULL); // 500 ms interval
}

void blink_SPO2_label_cb(lv_timer_t* timer) {
    // Toggle the visibility
    bool is_hidden = lv_obj_has_flag(SPO2_label, LV_OBJ_FLAG_HIDDEN);
    if (is_hidden) {
        lv_obj_clear_flag(SPO2_label, LV_OBJ_FLAG_HIDDEN); // Show the label
    }
    else {
        lv_obj_add_flag(SPO2_label, LV_OBJ_FLAG_HIDDEN);   // Hide the label
    }
}
