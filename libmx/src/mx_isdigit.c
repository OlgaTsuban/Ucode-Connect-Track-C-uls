#include "../inc/libmx.h"

/*bool mx_isdigit( int c) {
    if (c >= 48 && c <= 57) {
        return 1;
    }
    else {
        return 0;
    }
}*/
bool mx_isdigit(char s) {
    /*if (!mx_isdigit(s)) {
     return false;
     }
     return true;*/
    
    if (s >= 48 && s <= 57) {
        return 1;
    }
    else {
        return 0;
    }
}
