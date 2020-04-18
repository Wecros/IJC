/**
 * @file io.h
 * @author Marek Filip (xfilip46), FIT BUT
 * @date 2020-Apr-15
 * @brief IJC-DU2, příklad b)
 * @details File for declaring input-output functions.
 *          Compiled: gcc 9.3
 */

#define MAX_WORD_LEN 127
#define MAX_WORD_LEN_STRING "127"
#include <stdio.h>

int get_word(char *s, int max, FILE *f);
