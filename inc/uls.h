#pragma once

#include "libmx.h"
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/errno.h>
#include <dirent.h>
#include <pwd.h>
#include <grp.h>
#include <sys/xattr.h>
#include <sys/acl.h>
#include <sys/ioctl.h>
#include <time.h>

#define FLAG_LIST "ACFGHLRSTUacdefghlmnoprtu1@"
#define INT_MAX 2147483647
#define PATH_MAX 1024
#define BIBYTE 1024

 //colors
#define RED       "\x1B[31m"
#define GRN       "\x1B[32m"
#define YEL       "\x1B[33m"
//#define BLU       "\x1B[1m\x1B[36m"
#define BLU    "\x1B[34m"
#define MAG       "\x1B[35m"
#define RESET     "\x1B[0m"
#define BLK_F_RED_B "\x1B[0;30;41m"
#define BLK_F_CYAN_B "\x1B[0;30;46m"
#define BLOCK "\x1B[0;34;46m"
#define CHR "\x1B[0;34;43m"
#define DIR_T "\x1B[0;30;42m"
#define DIR_X "\033[0;30;43m"

//Enums
enum flags {
    G,
    U,
    F,
    f,
    a,
    A,
    R,
    l,
    one,
    m,
    C,
    S,
    t,
    r,
    p,
    u,
    c,
    dog,
    e,
    h,
    T,
    d,
    L,
    H,
    n,
    o,
    g,
    tty,
    err,
    ALL_FLAGS,
};
enum types {
    fifo,
    chr,
    blk,
    lnk,
    sock,
    dir,
    file,
    dot_dir,
    perm_denied,
};

//structs
typedef struct s_path {
    char **path;
    bool *isdir;
    int amt;
}              t_path;
typedef struct s_obj {
    struct s_obj **kids;
    char *path_name;
    char *s_name;
    struct stat st;
    int kids_amt;
    char type;
    bool is_root;
    bool is_deadl;
}              t_obj;
typedef struct s_data {
    t_obj **dirs_path;
    t_obj **files_path;
    int dirs_amt;
    int files_amt;
}               t_data;
typedef struct s_lout {
    int total;
    short a_link;
    short b_owner;
    short c_group;
    short d_size;
    bool d_minor;
}               t_lout;

//gets
t_path *getPaths(int argc, char *argv[], bool *fl);
t_obj *fetchDirInfo(char *p, bool *fl);
t_obj *wc_fetchFileInfo(char *p, bool *fl);

//do some manage work
t_data *fetchData(t_path *p, bool *fl);
void printResult(t_data *d, bool *flocktimeout);

//Print
void printName(t_obj *obj, bool *fl);
void printWithC(t_obj **fp, int fp_amt, bool *fl);
void printWithOne(t_obj **fp, int fp_amt, bool *fl);
void printWithM(t_obj **fp, int fp_amt, bool *fl);
void printWithL(t_obj **fp, int fp_amt, bool *fl, bool use_total);
t_lout wc_getSizesForL(t_obj **fp, int fp_amt, bool *fl);
void printPerms(struct stat st, char *p);
void printStats(struct stat st, t_lout l, bool *fl);
void printTime(struct stat st, bool *fl);


//sorting
void quicksortObj(t_obj **arr, int l, int r, bool cmp(t_obj *, t_obj *));

//utilities
char *getShortName(char *p);
short getBitDepth(int a);
char getType(struct stat st);
void printDouble(double n);

//clean
void cutDeadLinks(t_obj **dir, int dir_amt, bool *fl);
void freePath(t_path *p);
void freeObj(t_obj *o);
void freeData(t_data *d);

//work with error
void errorNoPath(char *path);
void errorPermDenied(char *name_of_dir);
void wc_printTime(struct stat st, bool *fl);

//etc
bool *flags_num (int argc, char *argv[]);
bool *uls_cmp_flags(bool *fls);
void error_illegal_option(char *flags_char);
bool *uls_isatty(bool *fls);
bool *cf_bool_manip(int argc, char **argv);
void flags_check (t_data *d, bool *fl);
void flag_r(t_obj **d, int d_amt, const bool *fl);
void flag_S(t_obj **d, int d_amt, const bool *fl);
void flag_t(t_obj **d, int d_amt, const bool *fl);
void flag_u(t_obj **d, int d_amt, const bool *fl);
void flag_c(t_obj **d, int d_amt, const bool *fl);
void flag_Uu(t_obj **d, int d_amt, const bool *fl);
void not_flag_f(t_obj **d, int d_amt, const bool *fl);
void flag_F_and_p(t_obj **d, int d_amt, const bool *fl);
bool *bool_manipulate(int argc, char **argv);

