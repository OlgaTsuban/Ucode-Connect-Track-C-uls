#include "../inc/libmx.h"

void *mx_memchr(const void *s, int c, size_t n) {
    unsigned char *p = (unsigned char *)s;

    while (n--) {
        if (*p == (unsigned char)c)
            return p;
        p++;
    }
    return NULL;
}


