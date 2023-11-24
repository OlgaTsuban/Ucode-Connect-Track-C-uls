#include "uls.h"

void flags_check (t_data *d, bool *fl) {
    if (d){
        not_flag_f(d->files_path, d->files_amt, fl);
        not_flag_f(d->dirs_path, d->dirs_amt, fl);
        flag_S(d->files_path, d->files_amt, fl);
        flag_S(d->dirs_path, d->dirs_amt, fl);
        if (!fl[f]) {
            flag_t(d->files_path, d->files_amt, fl);
            flag_t(d->dirs_path, d->dirs_amt, fl);
            flag_u(d->files_path, d->files_amt, fl);
            flag_u(d->dirs_path, d->dirs_amt, fl);
            flag_c(d->files_path, d->files_amt, fl);
            flag_c(d->dirs_path, d->dirs_amt, fl);
            flag_Uu(d->files_path, d->files_amt, fl);
            flag_Uu(d->dirs_path, d->dirs_amt, fl);
        }
        flag_F_and_p(d->files_path, d->files_amt, fl);
        flag_F_and_p(d->dirs_path, d->dirs_amt, fl);
        flag_r(d->files_path, d->files_amt, fl);
        flag_r(d->dirs_path, d->dirs_amt, fl);
    }
}
