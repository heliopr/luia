#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#include "luiawindow.h"
#include "luiaelement.h"
#include "luiatextlabel.h"
#include "rendering.h"
#include "luia.h"

uint32_t last_t = 0;

int main() {
    if (!luia_init()) {
        fprintf(stderr, "An error occurred when trying to init' luia\n");
        return 1;
    }

    luia_window *w = luia_window_new(320, 200, "JANELINHA");
    luia_window_show(w);

    luia_textlabel *t = luia_textlabel_new("lbl");
    t->element->position_px = (vector2) {10, 20};
    t->element->size_px = (vector2) {100, 60};

    SDL_Event e;

    while (1) {
        uint32_t remaining = (1000/20) - (last_t - SDL_GetTicks());
        if (remaining > 0) SDL_Delay(remaining);

        if (SDL_PollEvent(&e)) {
            if (e.type == SDL_QUIT) {
                break;
            }
        }

        SDL_SetRenderDrawColor(w->sdl_renderer, 30, 30, 30, 255);
        SDL_RenderClear(w->sdl_renderer);

        luia_textlabel_render(t, w->sdl_renderer);

        /*uint8_t size = 24;
        uint16_t wi = (uint16_t)ceil(((double)size/120)*72) * 18, h = (uint16_t)ceil(((double)size/120)*136);
        printf("a %d %d\n", wi, h);
        SDL_Rect r = {10, 10, wi, h};
        SDL_SetRenderDrawColor(w->sdl_renderer, 255, 200, 200, 255);
        SDL_RenderFillRect(w->sdl_renderer, &r);

        luia_render_text(w->sdl_renderer, "A12b3io12nbum-08BH", (rgba){255, 255, 255, 255}, 10, 10, size);
        //luia_render_text(w->sdl_renderer, "JIKLMNOPQRSTUVJK1HAH", (rgba){255, 255, 255, 255}, 10, 30, 10);*/

        SDL_RenderPresent(w->sdl_renderer);

        last_t = SDL_GetTicks();
    }

    luia_quit();
}