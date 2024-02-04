#ifndef LUIA_RENDERING_H
#define LUIA_RENDERING_H

#include <stdbool.h>
#include <stdint.h>
#include <SDL2/SDL.h>

#include "luiatextlabel.h"
#include "luiatextlabel.h"
#include "vector2.h"
#include "rgba.h"

bool luia_load_fonts();
void luia_close_fonts();
void luia_calc_text_wh(uint8_t size, size_t character_count, uint16_t *w, uint16_t *h);
vector2 luia_calc_pos(vector2 pos, vector2 size, vector2 px, vector2 rel);
vector2 luia_calc_size(vector2 size, vector2 px, vector2 rel);
vector2 luia_calc_anchor(vector2 pos, vector2 size, vector2 anchor);
vector2 luia_calc_alignment(vector2 pos, vector2 size, uint16_t w, uint16_t h, luia_x_alignment x, luia_y_alignment y);
/*void render_point(SDL_Renderer *renderer, int x, int y, int size, rgba color);
void render_border(SDL_Renderer *renderer, int x, int y, int w, int h, int thickness, rgba color);
void render_text(SDL_Renderer *renderer, const char *text, rgba color, int x, int y, uint8_t size);
void render_box(SDL_Renderer *renderer, int x, int y, int w, int h, rgba color);
void render_circle(SDL_Renderer *renderer, int x, int y, int radius, rgba color);
void render_rounded_box(SDL_Renderer *renderer, int x, int y, int w, int h, int round_radius, rgba color);
void render_wrap_text(SDL_Renderer *renderer, const char *text, int x, int y, int w, int h, luia_x_alignment x_align, luia_y_alignment y_align, uint16_t size, rgba color, bool clip_text);*/

void luia_render_rectangle(SDL_Renderer *renderer, vector2 pos, vector2 size, rgba background_color, rgba border_color, int border_thickness, int corner_radius);
void luia_render_text(SDL_Renderer *renderer, vector2 pos, vector2 size, const char *text, int text_size, rgba text_color, luia_x_alignment x_alignm, luia_y_alignment y_alignm,
    bool wrap_text, bool clip_text);

#endif