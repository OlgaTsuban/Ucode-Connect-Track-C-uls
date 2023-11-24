#include "uls.h"

bool *bool_manipulate(int argc, char **argv) {
    //Step 1: get an array of bool flags based on argv
    bool *flags = flags_num (argc, argv);
    //step 2: compare and manipulate the bool flags
    flags = uls_cmp_flags(flags);
    flags = uls_isatty(flags);
    return flags;
}
