#include "luiawindow.h"
#include "rendering.h"
#include "luiacore.h"

luia_window *luia_window_new(uint16_t width, uint16_t height, const char *title) {
    luia_window *w = malloc(sizeof(luia_window));
    w->width = width;
    w->height = height;
    w->resizable = true;
    w->quit_on_close = false;
    w->visible = false;
    w->sdl_window = SDL_CreateWindow(title, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, w->width, w->height, SDL_WINDOW_HIDDEN | SDL_WINDOW_RESIZABLE);
    w->sdl_renderer = SDL_CreateRenderer(w->sdl_window, -1, 0);
    SDL_SetRenderDrawBlendMode(w->sdl_renderer, SDL_BLENDMODE_BLEND);
    w->background_color = (rgba){0, 0, 0, 255};
    strcpy(w->title, title);

    w->root_element = luia_element_new("root");
    w->root_element->type = ELEMENT_ROOT;

    luia_register_window(w);
    return w;
}

void luia_window_show(luia_window *w) {
    if (!w->visible) {
        SDL_ShowWindow(w->sdl_window);
        w->visible = true;
    }
}

void luia_window_hide(luia_window *w) {
    if (w->visible) {
        SDL_HideWindow(w->sdl_window);
        w->visible = false;
    }
}

void luia_window_focus(luia_window *w) {
    luia_window_show(w);
    SDL_RaiseWindow(w->sdl_window);
}

void luia_window_set_resizable(luia_window *w, bool resizable) {
    w->resizable = resizable;
    SDL_SetWindowResizable(w->sdl_window, resizable);
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
        luia_element *e = root->children[i];
        if (e->visible) {
            luia_element_render(e, renderer, pos, window_size);
        }
    }

    SDL_RenderPresent(w->sdl_renderer);
}

void luia_window_handle_event(luia_window *w, SDL_Event event) {
    if (event.type == SDL_WINDOWEVENT && event.window.event == SDL_WINDOWEVENT_CLOSE) {
        if (luia_get_window_count() == 1 || w->quit_on_close) {
            luia_set_is_running(false);
        }
        else {
            luia_window_destroy(w);
        }
    }
}

void luia_window_destroy(luia_window *w) {
    luia_unregister_window(w);
    SDL_DestroyRenderer(w->sdl_renderer);
    SDL_DestroyWindow(w->sdl_window);
    //free(w->title);
    free(w);
}