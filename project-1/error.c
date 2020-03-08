#include <stdio.h>
#include <stdlib.h>

#include "error.h"

void warning_msg(const char* fmt, ...) {
    va_list args;
    va_start(args, fmt);

    fputs("WARNING: ", stderr);
    vfprintf(stderr, fmt, args);

    va_end(args);
    exit(EXIT_FAILURE);
}

void error_exit(const char* fmt, ...) {
    va_list args;
    va_start(args, fmt);

    fputs("ERROR: ", stderr);
    vfprintf(stderr, fmt, args);

    va_end(args);
    exit(EXIT_FAILURE);
}