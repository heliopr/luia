#ifndef LUIA_RENDERING_H
#define LUIA_RENDERING_H

#include <stdbool.h>
#include <stdint.h>
#include <SDL2/SDL.h>

#include "rgba.h"

bool luia_load_fonts();
void luia_close_fonts();
void luia_calculate_text_wh(uint8_t size, size_t character_count, uint16_t *w, uint16_t *h);
void luia_render_text(SDL_Renderer *renderer, const char *text, rgba color, int x, int y, uint8_t size);
void luia_render_box(SDL_Renderer *renderer, int x, int y, int w, int h, rgba color);

#endif