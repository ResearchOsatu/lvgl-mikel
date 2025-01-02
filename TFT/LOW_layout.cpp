#include "LOW_layout.h"
#include "rsc/texts.h"
#include "buttons.h"

void create_LOW_layout(lv_obj_t* container)
{
    lv_obj_t* LOW_layout = lv_obj_create(container);

    lv_obj_set_size(LOW_layout, 800, 100); // Tamaño: lo que reste, por ejemplo, 800x100
    lv_obj_set_pos(LOW_layout, 0, 380);    // Posición justo debajo de TOP_layout
    lv_obj_set_style_bg_opa(LOW_layout, LV_OPA_TRANSP, LV_PART_MAIN); // Hacerlo transparente
    lv_obj_set_style_border_width(LOW_layout, 0, LV_PART_MAIN);       // Sin bordes
    lv_obj_clear_flag(LOW_layout, LV_OBJ_FLAG_SCROLLABLE);
    lv_obj_set_style_pad_all(LOW_layout, 0, LV_PART_MAIN); // No padding
    lv_obj_set_flex_flow(LOW_layout, LV_FLEX_FLOW_COLUMN); // Arrange items in a column
    lv_obj_set_flex_align(LOW_layout, LV_FLEX_ALIGN_START, LV_FLEX_ALIGN_START, LV_FLEX_ALIGN_CENTER);
    lv_obj_set_style_pad_row(LOW_layout, 0, LV_PART_MAIN); // Remove row padding

    //lv_obj_set_style_border_width(LOW_layout, 2, LV_PART_MAIN); // Set border width
    //lv_obj_set_style_border_color(LOW_layout, lv_palette_main(LV_PALETTE_PURPLE), LV_PART_MAIN); // Set border color

    create_message_box(LOW_layout);
    message_set(get_translation(ETXT_SHOCK_ADVISED));
    message_Blink();

    create_buttons(LOW_layout);
}
