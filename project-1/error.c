/**
 * @file error.c
 * @author Marek Filip (xfilip46), FIT BUT
 * @date 19/Mar/2020
 * @brief IJC-DU1, příklad b)
 * @details Custom warning messages and exit functions.
 *          Compiled: gcc 9.2
 */

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
