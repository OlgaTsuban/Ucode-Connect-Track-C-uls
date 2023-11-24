#include "../inc/libmx.h"

char *mx_strcat(char *restrict s1, const char *restrict s2) {
    int size_s1 = mx_strlen(s1);
    int size_s2 = mx_strlen(s2);
    int count = size_s1;
    int j = 0;

    while (count < (size_s1 + size_s2)) {
        s1[count] = s2[j];
        count++;
        j++;
    }
    s1[count++] = '\0';
    return s1;
}


