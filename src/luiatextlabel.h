#ifndef LUIA_TEXTLABEL_H
#define LUIA_TEXTLABEL_H

#include "luiaelement.h"

typedef struct luia_textlabel
{
    luia_element *element;
    char text[1024];
} luia_textlabel;

#endif