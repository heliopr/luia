#include "luiatextlabel.h"

luia_textlabel *luia_textlabel_new() {
    luia_textlabel *t = malloc(sizeof(luia_textlabel));
    t->element = NULL;
    t->background_color = (rgba) {255, 255, 255, 255};
    t->text_color = (rgba) {255, 255, 255, 255};
    strcpy(t->text, "");
    return t;
}

luia_textlabel *luia_textlabel_create(const char *name) {
    luia_textlabel *t = luia_textlabel_new();
    luia_element *e = luia_element_new();
    e->data = t;
    e->type = TEXT_LABEL;
    t->element = e;
    strcpy(e->name, name);
    return t;
}

void luia_textlabel_set_text(luia_textlabel *t, const char *text) {
    strcpy(t->text, text);
}