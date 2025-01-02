#include "general_layout.h"

void create_general_layout(void)
{
    lv_obj_t* parent = lv_scr_act();

    lv_obj_t* general_layout = lv_obj_create(parent);

    // Hacer transparente el general_layout
    lv_obj_set_size(general_layout, H_SIZE, V_SIZE); // Tamaño: 800x380 píxeles
    lv_obj_set_style_bg_opa(general_layout, LV_OPA_TRANSP, LV_PART_MAIN); // Fondo transparente
    lv_obj_set_style_border_width(general_layout, 0, LV_PART_MAIN);        // Sin bordes
    lv_obj_center(general_layout); // Colocar en el centro del padre
    lv_obj_clear_flag(general_layout, LV_OBJ_FLAG_SCROLLABLE);
    lv_obj_set_style_pad_all(general_layout, 0, LV_PART_MAIN); // No padding
    lv_obj_set_flex_flow(general_layout, LV_FLEX_FLOW_COLUMN); // Arrange items in a column
    lv_obj_set_flex_align(general_layout, LV_FLEX_ALIGN_START, LV_FLEX_ALIGN_START, LV_FLEX_ALIGN_CENTER);
    lv_obj_set_style_pad_row(general_layout, 0, LV_PART_MAIN); // Remove row padding

    //lv_obj_set_style_border_width(general_layout, 2, LV_PART_MAIN); // Set border width
    //lv_obj_set_style_border_color(general_layout, lv_palette_main(LV_PALETTE_YELLOW), LV_PART_MAIN); // Set border color

    create_TOP_layout(general_layout);
    create_LOW_layout(general_layout);
}
