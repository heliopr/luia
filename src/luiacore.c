#include <stdbool.h>

#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>

#include "rendering.h"
#include "luiacore.h"

luia_window *windows[256] = {NULL};
int window_count = 0;
bool is_running = false;
uint32_t last_tick = 0;

bool luia_init_sdl() {
    if (SDL_Init(SDL_INIT_EVERYTHING) != 0) {
        fprintf(stderr, "Error: could not initialize SDL\n%s\n", SDL_GetError());
        return false;
    }
    if (TTF_Init() != 0) {
        fprintf(stderr, "Error: could not initialize SDL_ttf\n%s\n", TTF_GetError());
        return false;
    }
    return true;
}

bool luia_init() {
    return luia_init_sdl() && luia_load_fonts();
}


void luia_quit_sdl() {
    TTF_Quit();
    SDL_Quit();
}

void luia_destroy_windows() {
    while (window_count > 0) {
        luia_window_destroy(windows[0]);
        printf("destrui janela\n");
    }
}

void luia_quit() {
    luia_destroy_windows();
    luia_close_fonts();
    luia_quit_sdl();
}

void handle_events() {
    SDL_Event event;
    while (SDL_PollEvent(&event) > 0) {
        for (int i = 0; i < window_count; i++) {
            luia_window *w = windows[i];
            if (w != NULL && SDL_GetWindowFromID(event.window.windowID) == w->sdl_window) {
                luia_window_handle_event(w, event);
            }
        }
    }
}

void luia_run() {
    if (is_running) return;

    is_running = true;
    while (is_running) {
        uint32_t remaining = (1000/60) - (last_tick - SDL_GetTicks());
        if (remaining > 0) SDL_Delay(remaining);

        handle_events();

        if (!is_running) break;;

        for (int i = 0; i < window_count; i++) {
            luia_window *w = windows[i];
            if (w != NULL) {
                luia_window_render(w);
            }
        }

        last_tick = SDL_GetTicks();
    }
}

bool luia_is_running() {
    return is_running;
}

void luia_set_is_running(bool running) {
    is_running = running;
}

uint8_t luia_get_window_count() {
    return window_count;
}

void luia_register_window(luia_window *w) {
    windows[window_count] = w;
    w->window_index = window_count;
    window_count += 1;
}

void luia_unregister_window(luia_window *w) {
    for (int i = w->window_index+1; i < window_count; i++) {
        windows[i-1] = windows[i];
    }

    windows[window_count-1] = NULL;
    window_count -= 1;
}