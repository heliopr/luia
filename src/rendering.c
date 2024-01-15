#include <SDL2/SDL_ttf.h>

#include "rendering.h"

char font_patterns[128][LUIA_FONT_SIZEPX][LUIA_FONT_SIZEPX] = {
    ['a'] = {
        {0,0,0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0,0,0},
    }
};

TTF_Font *fonts[256];

bool luia_load_fonts() {
    for (int i = 0; i < 256; i++) {
        fonts[i] = TTF_OpenFont("fonts/arial.ttf", i);

        if (!fonts[i]) {
            fprintf(stderr, "Error: could not load font arial.ttf (size %d)\n%s\n", i, TTF_GetError());
            return false;
        }
    }
    return true;
}

void luia_close_fonts() {
    for (int i = 0; i < 256; i++) {
        TTF_CloseFont(fonts[i]);
    }
}

void luia_render_text(SDL_Renderer *renderer, const char *text, rgba color, uint16_t x, uint16_t y, uint8_t size) {
    SDL_Surface *surface = TTF_RenderText_Solid(fonts[size], text, (SDL_Color) {color.r, color.g, color.b, color.a});
    SDL_Texture *texture = SDL_CreateTextureFromSurface(renderer, surface);

    int w = 0;
    int h = 0;
    SDL_QueryTexture(texture, NULL, NULL, &w, &h);
    SDL_Rect dstrect = {x, y, w, h};

    SDL_RenderCopy(renderer, texture, NULL, &dstrect);

    SDL_DestroyTexture(texture);
    SDL_FreeSurface(surface);
}