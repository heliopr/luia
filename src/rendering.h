#ifndef LUIA_RENDERING_H
#define LUIA_RENDERING_H

#include <stdbool.h>
#include <stdint.h>
#include <SDL2/SDL.h>

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
void luia_render_border(SDL_Renderer *renderer, int x, int y, int w, int h, int thickness, rgba color);
void luia_render_text(SDL_Renderer *renderer, const char *text, rgba color, int x, int y, uint8_t size);
void luia_render_box(SDL_Renderer *renderer, int x, int y, int w, int h, rgba color);

#endif