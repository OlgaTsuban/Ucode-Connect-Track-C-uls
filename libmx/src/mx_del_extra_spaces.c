#include "../inc/libmx.h"

char *mx_del_extra_spaces(const char *str) {
    char *new_str = NULL;
    char *temp = NULL;
    
    if (!str) return NULL;
    
    new_str = mx_strnew(mx_strlen(str));
    int k = 0;
    int j = 0;
    while (str[k]) {
        if (!(mx_isspace(str[k]))) {
            new_str[j] = str[k];
            j++;
        }
        if (!(mx_isspace(str[k])) && mx_isspace(str[k + 1])) {
            new_str[j] = ' ';
            j++;
        }
        k++;
    }
    temp = mx_strtrim(new_str);
    mx_strdel(&new_str);
    return temp;
}


