#ifndef LUIA_ELEMENT_H
#define LUIA_ELEMENT_H

#include <stdint.h>
#include <stdbool.h>

#include "vector2.h"

typedef enum luia_etype {
    NONE,
    ROOT,
    GROUP,
    TEXT_LABEL
} luia_etype;

typedef struct luia_element
{
    uint16_t id;
    luia_etype type;
    char name[64];
    vector2 position_px, position_rel, anchor, size_px, size_rel;
    bool visible;
    struct luia_element *parent;
    struct luia_element **children;
    uint16_t children_count;
    uint16_t children_allocated;
    void *data;
} luia_element;


luia_element *luia_element_new(const char *name);
void luia_element_add_child(luia_element *parent, luia_element *child);
void luia_element_unparent(luia_element *e);
void luia_element_destroy(luia_element *e);
void luia_element_render(luia_element *e, SDL_Renderer *renderer, vector2 abs_pos, vector2 abs_size);

#endif