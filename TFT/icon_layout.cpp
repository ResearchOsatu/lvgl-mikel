#include "icon_layout.h"
#include "rsc/images.h"

void create_icon_layout(lv_obj_t* container)
{
    lv_obj_t* icon_layout = lv_obj_create(container);

    lv_obj_set_size(icon_layout, 600, 50); // Tamaño: 800x380 píxeles
    lv_obj_set_pos(icon_layout, 0, 0);      // Posición en la parte superior del contenedor
    lv_obj_set_style_bg_opa(icon_layout, LV_OPA_TRANSP, LV_PART_MAIN); // Hacerlo transparente
    lv_obj_set_style_border_width(icon_layout, 0, LV_PART_MAIN);       // Sin bordes
    lv_obj_clear_flag(icon_layout, LV_OBJ_FLAG_SCROLLABLE);
    lv_obj_set_style_pad_all(icon_layout, 0, LV_PART_MAIN); // No padding
    lv_obj_set_flex_flow(icon_layout, LV_FLEX_FLOW_ROW); // Arrange items in a column
    lv_obj_set_flex_align(icon_layout, LV_FLEX_ALIGN_START, LV_FLEX_ALIGN_START, LV_FLEX_ALIGN_CENTER);
    lv_obj_set_style_pad_row(icon_layout, 0, LV_PART_MAIN); // Remove row padding

    //lv_obj_set_style_border_width(TOP_layout, 2, LV_PART_MAIN); // Set border width
    //lv_obj_set_style_border_color(TOP_layout, lv_palette_main(LV_PALETTE_GREY), LV_PART_MAIN); // Set border color

    create_time_layout(icon_layout);
    create_icon(icon_layout, 0);
    create_icon(icon_layout, 1);
    create_icon(icon_layout, 2);
    create_icon(icon_layout, 3);
    create_icon(icon_layout, 4);

    hide_icon(2);
}
