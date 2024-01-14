#ifndef LUIA_TEXTLABEL_H
#define LUIA_TEXTLABEL_H

#include <SDL2/SDL.h>

#include "rgba.h"
#include "luiaelement.h"

typedef struct luia_textlabel
{
    luia_element *element;
    char text[1024];
    rgba text_color;
    rgba background_color;
} luia_textlabel;

luia_textlabel *luia_textlabel_new();
luia_textlabel *luia_textlabel_create(const char *name);
void luia_textlabel_set_text(luia_textlabel *t, const char *text);
void luia_render_textlabel(luia_textlabel *t, SDL_Renderer *renderer);

#endif