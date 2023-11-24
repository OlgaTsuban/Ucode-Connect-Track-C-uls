#include "../inc/libmx.h"

char *mx_nbr_to_hex(unsigned long nbr) {
    if (nbr == 0) {
        char *result = malloc(2);
        if (result) {
            result[0] = '0';
            result[1] = '\0';
        }
        return result;
    }
    
    int size = 0;
    unsigned long tmp = nbr;
    while (tmp > 0) {
        tmp /= 16;
        size++;
    }

    char *result = malloc(size + 1);
    if (!result) {
        return NULL;
    }

    result[size] = '\0';

    for (int i = size - 1; i >= 0; i--) {
        int digit = nbr % 16;
        result[i] = (digit < 10) ? ('0' + digit) : ('a' + digit - 10);
        nbr /= 16;
    }

    return result;
}


