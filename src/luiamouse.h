#ifndef LUIA_MOUSE_H
#define LUIA_MOUSE_H

#include <SDL2/SDL.h>

typedef enum luia_mousebutton {
    LUIA_MOUSE_UNKNOWN,
    LUIA_MOUSE_LEFT,
    LUIA_MOUSE_MIDDLE,
    LUIA_MOUSE_RIGHT,
    LUIA_MOUSE_X1,
    LUIA_MOUSE_X2
} luia_mousebutton;

luia_mousebutton luia_sdlmouse_map(uint8_t b);

#endif