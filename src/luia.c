#include <stdbool.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>

bool luia_init_sdl() {
    if (SDL_Init(SDL_INIT_EVERYTHING) != 0)
        return false;
    TTF_Init();
    return true;
}

bool luia_init() {
    return luia_init_sdl();
}


void luia_quit_sdl() {
    TTF_Quit();
    SDL_Quit();
}

void luia_quit() {
    luia_quit_sdl();
}