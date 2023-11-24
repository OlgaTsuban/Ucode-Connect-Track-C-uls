#include "../inc/libmx.h"

int mx_bubble_sort(char **arr, int size) {
    char *try;
    int res = 0;
    
    for (int i = 0; i < size; i++) {
        for (int j = 1; j < size - i; j++) {
            if (mx_strcmp(arr[j - 1], arr[j]) > 0) {
                try = arr[j];
                arr[j] = arr[j - 1];
                arr[j - 1] = try;
                res++;
            }
        }
    }
    return res;
}


