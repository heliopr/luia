#include <stdlib.h>

#include "luiagroup.h"

luia_group *luia_group_new(const char *name) {
    luia_group *g = malloc(sizeof(luia_group));

    luia_element *e = luia_element_new(name);
    e->type = ELEMENT_GROUP;
    e->data = g;
    g->element = e;

    return g;
}