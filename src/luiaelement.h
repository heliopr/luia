#ifndef LUIA_ELEMENT_H
#define LUIA_ELEMENT_H

#include <stdint.h>
#include <stdbool.h>

typedef enum luia_etype {
    NONE,
    GROUP,
    TEXT_LABEL
} luia_etype;

typedef struct luia_element
{
    uint16_t id;
    luia_etype type;
    char name[64];
    bool visible;
    struct luia_element *parent;
    struct luia_element **children;
    uint16_t children_count;
    uint16_t children_allocated;
    void *data;
} luia_element;


luia_element *luia_element_new();
void luia_element_add_child(luia_element *parent, luia_element *child);
void luia_element_unparent(luia_element *e);
void luia_element_destroy(luia_element *e);

#endif