#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#include "luiawindow.h"
#include "luiaelement.h"
#include "luia.h"

int main() {
    if (!luia_init()) {
        fprintf(stderr, "An error occurred when trying to init luia\n");
        return 1;
    }

    luia_window *w = luia_window_create(300, 200, "JANELINHA");
    luia_window_show(w);

    luia_element *e = luia_element_new();
    luia_element_add_child(w->root_element, e);

    luia_quit();
}