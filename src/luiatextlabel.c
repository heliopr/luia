#include "rendering.h"
#include "luiatextlabel.h"

luia_textlabel *luia_textlabel_new(const char *name) {
    luia_textlabel *t = malloc(sizeof(luia_textlabel));
    t->text_size = 24;
    t->background_color = (rgba) {255, 255, 255, 255};
    t->text_color = (rgba) {255, 255, 255, 255};
    strcpy(t->text, "");

    luia_element *e = luia_element_new(name);
    e->type = TEXT_LABEL;
    e->data = t;
    t->element = e;
    return t;
}

void luia_textlabel_set_text(luia_textlabel *t, const char *text) {
    strcpy(t->text, text);
}

void luia_textlabel_render(luia_textlabel *t, SDL_Renderer *renderer) {
    luia_element *e = t->element;
    luia_render_box(renderer, e->position_px.x, e->position_px.y, e->size_px.x, e->size_px.y, t->background_color);
}