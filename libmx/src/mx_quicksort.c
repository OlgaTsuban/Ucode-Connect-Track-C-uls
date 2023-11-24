#include "../inc/libmx.h"

int mx_quicksort(char **arr, int left, int right) {
    if (!arr) return -1;
    int counter = 0;
    if (left < right) {
        int l = left;
        int r = right;
        char *mid = arr[(r + l) / 2];
        while (l <= r) {
            while (mx_strlen(arr[l]) < mx_strlen(mid)) l++;
            while (mx_strlen(arr[r]) > mx_strlen(mid)) r--;

            if (l <= r) {
                if (mx_strlen(arr[r]) != mx_strlen(arr[l])) {
                    char *temp = arr[l];
                    arr[l] = arr[r];
                    arr[r] = temp;
                    counter++;
                }
                r--;
                l++;
            }
        }
        counter += mx_quicksort(arr, left, r);
        counter += mx_quicksort(arr, l, right);
    }
    return counter;
}


