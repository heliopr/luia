#ifndef LUIA_UTIL_H
#define LUIA_UTIL_H

int str_next_wrap(const char *s, int i, int goal);
void str_copy(const char *s, int i, int j, char *output);
void str_clear_lspaces(const char *s, char *output);

#endif