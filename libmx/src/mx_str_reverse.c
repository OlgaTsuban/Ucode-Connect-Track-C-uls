#include "../inc/libmx.h"

void mx_str_reverse(char *s) {
    int i = 0;
    int b = mx_strlen(s);
    while (i < b / 2) {
        mx_swap_char(&s[i], &s[b - i - 1]);
        i++;
    }
}


