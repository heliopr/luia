#include <stdlib.h>
#include <stdio.h>

#include "luiaevent.h"

luia_event *luia_event_new() {
    luia_event *e = malloc(sizeof(luia_event));
    if (e == NULL) {
        return NULL;
    }

    e->listeners = malloc(sizeof(func_ptr_t));
    if (e->listeners == NULL) {
        return NULL;
    }

    e->listener_count = 0;
    e->allocated = 1;

    return e;
}

void luia_event_listen(luia_event *e, func_ptr_t func) {
    if (e == NULL || func == NULL) return;

    if (e->listener_count == e->allocated) {
        e->allocated *= 2;
        //printf("realloc %d\n", e->allocated);
        func_ptr_t *new_listeners = realloc(e->listeners, sizeof(func_ptr_t)*e->allocated);
        if (!new_listeners) {
            printf("ERROR\n");
        }
        else {
            e->listeners = new_listeners;
        }
    }

    e->listeners[e->listener_count++] = func;
}

void luia_event_fire(luia_event *e, void *event_info) {
    if (e == NULL || event_info == NULL) return;

    for (int i = 0; i < e->listener_count; i++) {
        func_ptr_t func = e->listeners[i];
        if (func != NULL) {
            func(event_info);
        }
    }
}

void luia_event_remove_listener(luia_event *e, func_ptr_t func) {
    if (e == NULL || func == NULL) return;

    for (int i = 0; i < e->listener_count; i++) {
        if (e->listeners[i] == func) {
            e->listeners[i] = e->listeners[e->listener_count-1];
            break;
        }
    }

    e->listeners[--e->listener_count] = NULL;
}

void luia_event_destroy(luia_event *e) {
    if (e == NULL) return;

    free(e->listeners);
    free(e);
}