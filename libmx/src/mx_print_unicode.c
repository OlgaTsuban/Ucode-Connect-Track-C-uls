#include "../inc/libmx.h"

void mx_print_unicode(wchar_t c) {
    char buffer[4];
    int length = 0;
    if (c < 0x80) {
        buffer[0] = (c >> 0 & 0x7F) | 0x00;
        length = 1;
    }
    else if (c < 0x0800) {
        buffer[0] = (c >> 6 & 0x1F) | 0xC0;
        buffer[1] = (c >> 0 & 0x3F) | 0x80;
        length = 2;
    }
    else if (c < 0x010000) {
        buffer[0] = (c >> 12 & 0x0F) | 0xE0;
        buffer[1] = (c >> 6 & 0x3F) | 0x80;
        buffer[2] = (c >> 0 & 0x3F) | 0x80;
        length = 3;
    }
    else {
        buffer[0] = (c >> 18 & 0x07) | 0xF0;
        buffer[1] = (c >> 12 & 0x3F) | 0x80;
        buffer[2] = (c >> 6 & 0x3F) | 0x80;
        buffer[3] = (c >> 0 & 0x3F) | 0x80;
        length = 4;
    }
    write(1, &buffer, length);
}


