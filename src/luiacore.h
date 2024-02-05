#ifndef LUIA_CORE_H
#define LUIA_CORE_H

#include "luiawindow.h"

bool luia_init_sdl();
bool luia_init();
void luia_quit_sdl();
void luia_destroy_windows();
void luia_quit();
//void luia_handle_events();
void luia_run();
void luia_set_is_running(bool running);
uint8_t luia_get_window_count();
void luia_register_window(luia_window *w);
void luia_unregister_window(luia_window *w);

#endif