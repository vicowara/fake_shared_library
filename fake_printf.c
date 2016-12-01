#include <stdio.h>
#include <stdarg.h>
#define __USE_GNU
#include <dlfcn.h>

int printf(const char *fmt, ...){
    char *ptr;
    void *handle;
    va_list ap;

    puts("nya-n");

    handle = dlsym(RTLD_NEXT, "printf");
    int (*func)(const char *, ...) = (int (*)(const char*, ...))handle;

    va_start(ap, fmt);
    
    ptr = va_arg(ap, char*);
    func("%p\n", ptr);
    while (ptr != NULL) {
        ptr = va_arg(ap, char*);
        func("%p\n", ptr);
    }

    va_end(ap);

    return 0;
}
