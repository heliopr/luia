#include <stdbool.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>

#include "rendering.h"

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

void luia_quit() {
    luia_close_fonts();
    luia_quit_sdl();
}