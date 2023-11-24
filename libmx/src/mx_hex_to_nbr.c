#include "../inc/libmx.h"

unsigned long mx_hex_to_nbr(const char *hex) {
    if (hex == NULL) return 0;
    int j = 0;
    while (hex[j] != '\0')
        j++;
    unsigned long res = 0;
    unsigned long dec = 1;
    for (int i = j - 1; i >= 0; i--) {
        if ((hex[i]) >= 48 && hex[i] <= 57) {
            res += ((hex[i] - 48) * dec);
            dec *= 16;
        }
        if ((hex[i] >= 65 && hex[i] <= 90 )|| (hex[i] >= 97 && hex[i] <= 122)) {
            if ((hex[i] >= 65 && hex[i] <= 90 )) {
                res += ((hex[i] - 55) * dec);
                dec *= 16;
            }
            else {
                res += ((hex[i] - 87) * dec);
                dec *= 16;
            }
        }
    }
    return res;
}


