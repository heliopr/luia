#ifndef LUIA_H
#define LUIA_H

#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include "rendering.h"
#include "SDL2/SDL.h"
#include "luiagroup.h"
#include "luiawindow.h"
#include "luiaelement.h"
#include "luiatextlabel.h"
#include "luiaframe.h"
#include "vector2.h"
#include "rgba.h"

bool luia_init_sdl();
bool luia_init();
void luia_quit_sdl();
void luia_quit();

#endif