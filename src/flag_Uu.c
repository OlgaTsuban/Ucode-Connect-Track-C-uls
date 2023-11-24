#include "uls.h"

static bool cmpLexographical(t_obj *obj1, t_obj *obj2) {
    char *str1 = obj1->s_name;
    char *str2 = obj2->s_name;

    if (obj1->st.st_birthtime == obj2->st.st_birthtime) {
        for (; *str1 == *str2; str1++, str2++)
            if (*str1 == '\0')
                return 0;
        return (*str1 - *str2) > 0 ? true : false;
    }
    return obj1->st.st_birthtime < obj2->st.st_birthtime ? true : false;
}

void flag_Uu(t_obj **d, int d_amt, const bool *fl) {

    if (fl[U] && fl[t]) {
        quicksortObj(d, 0, d_amt - 1, cmpLexographical);
        for (int i = 0; i < d_amt; i++)
            if (d[i]->kids_amt)
                flag_Uu(d[i]->kids, d[i]->kids_amt, fl);
    }
}
