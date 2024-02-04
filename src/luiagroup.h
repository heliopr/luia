#ifndef LUIA_GROUP_H
#define LUIA_GROUP_H

#include "luiaelement.h"

typedef struct luia_group
{
    luia_element *element;
} luia_group;


luia_group *luia_group_new(const char *name);

#endif