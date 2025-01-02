#include "HR_box.h"

void create_HR_box(lv_obj_t* container)
{
    // Create the principal box
    HR_box = lv_obj_create(container);
    lv_obj_set_size(HR_box, HR_BOX_H_SIZE, HR_BOX_V_SIZE); // Set the size of the box
    lv_obj_set_style_bg_color(HR_box, lv_color_hex(0x000000), LV_PART_MAIN); // Set backgorund color
    lv_obj_set_style_border_width(HR_box, 5, LV_PART_MAIN); // Set border width
    lv_obj_set_style_border_color(HR_box, lv_palette_main(LV_PALETTE_GREEN), LV_PART_MAIN); // Set border color
    lv_obj_set_style_radius(HR_box, 0, LV_PART_MAIN); // Rounded corners
    lv_obj_set_style_pad_all(HR_box, 0, LV_PART_MAIN); // No padding

    //Position the box
    lv_obj_align(HR_box, LV_ALIGN_TOP_LEFT, 0, 0);

    // Create a label for numbers inside the box
    lv_obj_t* HR_label = lv_label_create(HR_box);
    lv_label_set_text(HR_label, "120"); // Set the number text
    lv_obj_set_style_text_color(HR_label, lv_palette_main(LV_PALETTE_GREEN), LV_PART_MAIN);
    lv_obj_center(HR_label); // Center the label inside the box
}

void Switch_HR_position(void)
{
    lv_obj_move_to_index(HR_box, 0); // Move box1 to the second position
}
