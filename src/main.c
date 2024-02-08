#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#include "luiawindow.h"
#include "luiatextlabel.h"
#include "luiagroup.h"
#include "luiaframe.h"
#include "luiacore.h"

uint32_t last_t = 0;

void keydown(void *e) {
    luia_window_keydown_event *ev = (luia_window_keydown_event*)e;

    printf("janelinha 1 apertou teclinha %d\n", ev->key);
}

int main() {
    if (!luia_init()) {
        fprintf(stderr, "An error occurred when trying to init' luia\n");
        return 1;
    }
    
    luia_window *w = luia_window_new(800, 600, "Windooooooow");
    w->background_color = (rgba){230, 230, 230};
    luia_window_show(w);

    luia_window *w2 = luia_window_new(300, 300, "Windo2 ");
    w2->quit_on_close = false;
    luia_window_show(w2);

    luia_event_listen(w->key_down_event, keydown);

    //luia_window_focus(w);

    luia_group *g = luia_group_new("grupo");
    luia_window_add_element(w, g->element);

    luia_textlabel *t = luia_textlabel_new("lbl");
    t->element->anchor = (vector2) {0.5, 0.5};
    t->element->position_px = (vector2) {0, 0};
    t->element->position_rel = (vector2) {0.5, 0.5};
    t->element->size_px = (vector2) {0, 0};
    t->element->size_rel = (vector2) {0.7, 0.4};
    t->text_x_alignment = X_LEFT;
    t->text_y_alignment = Y_MIDDLE;
    t->text_size = 14;
    t->clip_text = true;
    t->wrap_text = true;
    t->border_color = (rgba){0, 0, 0, 0};
    t->border_thickness = 5;
    t->background_color = (rgba){255, 0, 0, 255};
    strcpy(t->text, "Lorem ipsum dolor sit amet, consectetur adipiscing elit. Nullam et turpis et quam sagittis interdum faucibus vel turpis. Vestibulum vitae maximus nibh. Quisque quam purus, tincidunt eu pellentesque sed, luctus vitae lacus. In hac habitasse platea dictumst. Aenean id nibh commodo, ultricies dolor eu, facilisis ligula. Aenean suscipit, magna sed semper porttitor, dolor magna venenatis orci, volutpat fringilla enim erat ut eros. Vestibulum feugiat justo eu orci sodales, sed porttitor erat vestibulum. Quisque aliquet varius sem, in laoreet ligula efficitur ut. Quisque congue erat ut libero consectetur ultricies. Nam pretium interdum massa. Phasellus congue lorem id semper consequat. Etiam sodales tortor ipsum, vel eleifend nisl finibus vel. Cras ultrices eu magna gravida accumsan.");

    //luia_window_add_element(w, t->element);
    luia_element_add_child(g->element, t->element);

    luia_frame *frame = luia_frame_new("FRAMEZINHO");
    frame->element->size_rel = (vector2){1, 0.1};
    frame->background_color = (rgba){0, 255, 0, 255};
    luia_window_add_element(w, frame->element);
    
    luia_run();

    luia_quit();
}