#include <stdlib.h>

#include "rendering.h"
#include "luiaframe.h"

luia_frame *luia_frame_new(const char *name) {
    luia_frame *f = malloc(sizeof(luia_frame));
    f->background_color = (rgba) {0, 0, 0, 0};
    f->border_color = (rgba) {0, 0, 0, 0};
    f->border_thickness = 0;
    f->corner_radius = 0;

    luia_element *e = luia_element_new(name);
    e->type = ELEMENT_FRAME;
    e->data = f;
    f->element = e;

    return f;
}

void luia_frame_render(luia_frame *f, SDL_Renderer *renderer, vector2 pos, vector2 size) {
    luia_render_rectangle(renderer, pos, size, f->background_color, f->border_color, f->border_thickness, f->corner_radius);
}