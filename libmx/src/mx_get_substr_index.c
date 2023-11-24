#include "../inc/libmx.h"

int mx_get_substr_index(const char *str, const char *sub) {
    int index = 0;
    int sublen = 0;
    if (!sub || !str) {
        return -2;
    }
    sublen = mx_strlen(sub);
    while (*str) {
        int n = sublen;
        const char *s1 = str;
        const char *s2 = sub;
        while (n--) {
            if (*s1 != *s2) {
                break;
            }
            s1++;
            s2++;
        }
        if (n == -1) {
            return index;
        }

        index++;
        str++;
    }
    return -1;
}


