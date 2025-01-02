#include "audios.h"

void play_audio(void)
{
#if defined(__linux__)
    //lv_img_set_src(img[img_id], "images/lvgl_logo.png");  // Set the file path
#else
    PlaySound(TEXT("C:/Users/miel_/Documents/GitHub/LVGL/TFT/rsc/audios/Grabación.wav"), NULL, SND_FILENAME | SND_ASYNC);
#endif
}