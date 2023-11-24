#include "uls.h"

void printWithOne(t_obj **fp, int fp_amt, bool *fl) {
    for(int i = 0; i < fp_amt; i++) {
        printName(fp[i], fl);
        mx_printstr("\n");
    }
}


