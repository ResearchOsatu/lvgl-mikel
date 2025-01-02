#include "TOP_layout.h"

void create_TOP_layout(lv_obj_t* container)
{
    lv_obj_t* TOP_layout = lv_obj_create(container);

    lv_obj_set_size(TOP_layout, 800, 380); // Tamaño: 800x380 píxeles
    lv_obj_set_pos(TOP_layout, 0, 0);      // Posición en la parte superior del contenedor
    lv_obj_set_style_bg_opa(TOP_layout, LV_OPA_TRANSP, LV_PART_MAIN); // Hacerlo transparente
    lv_obj_set_style_border_width(TOP_layout, 0, LV_PART_MAIN);       // Sin bordes
    lv_obj_clear_flag(TOP_layout, LV_OBJ_FLAG_SCROLLABLE);
    lv_obj_set_style_pad_all(TOP_layout, 0, LV_PART_MAIN); // No padding
    lv_obj_set_flex_flow(TOP_layout, LV_FLEX_FLOW_ROW); // Arrange items in a column
    lv_obj_set_flex_align(TOP_layout, LV_FLEX_ALIGN_SPACE_BETWEEN, LV_FLEX_ALIGN_START, LV_FLEX_ALIGN_CENTER);

    //lv_obj_set_style_border_width(TOP_layout, 2, LV_PART_MAIN); // Set border width
    //lv_obj_set_style_border_color(TOP_layout, lv_palette_main(LV_PALETTE_GREY), LV_PART_MAIN); // Set border color

    create_boxes(TOP_layout);
    create_central_layout(TOP_layout);
}
