#include "luiawindow.h"

luia_window *luia_window_new() {
    luia_window *w = malloc(sizeof(luia_window));
    w->width = 0;
    w->height = 0;
    w->resizable = false;
    w->sdl_window = NULL;
    w->sdl_renderer = NULL;
    w->root_element = NULL;
    strcpy(w->title, "");
    return w;
}

luia_window *luia_window_create(uint16_t width, uint16_t height, const char *title) {
    luia_window *w = luia_window_new();
    w->width = width;
    w->height = height;
    strcpy(w->title, title);

    w->root_element = luia_element_new();
    w->root_element->type = GROUP;
    strcpy(w->root_element->name, "root");
    return w;
}

void luia_window_show(luia_window *w) {
    if (w->resizable) {
        w->sdl_window = SDL_CreateWindow(w->title, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, w->width, w->height, SDL_WINDOW_RESIZABLE);
    }
    else {
        w->sdl_window = SDL_CreateWindow(w->title, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, w->width, w->height, SDL_WINDOW_SHOWN);
    }

    w->sdl_renderer = SDL_CreateRenderer(w->sdl_window, -1, 0);
}

void luia_window_add_element(luia_window *w, luia_element *e) {
    luia_element_add_child(w->root_element, e);
}