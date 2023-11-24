#include "uls.h"

int main(int argc, char ** argv) {
//Parsing
    bool *fl = bool_manipulate(argc, argv);
    t_path *p = getPaths(argc, argv, fl);
//Fetching
    t_data *d = fetchData(p, fl);
//Kostyl dla L
    if (d)
        cutDeadLinks(d->dirs_path, d->dirs_amt, fl);
//Sorting
    flags_check (d, fl);
//Printing
    printResult(d, fl);
//Cleanup
    freePath(p);
    freeData(d);
    free(fl);
    
    return fl[err] ? 1 : 0;
}
