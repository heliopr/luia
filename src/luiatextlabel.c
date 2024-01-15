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

void luia_textlabel_render(luia_textlabel *t, SDL_Renderer *renderer, vector2 abs_pos, vector2 abs_size) {
    luia_element *e = t->element;
    vector2 element_pos = vector2_calc_pos(abs_pos, abs_size, e->position_px, e->position_rel);
    vector2 element_size = vector2_calc_size(abs_size, e->size_px, e->size_rel);
    printf("VVV %f %f\n%f %f\n", element_pos.x, element_pos.y, element_size.x, element_size.y);
    luia_render_box(renderer, element_pos.x, element_pos.y, element_size.x, element_size.y, t->background_color);
}