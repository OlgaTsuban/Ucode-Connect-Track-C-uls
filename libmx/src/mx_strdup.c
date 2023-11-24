#include "../inc/libmx.h"

char *mx_strdup(const char *s1) {
    int size = mx_strlen(s1);
    char *dup = mx_strnew(size);
    if( dup == 0) return NULL;
    mx_strcpy(dup, s1);
    return dup;
}


