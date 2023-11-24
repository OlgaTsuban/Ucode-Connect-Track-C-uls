#include "../inc/libmx.h"

char *mx_file_to_str (const char *file) {
    if (file == NULL) return NULL;
    char temp;
    int count = 0;

    int f = open (file, O_RDONLY);
    if (f < 0) {
        return NULL;
    }
        
    while (read (f, &temp, 1) > 0) {
        count++;
    }
        
    if (close (f) != 0) {
        return NULL;
    }
    close (f);

    char *res = mx_strnew(count);
    f = open (file, O_RDONLY);
    if (f < 0) {
        return NULL;
    }
    for (int i = 0; read (f, &temp, 1) > 0; i++) {
        res[i] = temp;
    }
    if (close (f) != 0) {
        return NULL;
    }
    close (f);

    return res;
}


