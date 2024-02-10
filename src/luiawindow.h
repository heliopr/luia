#ifndef LUIA_WINDOW_H
#define LUIA_WINDOW_H

#include <stdint.h>
#include <stdbool.h>
#include <SDL2/SDL.h>

#include "rgba.h"
#include "luiaevent.h"
#include "luiaelement.h"
#include "luiakeyboard.h"
#include "luiamouse.h"

typedef struct luia_window
{
    int width, height;
    bool resizable;
    char title[128];
    rgba background_color;
    bool quit_on_close;
    bool visible;
    int window_index;
    SDL_Window *sdl_window;
    SDL_Renderer *sdl_renderer;
    luia_element *root_element;

    luia_event *key_down_event;
    luia_event *key_up_event;
    luia_event *mouse_down_event;
    luia_event *mouse_up_event;
} luia_window;

typedef struct luia_window_keydown_event
{
    luia_window *window;
    luia_key key;
} luia_window_keydown_event;

typedef struct luia_window_keyup_event
{
    luia_window *window;
    luia_key key;
} luia_window_keyup_event;

typedef struct luia_window_mousedown_event
{
    luia_window *window;
    int x, y;
    luia_mousebutton button;
} luia_window_mousedown_event;

typedef struct luia_window_mouseup_event
{
    luia_window *window;
    int x, y;
    luia_mousebutton button;
} luia_window_mouseup_event;


luia_window *luia_window_new(uint16_t width, uint16_t height, const char *title);
void luia_window_show(luia_window *w);
void luia_window_hide(luia_window *w);
void luia_window_focus(luia_window *w);
void luia_window_set_resizable(luia_window *w, bool resizable);
void luia_window_add_element(luia_window *w, luia_element *e);
void luia_window_render(luia_window *w);
void luia_window_handle_event(luia_window *w, SDL_Event event);
void luia_window_destroy(luia_window *w);

#endif