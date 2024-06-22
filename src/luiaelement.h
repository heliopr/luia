#ifndef LUIA_ELEMENT_H
#define LUIA_ELEMENT_H

#include <SDL2/SDL.h>
#include <stdint.h>
#include <stdbool.h>

#include "vector2.h"

typedef enum luia_etype
{
    ELEMENT_NONE,
    ELEMENT_ROOT,
    ELEMENT_GROUP,
    ELEMENT_TEXT_LABEL,
    ELEMENT_FRAME
} luia_etype;

typedef struct luia_element
{
    uint16_t id;
    luia_etype type;
    char name[64];
    vector2 position_px, position_rel, anchor, size_px, size_rel;
    vector2 rendering_pos, rendering_size;
    bool visible;
    int render_index;
    struct luia_element *parent;
    struct luia_element **children;
    uint16_t children_count;
    uint16_t children_allocated;
    int child_index;
    void *data;
} luia_element;


luia_element *luia_element_new(const char *name);
void luia_element_add_child(luia_element *parent, luia_element *child);
void luia_element_unparent(luia_element *e);
void luia_element_destroy(luia_element *e);
void luia_element_render(luia_element *e, SDL_Renderer *renderer, vector2 abs_pos, vector2 abs_size);
int luia_element_sort_comp(const void *p1, const void *p2);

#endif