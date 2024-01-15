#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#include "luiawindow.h"
#include "luiaelement.h"
#include "rendering.h"
#include "luia.h"

uint32_t last_t = 0;

int main() {
    if (!luia_init()) {
        fprintf(stderr, "An error occurred when trying to init luia\n");
        return 1;
    }

    luia_window *w = luia_window_create(300, 200, "JANELINHA");
    luia_window_show(w);

    SDL_Event e;

    while (1) {
        uint32_t remaining = (1000/30) - (last_t - SDL_GetTicks());
        if (remaining > 0) SDL_Delay(remaining);

        if (SDL_PollEvent(&e)) {
            if (e.type == SDL_QUIT) {
                break;
            }
        }

        SDL_SetRenderDrawColor(w->sdl_renderer, 50, 50, 50, 255);
        SDL_RenderClear(w->sdl_renderer);

        luia_render_text(w->sdl_renderer, "OLA MUNDO!", (rgba){255, 255, 255, 255}, 10, 10, 15);

        SDL_RenderPresent(w->sdl_renderer);

        last_t = SDL_GetTicks();
    }

    luia_quit();
}