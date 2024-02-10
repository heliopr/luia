#ifndef LUIA_EVENT_H
#define LUIA_EVENT_H

typedef void (* func_ptr_t)(void *);

typedef struct luia_event
{
    func_ptr_t *listeners;
    int listener_count;
    int allocated;
} luia_event;

luia_event *luia_event_new();
void luia_event_listen(luia_event *e, func_ptr_t func);
void luia_event_fire(luia_event *e, void *event_info);
void luia_event_remove_listener(luia_event *e, func_ptr_t func);
void luia_event_destroy(luia_event *e);

#endif