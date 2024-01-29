#include <SDL2/SDL_ttf.h>

#include "util.h"
#include "rendering.h"

TTF_Font *fonts[256];
int widths[256], heights[256];

bool luia_load_fonts() {
    for (int i = 0; i < 256; i++) {
        TTF_Font *font = TTF_OpenFont("fonts/arial_mono.ttf", i);;

        if (!font) {
            fprintf(stderr, "Error: could not load font arial_mono.ttf (size %d)\n%s\n", i, TTF_GetError());
            return false;
        }

        fonts[i] = font;
        TTF_SizeUTF8(font, "y", &widths[i], &heights[i]);
    }

    return true;
}

void luia_close_fonts() {
    for (int i = 0; i < 256; i++) {
        TTF_CloseFont(fonts[i]);
    }
}

void luia_calc_text_wh(uint8_t size, size_t character_count, uint16_t *w, uint16_t *h) {
    /*if (w != NULL) *w = (uint16_t)ceil(((double)size/120)*72) * character_count;
    if (h != NULL) *h = (uint16_t)ceil(((double)size/120)*136);*/

    if (w != NULL) *w = (uint16_t)widths[size] * character_count;
    if (h != NULL) *h = (uint16_t)heights[size];
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

void luia_render_point(SDL_Renderer *renderer, int x, int y, int size, rgba color) {
    luia_render_box(renderer, x-(size/2), y-(size/2), size, size, color);
}

void luia_render_border(SDL_Renderer *renderer, int x, int y, int w, int h, int thickness, rgba color) {
    SDL_SetRenderDrawColor(renderer, color.r, color.g, color.b, color.a);
    int x2 = x+w;
    int y2 = y+h;
    SDL_RenderFillRect(renderer, &(SDL_Rect){x, y-thickness, w, thickness}); // top
    SDL_RenderFillRect(renderer, &(SDL_Rect){x, y2, w, thickness}); // bottom
    SDL_RenderFillRect(renderer, &(SDL_Rect){x2, y-thickness, thickness, h + thickness*2}); // right
    SDL_RenderFillRect(renderer, &(SDL_Rect){x-thickness, y-thickness, thickness, h + thickness*2}); // left
}

void luia_render_text(SDL_Renderer *renderer, const char *text, rgba color, int x, int y, uint8_t size) {
    SDL_Surface *surface = TTF_RenderUTF8_Blended(fonts[size], text, (SDL_Color) {color.r, color.g, color.b, color.a});
    SDL_Texture *texture = SDL_CreateTextureFromSurface(renderer, surface);

    uint16_t w, h;
    luia_calc_text_wh(size, strlen(text), &w, &h);
    //int sw, sh;
    //TTF_SizeUTF8(fonts[size], text, &sw, &sh);
    //printf("A: %u %u - B: %d %d\n", w, h, sw, sh);
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

void luia_render_circle(SDL_Renderer *renderer, int x, int y, int radius, rgba color) {
    int offsetx, offsety, d;
    int status;

    offsetx = 0;
    offsety = radius;
    d = radius -1;
    status = 0;

    while (offsety >= offsetx) {
        status += SDL_RenderDrawLine(renderer, x - offsety, y + offsetx, x + offsety, y + offsetx);
        status += SDL_RenderDrawLine(renderer, x - offsetx, y + offsety, x + offsetx, y + offsety);
        status += SDL_RenderDrawLine(renderer, x - offsetx, y - offsety, x + offsetx, y - offsety);
        status += SDL_RenderDrawLine(renderer, x - offsety, y - offsetx, x + offsety, y - offsetx);

        if (status < 0) {
            status = -1;
            break;
        }

        if (d >= 2*offsetx) {
            d -= 2*offsetx + 1;
            offsetx +=1;
        }
        else if (d < 2 * (radius - offsety)) {
            d += 2 * offsety - 1;
            offsety -= 1;
        }
        else {
            d += 2 * (offsety - offsetx - 1);
            offsety -= 1;
            offsetx += 1;
        }
    }
}

void luia_render_rounded_box(SDL_Renderer *renderer, int x, int y, int w, int h, int round_radius, rgba color) {
    luia_render_box(renderer, x+round_radius, y, w-(round_radius*2), h, color);
    luia_render_box(renderer, x, y+round_radius, w, h-(round_radius*2), color);
    luia_render_circle(renderer, x+round_radius, y+round_radius, round_radius, color);
    luia_render_circle(renderer, x+w-round_radius-1, y+round_radius, round_radius, color);
    luia_render_circle(renderer, x+round_radius, y+h-round_radius-1, round_radius, color);
    luia_render_circle(renderer, x+w-round_radius-1, y+h-round_radius-1, round_radius, color);
}

// crime
void luia_render_wrap_text(SDL_Renderer *renderer, const char *text, int x, int y, int w, int h, luia_x_alignment x_align, luia_y_alignment y_align, uint16_t size, rgba color, bool clip_text) {
    uint16_t font_w, font_h;
    luia_calc_text_wh(size, 1, &font_w, &font_h);

    int chars_p_line = w/font_w;
    chars_p_line = chars_p_line>0 ? chars_p_line : 1;
    int lines = 0, len = strlen(text);

    {
        int i = 0;
        while (i < len) {
            int j = str_next_wrap(text, i, chars_p_line);
            i = j;
            lines++;
        }
    }

    int pos_y = y;
    if (y_align == Y_BOTTOM) pos_y += h - (font_h*lines);
    else if (y_align == Y_MIDDLE) pos_y += (h - (font_h * lines))/2;

    if (clip_text) {
        SDL_Rect clip_rect = {x, y, w, h};
        SDL_RenderSetClipRect(renderer, &clip_rect);
    }

    int c = 0;
    for (int i = 0; i < lines; i++) {
        int j = str_next_wrap(text, c, chars_p_line);
        char b[1024];
        str_copy(text, c, j, b);
        char b2[1024];
        str_clear_lspaces(b, b2);
        int b2len = strlen(b2);

        int pos_x = x;
        if (x_align == X_RIGHT) pos_x += w - (b2len*font_w);
        else if (x_align == X_MIDDLE) pos_x += (w - (b2len*font_w))/2;
        luia_render_text(renderer, b2, color, pos_x, pos_y, size);
        pos_y += font_h;
        c = j;
    }

    if (clip_text) SDL_RenderSetClipRect(renderer, NULL);
}

