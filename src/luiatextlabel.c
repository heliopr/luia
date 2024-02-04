#include "rendering.h"
#include "luiatextlabel.h"

luia_textlabel *luia_textlabel_new(const char *name) {
    luia_textlabel *t = malloc(sizeof(luia_textlabel));
    t->text_size = 18;
    t->background_color = (rgba) {0, 0, 0, 0};
    t->border_color = (rgba) {0, 0, 0, 0};
    t->border_thickness = 0;
    t->corner_radius = 0;
    t->text_color = (rgba) {20, 20, 20, 255};
    t->text_x_alignment = X_MIDDLE;
    t->text_y_alignment = Y_MIDDLE;
    t->clip_text = true;
    t->wrap_text = false;
    strcpy(t->text, "");

    luia_element *e = luia_element_new(name);
    e->type = ELEMENT_TEXT_LABEL;
    e->data = t;
    t->element = e;
    return t;
}

void luia_textlabel_render(luia_textlabel *t, SDL_Renderer *renderer, vector2 pos, vector2 size) {
    luia_render_rectangle(renderer, pos, size, t->background_color, t->border_color, t->border_thickness, t->corner_radius);
    luia_render_text(renderer, pos, size, t->text, t->text_size, t->text_color, t->text_x_alignment, t->text_y_alignment, t->wrap_text, t->clip_text);


    /*if (t->background_color.a > 0) {
        if (t->corner_radius > 0) {
            luia_render_rounded_box(renderer, pos.x, pos.y, size.x, size.y, t->corner_radius, t->background_color);
        }
        else {
            luia_render_box(renderer, pos.x, pos.y, size.x, size.y, t->background_color);
        }
    }

    if (t->border_color.a > 0 && t->border_thickness > 0) luia_render_border(renderer, pos.x, pos.y, size.x, size.y, t->border_thickness, t->border_color);*/

    /*size_t txt_len = strlen(t->text);
    if (txt_len == 0) return;

    if (t->wrap_text) {
        luia_render_wrap_text(renderer, t->text, pos.x, pos.y, size.x, size.y, t->text_x_alignment, t->text_y_alignment, t->text_size, t->text_color, t->clip_text);
    }
    else {
        uint16_t w, h;
        luia_calc_text_wh(t->text_size, txt_len, &w, &h);
        vector2 text_pos = luia_calc_alignment(pos, size, w, h, t->text_x_alignment, t->text_y_alignment);

        if (t->clip_text) {
            SDL_Rect clip_rect = {pos.x, pos.y, size.x, size.y};
            SDL_RenderSetClipRect(renderer, &clip_rect);
        }

        luia_render_text(renderer, t->text, t->text_color, text_pos.x, text_pos.y, t->text_size);

        if (t->clip_text) SDL_RenderSetClipRect(renderer, NULL);
    }*/
}