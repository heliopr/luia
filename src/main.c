#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#include "luia.h"

uint32_t last_t = 0;

// LEMBRAR DE ARRUMAR AQUILO LA

int main() {
    if (!luia_init()) {
        fprintf(stderr, "An error occurred when trying to init' luia\n");
        return 1;
    }
    
    luia_window *w = luia_window_new(800, 600, "Windooooooow");
    w->background_color = (rgba){230, 230, 230};
    luia_window_show(w);

    luia_group *g = luia_group_new("grupo");
    luia_window_add_element(w, g->element);

    luia_textlabel *t = luia_textlabel_new("lbl");
    t->element->anchor = (vector2) {0.5, 0.5};
    t->element->position_px = (vector2) {0, 0};
    t->element->position_rel = (vector2) {0.5, 0.5};
    t->element->size_px = (vector2) {0, 0};
    t->element->size_rel = (vector2) {0.7, 0.4};
    t->text_x_alignment = X_LEFT;
    t->text_y_alignment = Y_MIDDLE;
    t->text_size = 14;
    t->clip_text = true;
    t->wrap_text = true;
    t->border_color = (rgba){0, 0, 0, 0};
    t->border_thickness = 5;
    t->background_color = (rgba){255, 0, 0, 255};
    strcpy(t->text, "Lorem ipsum dolor sit amet, consectetur adipiscing elit. Nullam et turpis et quam sagittis interdum faucibus vel turpis. Vestibulum vitae maximus nibh. Quisque quam purus, tincidunt eu pellentesque sed, luctus vitae lacus. In hac habitasse platea dictumst. Aenean id nibh commodo, ultricies dolor eu, facilisis ligula. Aenean suscipit, magna sed semper porttitor, dolor magna venenatis orci, volutpat fringilla enim erat ut eros. Vestibulum feugiat justo eu orci sodales, sed porttitor erat vestibulum. Quisque aliquet varius sem, in laoreet ligula efficitur ut. Quisque congue erat ut libero consectetur ultricies. Nam pretium interdum massa. Phasellus congue lorem id semper consequat. Etiam sodales tortor ipsum, vel eleifend nisl finibus vel. Cras ultrices eu magna gravida accumsan.");

    //luia_window_add_element(w, t->element);
    luia_element_add_child(g->element, t->element);

    luia_frame *frame = luia_frame_new("FRAMEZINHO");
    frame->element->size_rel = (vector2){1, 0.1};
    frame->background_color = (rgba){0, 255, 0, 255};
    luia_window_add_element(w, frame->element);

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