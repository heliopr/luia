#include <SDL2/SDL_ttf.h>

#include "rendering.h"

TTF_Font *fonts[256];

bool luia_load_fonts() {
    for (int i = 0; i < 256; i++) {
        fonts[i] = TTF_OpenFont("fonts/arial_mono.ttf", i);

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

void luia_calc_text_wh(uint8_t size, size_t character_count, uint16_t *w, uint16_t *h) {
    if (w != NULL) *w = (uint16_t)ceil(((double)size/120)*72) * character_count;
    if (h != NULL) *h = (uint16_t)ceil(((double)size/120)*136);
}

int next_wrap(const char *s, int i, int goal) {
    int len = strlen(s);
    int j = i, k = i;
    while (j <= len && j <= i+goal) {
        if ((s[j] == '\0' || s[j] == ' ')) {
            if (j > 0 && s[j-1] == ' ') {
                j++;
                continue;
            }
            k = j;
        }
        j++;
    }
    return k;
}

vector2 luia_calc_pos(vector2 pos, vector2 size, vector2 px, vector2 rel) {
    return (vector2){pos.x + px.x + (size.x * rel.x), pos.y + px.y + (size.y * rel.y)};
    //return vector2_sum(pos, vector2_sum(px, (vector2){size.x * rel.x, size.y * rel.y}));
}

vector2 luia_calc_size(vector2 size, vector2 px, vector2 rel) {
    return (vector2){px.x + (size.x*rel.x), px.y + (size.y*rel.y)};
}

vector2 luia_calc_anchor(vector2 pos, vector2 size, vector2 anchor) {
    return (vector2){pos.x - (size.x * anchor.x), pos.y - (size.y * anchor.y)};
}

vector2 luia_calc_alignment(vector2 pos, vector2 size, uint16_t w, uint16_t h, luia_x_alignment x, luia_y_alignment y) {
    vector2 new_pos = {pos.x, pos.y};
    if (x == X_MIDDLE) new_pos.x += (size.x-w)/2;
    else if (x == X_RIGHT) new_pos.x += size.x-w;

    if (y == Y_MIDDLE) new_pos.y += (size.y-h)/2;
    else if (y == Y_BOTTOM) new_pos.y += size.y-h;
    return new_pos;
}

void luia_render_text(SDL_Renderer *renderer, const char *text, rgba color, int x, int y, uint8_t size) {
    SDL_Surface *surface = TTF_RenderText_Solid(fonts[size], text, (SDL_Color) {color.r, color.g, color.b, color.a});
    SDL_Texture *texture = SDL_CreateTextureFromSurface(renderer, surface);

    uint16_t w, h;
    luia_calc_text_wh(size, strlen(text), &w, &h);
    //SDL_QueryTexture(texture, NULL, NULL, &w, &h);
    //printf("b %d %d\n", w, h);
    SDL_Rect dstrect = {x, y, w, h};
    SDL_RenderCopy(renderer, texture, NULL, &dstrect);

    SDL_DestroyTexture(texture);
    SDL_FreeSurface(surface);
}

void luia_render_box(SDL_Renderer *renderer, int x, int y, int w, int h, rgba color) {
    SDL_Rect r = {x, y, w, h};
    SDL_SetRenderDrawColor(renderer, color.r, color.g, color.b, color.a);
    SDL_RenderFillRect(renderer, &r);
}