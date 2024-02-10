#include "luiamouse.h"

luia_mousebutton luia_sdlmouse_map(uint8_t b) {
    switch (b)
    {
        case SDL_BUTTON_LEFT: return LUIA_MOUSE_LEFT;
        case SDL_BUTTON_MIDDLE: return LUIA_MOUSE_MIDDLE;
        case SDL_BUTTON_RIGHT: return LUIA_MOUSE_RIGHT;
        case SDL_BUTTON_X1: return LUIA_MOUSE_X1;
        case SDL_BUTTON_X2: return LUIA_MOUSE_X2;
        default: return LUIA_MOUSE_UNKNOWN;
    }
    return LUIA_MOUSE_UNKNOWN;
}