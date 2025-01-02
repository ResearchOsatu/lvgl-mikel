#include "texts.h"

// Function to get translation based on the selected language
const char* get_translation(int index) {
    int* lang = lv_lang_get();  // Get the current language index (0 for English, 1 for Spanish, etc.)

    switch (*lang) {
    case LANG_EN: return translations[index].en;
    case LANG_ES: return translations[index].es;
    case LANG_FR: return translations[index].fr;
    default: return translations[index].en;  // Default to English
    }
}

int* lv_lang_get(void)
{
    return &selected_lang;
}

void lv_lang_set(int new_lang)
{
    selected_lang = new_lang;
}