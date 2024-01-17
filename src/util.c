#include <string.h>

#include "util.h"

int str_next_wrap(const char *s, int i, int goal) {
    int len = strlen(s);
    int j = i, k = i;
    while (j <= len && j < i+goal) {
        if ((s[j] == '\0' || s[j] == ' ')) {
            if (j > 0 && s[j-1] == ' ') {
                j++;
                continue;
            }
            k = j;
        }
        j++;
    }
    if (k == i) k = j;
    return k;
}

void str_copy(const char *s, int i, int j, char *output) {
    int k = 0;
    for (i; i < j; i++){
        output[k] = s[i];
        k++;
    }
    output[k] = '\0';
}

void str_clear_lspaces(const char *s, char *output) {
    int k = 0;
    int len = strlen(s);
    for (int i = 0; i < len; i++) {
        if (k == 0 && s[i] == ' ') continue;
        output[k] = s[i];
        k++;
    }
    output[k] = '\0';
}