#include "rendering.h"
#include "luiatextlabel.h"

luia_textlabel *luia_textlabel_new(const char *name) {
    luia_textlabel *t = malloc(sizeof(luia_textlabel));
    t->text_size = 18;
    t->background_color = (rgba) {225, 225, 225, 255};
    t->border_color = (rgba) {20, 20, 20, 255};
    t->border_thickness = 1;
    t->text_color = (rgba) {20, 20, 20, 255};
    t->text_x_alignment = X_MIDDLE;
    t->text_y_alignment = Y_MIDDLE;
    strcpy(t->text, "");

    luia_element *e = luia_element_new(name);
    e->type = TEXT_LABEL;
    e->data = t;
    t->element = e;
    return t;
}

void luia_textlabel_render(luia_textlabel *t, SDL_Renderer *renderer, vector2 pos, vector2 size) {
    luia_render_box(renderer, pos.x, pos.y, size.x, size.y, t->background_color);
    luia_render_border(renderer, pos.x, pos.y, size.x, size.y, t->border_thickness, t->border_color);

    size_t txt_len = strlen(t->text);
    if (txt_len == 0) return;

    uint16_t w, h;
    luia_calc_text_wh(t->text_size, txt_len, &w, &h);

    pos = luia_calc_alignment(pos, size, w, h, t->text_x_alignment,t->text_y_alignment);
    luia_render_text(renderer, t->text, t->text_color, pos.x, pos.y, t->text_size);
}