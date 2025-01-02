#include "Boxes.h"

void create_boxes(lv_obj_t* container)
{
    lv_obj_t* Boxes_layout = lv_obj_create(container);

    lv_obj_set_size(Boxes_layout, 200, 380); // Tamaño: 800x380 píxeles
    lv_obj_set_pos(Boxes_layout, 0, 0);      // Posición en la parte superior del contenedor
    lv_obj_set_style_bg_opa(Boxes_layout, LV_OPA_TRANSP, LV_PART_MAIN); // Hacerlo transparente
    lv_obj_set_style_border_width(Boxes_layout, 0, LV_PART_MAIN);       // Sin bordes
    lv_obj_clear_flag(Boxes_layout, LV_OBJ_FLAG_SCROLLABLE);
    lv_obj_set_style_pad_all(Boxes_layout, 0, LV_PART_MAIN); // No padding
    lv_obj_set_flex_flow(Boxes_layout, LV_FLEX_FLOW_COLUMN); // Arrange items in a column
    lv_obj_set_flex_align(Boxes_layout, LV_FLEX_ALIGN_START, LV_FLEX_ALIGN_START, LV_FLEX_ALIGN_CENTER);
    lv_obj_set_style_pad_row(Boxes_layout, 0, LV_PART_MAIN); // Remove row padding

    //lv_obj_set_style_border_width(Boxes_layout, 2, LV_PART_MAIN); // Set border width
    //lv_obj_set_style_border_color(Boxes_layout, lv_palette_main(LV_PALETTE_ORANGE), LV_PART_MAIN); // Set border color

    create_HR_box(Boxes_layout);
    create_SPO2_box(Boxes_layout);

    SPO2_Blink(); //Make SPO2 value blink
    Switch_SPO2_position(); //Put SPO2 in the first position
}
