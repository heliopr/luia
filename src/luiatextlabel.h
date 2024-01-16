#ifndef LUIA_TEXTLABEL_H
#define LUIA_TEXTLABEL_H

#include <SDL2/SDL.h>

#include "rgba.h"
#include "luiaelement.h"

typedef enum luia_x_alignment
{
    X_LEFT,
    X_MIDDLE,
    X_RIGHT
} luia_x_alignment;

typedef enum luia_y_alignment
{
    Y_TOP,
    Y_MIDDLE,
    Y_BOTTOM
} luia_y_alignment;

typedef struct luia_textlabel
{
    luia_element *element;
    char text[1024];
    uint8_t text_size;
    luia_x_alignment text_x_alignment;
    luia_y_alignment text_y_alignment;
    rgba text_color;
    rgba background_color;
} luia_textlabel;

luia_textlabel *luia_textlabel_new(const char *name);
void luia_textlabel_render(luia_textlabel *t, SDL_Renderer *renderer, vector2 pos, vector2 size);

#endif