#ifndef LUIA_WINDOW_H
#define LUIA_WINDOW_H

#include <stdint.h>
#include <stdbool.h>
#include <SDL2/SDL.h>

#include "rgba.h"
#include "luiaelement.h"

typedef struct luia_window
{
    int width, height;
    bool resizable;
    char title[128];
    rgba background_color;
    SDL_Window *sdl_window;
    SDL_Renderer *sdl_renderer;
    luia_element *root_element;
} luia_window;

luia_window *luia_window_new(uint16_t width, uint16_t height, const char *title);
void luia_window_show(luia_window *w);
void luia_window_add_element(luia_window *w, luia_element *e);
void luia_window_render(luia_window *w);

#endif