#include "../inc/libmx.h"

int mx_file_length(const char *file) {
    short flen = open(file, O_RDONLY);
    short size = 0;
    int len = 0;
    char buf;
    size = read(flen, &buf, 1);
    while (size > 0) {
        size = read(flen, &buf, 1);
        len++;
    }
    close(flen);
    return len;
}

