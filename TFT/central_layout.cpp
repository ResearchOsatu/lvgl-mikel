#include "central_layout.h"

void create_central_layout(lv_obj_t* container)
{
    lv_obj_t* central_layout = lv_obj_create(container);

    lv_obj_set_size(central_layout, 600, 380); // Tamaño: 800x380 píxeles
    lv_obj_set_pos(central_layout, 0, 0);      // Posición en la parte superior del contenedor
    lv_obj_set_style_bg_opa(central_layout, LV_OPA_TRANSP, LV_PART_MAIN); // Hacerlo transparente
    lv_obj_set_style_border_width(central_layout, 0, LV_PART_MAIN);       // Sin bordes
    lv_obj_clear_flag(central_layout, LV_OBJ_FLAG_SCROLLABLE);
    lv_obj_set_style_pad_all(central_layout, 0, LV_PART_MAIN); // No padding
    lv_obj_set_flex_flow(central_layout, LV_FLEX_FLOW_COLUMN); // Arrange items in a column
    lv_obj_set_flex_align(central_layout, LV_FLEX_ALIGN_START, LV_FLEX_ALIGN_START, LV_FLEX_ALIGN_CENTER);
    lv_obj_set_style_pad_row(central_layout, 0, LV_PART_MAIN); // No padding

    //lv_obj_set_style_border_width(TOP_layout, 2, LV_PART_MAIN); // Set border width
    //lv_obj_set_style_border_color(TOP_layout, lv_palette_main(LV_PALETTE_GREY), LV_PART_MAIN); // Set border color

    create_icon_layout(central_layout);
    create_charts_layout(central_layout);
}
