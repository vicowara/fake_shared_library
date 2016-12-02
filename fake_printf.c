#include <stdio.h>
#include <stdarg.h>
#include <string.h>
#include <dlfcn.h>

int printf(const char *fmt, ...){
    char buf[4096];
    void *handle;
    va_list ap;

    handle = dlsym(RTLD_NEXT, "printf");
    int (*original_printf)(const char *, ...) = (int (*)(const char*, ...))handle;

    va_start(ap, fmt);
    vsnprintf(buf, sizeof(buf), fmt, ap);
    va_end(ap);

    original_printf("|ω・`）< %s", buf);

    return 0;
}
