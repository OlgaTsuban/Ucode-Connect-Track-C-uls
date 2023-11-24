#include "../inc/libmx.h"

int mx_count_substr(const char *str, const char *sub) {
    int count = 0;
    if (str == NULL || sub == NULL) {
        return -1;
    }
    if (*sub == '\0') {
        return 0;
    }
    int len2 = mx_strlen(sub);
    while (*str) {
        const char *s1 = str;
        const char *s2 = sub;
        int n = len2;
        int matched = 1; 
        
        while (n--) {
            if (*s1 != *s2) {
                matched = 0;
                break;
            }
            s1++;
            s2++;
        }
        
        if (matched && n == -1) {
            count++;
        }
        
        str++;
    }
        return count;
}


