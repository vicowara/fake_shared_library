#include <stdio.h>
#include <stdarg.h>

int printf(const char *fmt, ...){
    puts("nya-n");
    char *ptr;
    
    va_list ap;
    va_start(ap, fmt);
    
    ptr = va_arg(ap, char*);
    while (ptr != NULL) {
        ptr = va_arg(ap, char*);
    }
    
    va_end(ap);
    
    return 0;
}
