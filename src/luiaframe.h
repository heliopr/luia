#ifndef LUIA_FRAME_H
#define LUIA_FRAME_H

#include <SDL2/SDL.h>

#include  "luiaelement.h"
#include "rgba.h"

typedef struct luia_frame
{
    luia_element *element;
    rgba background_color;
    rgba border_color;
    int border_thickness;
    int corner_radius;
} luia_frame;


luia_frame *luia_frame_new(const char *name);
void luia_frame_render(luia_frame *f, SDL_Renderer *renderer, vector2 pos, vector2 size);

#endif