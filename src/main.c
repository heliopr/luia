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
    
    luia_window *w = luia_window_new(800, 600, "Windooooooow");
    w->resizable = true;
    w->background_color = (rgba){230, 230, 230};
    luia_window_show(w);

    luia_textlabel *t = luia_textlabel_new("lbl");
    t->element->anchor = (vector2) {0.5, 0};
    t->element->position_px = (vector2) {0, 0};
    t->element->position_rel = (vector2) {0.5, 0};
    t->element->size_px = (vector2) {0, 0};
    t->element->size_rel = (vector2) {0.6, 0.2};
    t->text_x_alignment = X_MIDDLE;
    t->text_y_alignment = Y_TOP;
    t->text_size = 30;
    t->clip_text = false;
    t->wrap_text = true;
    t->border_color = (rgba){0, 255, 0, 50};
    strcpy(t->text, "TEXT label testttt]]");

    luia_window_add_element(w, t->element);

    luia_textlabel *t2 = luia_textlabel_new("lbl2");
    t2->element->position_px = (vector2) {-200, 0};
    t2->element->position_rel = (vector2) {1, 0.5};
    t2->element->size_px = (vector2) {100, 100};
    t2->element->size_rel = (vector2) {0, 0};
    t2->element->anchor = (vector2) {1, 0.5};
    t2->background_color = (rgba){255, 0, 0, 255};

    //luia_window_add_element(w, t2->element);

    luia_textlabel *t3 = luia_textlabel_new("lbl2");
    t3->element->position_px = (vector2) {0, 0};
    t3->element->position_rel = (vector2) {0.5, 0.5};
    t3->element->size_px = (vector2) {0, 0};
    t3->element->size_rel = (vector2) {0.8, 0.8};
    t3->element->anchor = (vector2) {0.5, 0.5};
    t3->background_color = (rgba){0, 255, 0, 255};

    //luia_element_add_child(t->element, t3->element);

    /*vector2 size = {100, 100};
    vector2 px = {0, 0};
    vector2 rel = {1, 0};
    vector2 r = vector2_calc_size(size, px, rel);
    printf("%f %f\n", r.x, r.y);*/

    SDL_Event e;

    while (1) {
        uint32_t remaining = (1000/60) - (last_t - SDL_GetTicks());
        if (remaining > 0) SDL_Delay(remaining);

        if (SDL_PollEvent(&e)) {
            if (e.type == SDL_QUIT) {
                break;
            }
        }

        luia_window_render(w);
        //luia_element_render(t->element, w->sdl_renderer, (vector2){0, 0}, (vector2){320, 200});

        /*uint8_t size = 24;
        uint16_t wi = (uint16_t)ceil(((double)size/120)*72) * 18, h = (uint16_t)ceil(((double)size/120)*136);
        printf("a %d %d\n", wi, h);
        SDL_Rect r = {10, 10, wi, h};
        SDL_SetRenderDrawColor(w->sdl_renderer, 255, 200, 200, 255);
        SDL_RenderFillRect(w->sdl_renderer, &r);

        luia_render_text(w->sdl_renderer, "A12b3io12nbum-08BH", (rgba){255, 255, 255, 255}, 10, 10, size);
        //luia_render_text(w->sdl_renderer, "JIKLMNOPQRSTUVJK1HAH", (rgba){255, 255, 255, 255}, 10, 30, 10);*/

        last_t = SDL_GetTicks();
    }

    luia_quit();
}