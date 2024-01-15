#include "luiawindow.h"

luia_window *luia_window_new(uint16_t width, uint16_t height, const char *title) {
    luia_window *w = malloc(sizeof(luia_window));
    w->width = width;
    w->height = height;
    w->resizable = false;
    w->sdl_window = NULL;
    w->sdl_renderer = NULL;
    w->background_color = (rgba){0, 0, 0, 255};
    strcpy(w->title, title);

    w->root_element = luia_element_new("root");
    w->root_element->type = ROOT;
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

void luia_window_render(luia_window *w) {
    luia_element *root = w->root_element;
    SDL_Renderer *renderer = w->sdl_renderer;

    rgba color = w->background_color;
    SDL_SetRenderDrawColor(w->sdl_renderer, color.r, color.g, color.b, 255);
    SDL_RenderClear(w->sdl_renderer);

    SDL_GetWindowSizeInPixels(w->sdl_window, &w->width, &w->height);
    vector2 window_size = {w->width, w->height};
    vector2 pos = {0, 0};

    for (int i = 0; i < root->children_count; i++) {
        //printf("rendering %s\n", root->children[i]->name);
        luia_element_render(root->children[i], renderer, pos, window_size);
    }
}