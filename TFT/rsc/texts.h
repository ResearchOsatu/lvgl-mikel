#include "lvgl/lvgl.h"

#ifndef TEXTS_H
#define TEXTS_H

enum texts {
    ETXT_BUTTON = 0,
    ETXT_SHOCK_ADVISED,
    ETXT_CLICKED,
    ETXT_MAX
};

enum langs {
    LANG_EN = 0,
    LANG_ES,
    LANG_FR,
    LANG_MAX
};

// Structure to hold translations for different languages
typedef struct {
    const char* en;
    const char* es;
    const char* fr;
} translation_t;

// Create an array of translations
static translation_t translations[LANG_MAX] = {
    {"BUTTON", "BOTON", "BOTONIER"},
    {"SHOCK ADVISED", "DESCARGA ACONSEJADA", "RECOMENDIERAS"},
    {"CLICKED!", "PULSADO!", "PULSIER!" }
};

static int selected_lang = LANG_EN;

const char* get_translation(int index);
int* lv_lang_get(void);
void lv_lang_set(int new_lang);

#endif