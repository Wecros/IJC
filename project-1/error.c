#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>

#include "error.h"

void warning_msg(const char* fmt, ...) {
    va_list ap;
    va_start(ap, fmt);

    fputs("CHYBA: ", stderr);
    vfprintf(stderr, fmt, ap);

    va_end(ap);
}

void error_exit(const char* fmt, ...) {
    va_list ap;
    va_start(ap, fmt);

    fputs("CHYBA: ", stderr);
    vfprintf(stderr, fmt, ap);

    va_end(ap);
    exit(EXIT_FAILURE);
}