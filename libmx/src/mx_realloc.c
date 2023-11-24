#include "../inc/libmx.h"

void *mx_realloc(void *ptr, size_t size) {
    if (ptr == NULL) {
        return malloc(size);
    }
    if (size == 0) {
        free(ptr);
        return NULL;
    }

    size_t cur_size = malloc_size(ptr);;
    void *new_ptr;
    
    
    if (size <= cur_size) {
        return ptr;
    }
    new_ptr = malloc(size);
    
    mx_memcpy(new_ptr, ptr, cur_size);
    
    free(ptr);
    return new_ptr;
}


