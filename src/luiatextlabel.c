#include "luiatextlabel.h"

luia_textlabel *luia_textlabel_new() {
    luia_textlabel *t = malloc(sizeof(luia_textlabel));
    t->element = NULL;
    t->background_color = (rgba) {0, 0, 0, 0};
    t->text_color = (rgba) {0, 0, 0, 0};
    strcpy(t->text, "");
    return t;
}

luia_textlabel *luia_textlabel_create(const char *name) {
    luia_textlabel *t = luia_textlabel_new();
    strcpy(t->element->name, name);
    return t;
}

void luia_textlabel_set_text(luia_textlabel *t, const char *text) {
    strcpy(t->text, text);
}