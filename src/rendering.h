#ifndef LUIA_RENDERING_H
#define LUIA_RENDERING_H

#define LUIA_FONT_SIZEPX 16

#include <stdbool.h>
#include <stdint.h>
#include <SDL2/SDL.h>

#include "rgba.h"

bool luia_load_fonts();
void luia_close_fonts();
void luia_render_text(SDL_Renderer *renderer, const char *text, rgba color, uint16_t x, uint16_t y, uint8_t size);

#endif