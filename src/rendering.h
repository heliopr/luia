#ifndef LUIA_RENDERING_H
#define LUIA_RENDERING_H

#include <stdint.h>
#include <SDL2/SDL.h>

#include "rgba.h"

void luia_render_text(SDL_Renderer *renderer, const char *text, rgba color, uint16_t x, uint16_t y, uint8_t size);

#endif