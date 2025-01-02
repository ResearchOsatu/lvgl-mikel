#include "R500_lvgl_interface.h"
#include "rsc/texts.h"
#include "rsc/audios.h"

void R500_lvgl_interface_app(void)
{
    lv_lang_set(LANG_EN);

    set_background_black();

    create_general_layout();

    play_audio();
}

void set_background_black(void) {
    // Crea un estilo
    static lv_style_t style_bg;
    lv_style_init(&style_bg);

    // Establece el color de fondo a negro
    lv_style_set_bg_color(&style_bg, lv_color_black());
    lv_style_set_bg_opa(&style_bg, LV_OPA_COVER); // Opacidad completa

    // Aplica el estilo a la pantalla activa
    lv_obj_t* scr = lv_scr_act(); // Obtiene la pantalla activa
    lv_obj_add_style(scr, &style_bg, LV_PART_MAIN | LV_STATE_DEFAULT);
}
