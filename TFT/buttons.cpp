#include "buttons.h"
#include "rsc/texts.h"

void create_buttons(lv_obj_t* container)
{
    // Create the principal box
    buttons = lv_obj_create(container);
    lv_obj_set_size(buttons, BUTTONS_H_SIZE, BUTTONS_V_SIZE); // Set the size of the box
    lv_obj_set_style_bg_color(buttons, lv_palette_main(LV_PALETTE_NONE), LV_PART_MAIN); // Set backgorund color
    lv_obj_set_style_border_width(buttons, 0, LV_PART_MAIN); // Set border width
    lv_obj_set_style_radius(buttons, 0, LV_PART_MAIN); // Rounded corners
    lv_obj_clear_flag(buttons, LV_OBJ_FLAG_SCROLLABLE);
    lv_obj_set_flex_flow(buttons, LV_FLEX_FLOW_ROW); // Arrange items in a column
    lv_obj_set_flex_align(buttons, LV_FLEX_ALIGN_SPACE_BETWEEN, LV_FLEX_ALIGN_START, LV_FLEX_ALIGN_CENTER);
    lv_obj_set_style_pad_all(buttons, 0, LV_PART_MAIN); // No padding

    //Position the box
    lv_obj_align(buttons, LV_ALIGN_TOP_LEFT, 0, 0);

    static lv_style_t buttons_style;
    lv_style_init(&buttons_style);
    lv_style_set_text_font(&buttons_style, &lv_font_montserrat_20); // Use a larger font

    // Create a label for numbers inside the box
    for (int i = 0; i < BUTTONS_N; i++)
    {
        button[i] = lv_btn_create(buttons);
        lv_obj_set_size(button[i], BUTTON_H_SIZE, BUTTONS_V_SIZE); // Set the size of the box
        lv_obj_set_style_border_width(button[i], 0, LV_PART_MAIN); // Set border width
        lv_obj_set_style_bg_color(button[i], lv_palette_main(LV_PALETTE_BLUE), LV_PART_MAIN); // Set backgorund color
        lv_obj_clear_flag(button[i], LV_OBJ_FLAG_SCROLLABLE);
        lv_obj_set_style_pad_all(button[i], 0, LV_PART_MAIN); // No padding
        //lv_obj_align(button[i], LV_ALIGN_TOP_LEFT, 0, 0);

        buttons_label[i] = lv_label_create(button[i]);
        lv_obj_set_user_data(buttons_label[i], (void*)button_id);
        lv_obj_set_style_text_color(buttons_label[i], lv_palette_main(LV_PALETTE_DEEP_ORANGE), LV_PART_MAIN);
        lv_obj_add_style(buttons_label[i], &buttons_style, 0);
        lv_label_set_text(buttons_label[i], get_translation(ETXT_BUTTON)); // Set the number text
        lv_obj_align(buttons_label[i], LV_ALIGN_CENTER, 0, 0);

        // Add an event callback for the button
        lv_obj_add_event_cb(button[i], button_event_cb, LV_EVENT_CLICKED, buttons_label[i]); // Pass label as user data
    }
}

void button_set(int button, const char* text)
{
    lv_label_set_text(buttons_label[button], text); // Set the number text
}

char* button_get(int button)
{
    return lv_label_get_text(buttons_label[button]); // Set the number text
}

static void button_event_cb(lv_event_t* e) {
    lv_obj_t* pulsed_label = (lv_obj_t *)lv_event_get_user_data(e); // Retrieve user data (if any)

    int* retrieved_data = (int*)lv_obj_get_user_data(pulsed_label);

    // Handle the event
    if (lv_event_get_code(e) == LV_EVENT_CLICKED) {
        lv_label_set_text(pulsed_label, get_translation(ETXT_CLICKED)); // Update label text
    }
}
