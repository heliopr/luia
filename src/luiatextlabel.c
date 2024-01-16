#include "rendering.h"
#include "luiatextlabel.h"

luia_textlabel *luia_textlabel_new(const char *name) {
    luia_textlabel *t = malloc(sizeof(luia_textlabel));
    t->text_size = 24;
    t->background_color = (rgba) {255, 255, 255, 255};
    t->text_color = (rgba) {0, 0, 0, 255};
    t->text_x_alignment = MIDDLE;
    t->text_y_alignment = MIDDLE;
    strcpy(t->text, "");

    luia_element *e = luia_element_new(name);
    e->type = TEXT_LABEL;
    e->data = t;
    t->element = e;
    return t;
}

void luia_textlabel_render(luia_textlabel *t, SDL_Renderer *renderer, vector2 pos, vector2 size) {
    luia_render_box(renderer, pos.x, pos.y, size.x, size.y, t->background_color);
    luia_render_text(renderer, t->text, t->text_color, pos.x, pos.y, t->text_size);
}