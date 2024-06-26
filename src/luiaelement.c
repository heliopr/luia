#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "rendering.h"
#include "luiaframe.h"
#include "luiatextlabel.h"
#include "luiaelement.h"

uint32_t element_id_count = 0;

luia_element *luia_element_new(const char *name) {
    luia_element *e = malloc(sizeof(luia_element));
    e->parent = NULL;
    e->children = NULL;
    e->children_count = 0;
    e->children_allocated = 0;
    e->child_index = -1;
    e->render_index = 0;
    e->rendering_pos = (vector2){0, 0};
    e->rendering_size = (vector2){0, 0};
    e->data = NULL;
    e->type = ELEMENT_NONE;
    e->visible = true;
    e->id = element_id_count++;
    e->position_px = (vector2){0, 0};
    e->position_rel = (vector2){0, 0};
    e->size_px = (vector2){0, 0};
    e->size_rel = (vector2){0, 0};
    e->anchor = (vector2){0, 0};
    strcpy(e->name, name);
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
    child->child_index = parent->children_count;
    parent->children_count++;
}

void luia_element_unparent(luia_element *e) {
    if (e == NULL || e->parent == NULL) return;

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

    for (int i = index+1; i < parent->children_count; i++) {
        parent->children[i]->child_index = i-1;
        parent->children[i-1] = parent->children[i];
    }

    e->parent = NULL;
    e->child_index = -1;
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

void luia_element_render(luia_element *e, SDL_Renderer *renderer, vector2 abs_pos, vector2 abs_size) {
    //printf("BBB %f %f          %f %f\n", abs_pos.x, abs_pos.y, abs_size.x, abs_size.y);

    printf("%s\n", e->name);

    vector2 new_size = abs_size;
    vector2 new_pos = abs_pos;

    if (e->type != ELEMENT_GROUP && e->type != ELEMENT_ROOT && e->type != ELEMENT_ROOT && e->type != ELEMENT_NONE) {
        new_size = luia_calc_size(abs_size, e->size_px, e->size_rel);
        new_pos = luia_calc_pos(abs_pos, abs_size, e->position_px, e->position_rel);
        new_pos = luia_calc_anchor(new_pos, new_size, e->anchor);
        e->rendering_pos = new_pos;
        e->rendering_size = new_size;
    }

    //printf("AAA %f %f          %f %f\n", new_pos.x, new_pos.y, new_size.x, new_size.y);

    switch (e->type)
    {
        case ELEMENT_TEXT_LABEL:
            //printf("%f %f ; %f %f\n", new_pos.x, new_pos.y, new_size.x, new_size.y);
            luia_textlabel_render((luia_textlabel *)e->data, renderer, new_pos, new_size);
            break;
        case ELEMENT_FRAME:
            luia_frame_render((luia_frame *)e->data, renderer, new_pos, new_size);
            break;
        default:
            break;
    }

    luia_element *children_copy[e->children_count];
    memcpy(children_copy, e->children, sizeof(luia_element*)*e->children_count);
    qsort(children_copy, e->children_count, sizeof(luia_element*), luia_element_sort_comp);

    for (int i = e->children_count-1; i >= 0; i--) {
        luia_element *child = children_copy[i];
        if (child->visible) {
            luia_element_render(child, renderer, new_pos, new_size);
        }
    }
}

int luia_element_sort_comp(const void *p1, const void *p2) {
    luia_element *e1 = (luia_element*)p1;
    luia_element *e2 = (luia_element*)p2;
    if (e1->render_index > e2->render_index) return -1;
    if (e2->render_index > e1->render_index) return 1;
    if (e1->child_index > e2->child_index) return -1;
    if (e2->child_index > e1->child_index) return 1;
    return 0;
}