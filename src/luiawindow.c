#include "luiawindow.h"
#include "rendering.h"
#include "luiacore.h"

luia_window *luia_window_new(uint16_t width, uint16_t height, const char *title) {
    luia_window *w = malloc(sizeof(luia_window));
    w->width = width;
    w->height = height;
    w->resizable = true;
    w->quit_on_close = false;
    w->visible = false;
    w->sdl_window = SDL_CreateWindow(title, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, w->width, w->height, SDL_WINDOW_HIDDEN | SDL_WINDOW_RESIZABLE);
    w->sdl_renderer = SDL_CreateRenderer(w->sdl_window, -1, 0);
    SDL_SetRenderDrawBlendMode(w->sdl_renderer, SDL_BLENDMODE_BLEND);
    w->background_color = (rgba){0, 0, 0, 255};
    strcpy(w->title, title);

    w->key_down_event = luia_event_new();
    w->key_up_event = luia_event_new();
    w->mouse_down_event = luia_event_new();
    w->mouse_up_event = luia_event_new();

    w->root_element = luia_element_new("root");
    w->root_element->type = ELEMENT_ROOT;

    luia_register_window(w);
    return w;
}

void luia_window_show(luia_window *w) {
    if (!w->visible) {
        SDL_ShowWindow(w->sdl_window);
        w->visible = true;
    }
}

void luia_window_hide(luia_window *w) {
    if (w->visible) {
        SDL_HideWindow(w->sdl_window);
        w->visible = false;
    }
}

void luia_window_focus(luia_window *w) {
    luia_window_show(w);
    SDL_RaiseWindow(w->sdl_window);
}

void luia_window_set_resizable(luia_window *w, bool resizable) {
    w->resizable = resizable;
    SDL_SetWindowResizable(w->sdl_window, resizable);
}

void luia_window_add_element(luia_window *w, luia_element *e) {
    luia_element_add_child(w->root_element, e);
}

void get_hovering_element(luia_element *e, int mouse_x, int mouse_y, luia_element **res) {
    luia_element *children_copy[e->children_count];
    memcpy(children_copy, e->children, sizeof(luia_element*)*e->children_count);
    qsort(children_copy, e->children_count, sizeof(luia_element*), luia_element_sort_comp);

    for (int i = 0; i < e->children_count; i++) {
        luia_element *c = children_copy[i];
        if (c != NULL && (*res) == NULL) {
            get_hovering_element(c, mouse_x, mouse_y, res);
        }

        if ((*res) != NULL) break;
    }

    if ((*res) == NULL && e->visible && mouse_x >= e->rendering_pos.x && mouse_x < e->rendering_pos.x+e->rendering_size.x
    && mouse_y >= e->rendering_pos.y && mouse_y < e->rendering_pos.y+e->rendering_size.y) {
        *res = e;
    }
}

void luia_window_render(luia_window *w) {
    luia_element *root = w->root_element;
    SDL_Renderer *renderer = w->sdl_renderer;

    rgba color = w->background_color;
    SDL_SetRenderDrawColor(w->sdl_renderer, color.r, color.g, color.b, 255);
    SDL_RenderClear(w->sdl_renderer);

    SDL_GetWindowSizeInPixels(w->sdl_window, &w->width, &w->height);
    vector2 window_size = {w->width, w->height};
    vector2 pos = {0, 0};

    luia_element_render(w->root_element, renderer, pos, window_size);
    /*for (int i = 0; i < root->children_count; i++) {
        //printf("rendering %s\n", root->children[i]->name);
        luia_element *e = root->children[i];
        if (e->visible) {
            luia_element_render(e, renderer, pos, window_size);
        }
    }*/

    SDL_RenderPresent(w->sdl_renderer);
}

void luia_window_handle_event(luia_window *w, SDL_Event event) {
    if (event.type == SDL_WINDOWEVENT && event.window.event == SDL_WINDOWEVENT_CLOSE) {
        if (luia_get_window_count() == 1 || w->quit_on_close) {
            luia_set_is_running(false);
        }
        else {
            luia_window_destroy(w);
        }
    }
    else {
        int mouse_x, mouse_y;
        SDL_GetMouseState(&mouse_x, &mouse_y);
        switch (event.type) {
            case SDL_KEYDOWN:
                luia_window_keydown_event keydown_event = {w, luia_sdlkey_map(event.key.keysym.sym)};
                luia_event_fire(w->key_down_event, (void*)&keydown_event);
                break;

            case SDL_KEYUP:
                luia_window_keyup_event keyup_event = {w, luia_sdlkey_map(event.key.keysym.sym)};
                luia_event_fire(w->key_up_event, (void*)&keyup_event);
                break;

            case SDL_MOUSEBUTTONDOWN:
                luia_window_mousedown_event mousedown_event = {w, mouse_x, mouse_y, luia_sdlmouse_map(event.button.button)};
                luia_event_fire(w->mouse_down_event, (void*)&mousedown_event);


                luia_element *res = NULL;
                get_hovering_element(w->root_element, mouse_x, mouse_y, &res);

                if (res == NULL) {
                    printf("clicou em nada\n");
                }
                else {
                    printf("clicou no elemento %s\n", res->name);
                }
                
                break;

            case SDL_MOUSEBUTTONUP:
                luia_window_mouseup_event mouseup_event = {w, mouse_x, mouse_y, luia_sdlmouse_map(event.button.button)};
                luia_event_fire(w->mouse_up_event, (void*)&mouseup_event);
                break;
            
            default:
                break;
        }
    }
}

void luia_window_destroy(luia_window *w) {
    luia_unregister_window(w);
    SDL_DestroyRenderer(w->sdl_renderer);
    SDL_DestroyWindow(w->sdl_window);
    //free(w->title);
    free(w);
}