#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "luiaelement.h"

uint32_t element_id_count = 0;

luia_element *luia_element_new() {
    luia_element *e = malloc(sizeof(luia_element));
    e->parent = NULL;
    e->children = NULL;
    e->children_count = 0;
    e->children_allocated = 0;
    e->data = NULL;
    e->type = NONE;
    e->visible = false;
    e->id = element_id_count++;
    strcpy(e->name, "");
    return e;
}

void luia_element_add_child(luia_element *parent, luia_element *child) {
    if (child->parent != NULL) return;

    if (parent->children_count == parent->children_allocated) {
        if (parent->children_allocated == 0) parent->children_allocated++;
        parent->children_allocated *= 2;
        parent->children = realloc(parent->children, parent->children_allocated);
    }

    child->parent = parent;
    parent->children[parent->children_count] = child;
    parent->children_count++;
}

void luia_element_unparent(luia_element *e) {
    if (e->parent == NULL) return;

    luia_element *parent = e->parent;

    int index = -1;
    for (int i = 0; i < parent->children_count; i++) {
        luia_element *f = parent->children[i];
        if (f == e) {
            index = i;
            break;
        }
    }

    if (index == -1) {
        e->parent = NULL;
        fprintf(stderr, "Could not unparent element with id %d\n", e->id);
        return;
    }

    for (int i = index+1; i < parent->children_count; i++)
        parent->children[i-1] = parent->children[i];

    e->parent = NULL;
    parent->children_count--;
}

// UNTESTED
void luia_element_destroy(luia_element *e) {
    luia_element_unparent(e);

    while (e->children_count > 0) {
        luia_element_destroy(e->children[0]);
    }

    free(e->children);
    free(e->data);
    free(e);
}