#include <stdio.h>
#include <stdlib.h>
#include <dlfcn.h>

void *malloc(size_t size) {
    void *ptr;
    void *handle;

    handle = dlsym(RTLD_NEXT, "malloc");
    void* (*original_malloc)(size_t) = (void* (*)(size_t))handle;

    ptr = original_malloc(size);

    // TODO: add ptr to list

    return ptr;
}

void free(void *ptr) {
    void *handle;

    handle = dlsym(RTLD_NEXT, "free");
    void (*original_free)(void*) = (void (*)(void*))handle;

    // TODO: remove ptr from list

    original_free(ptr);
}
