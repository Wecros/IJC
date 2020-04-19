/**
 * @file wordcount.c
 * @author Marek Filip (xfilip46), FIT BUT
 * @date 2020-Apr-15
 * @brief IJC-DU2, příklad b)
 * @details The assigment is to rewrite a C++ program to pure C.
 *          The program counts the frequency of words in the output text.
 *          Word counts as anything seperated by whitespace.
 *          Program relies on hashtable implementation.
 *          Compiled: gcc 9.3
 */

/*
Things to look for:
    types of parameters in fuctions, good usage of 'const'
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "htab.h"
#include "private.h"
#include "io.h"

// defined this size so the disrtibution is alright and size is not very large
#define TABLE_SIZE 100000

int main() {
    htab_t *t = htab_init(TABLE_SIZE);

    int retcode = 0;
    while (retcode != EOF) {
        char word[MAX_WORD_LEN] = "\0";
        retcode = get_word(word, MAX_WORD_LEN, stdin);
        if (retcode != EOF) {
            // Add the word to the hashtable or increment the count of word
            htab_lookup_add(t, word);
        }
    }

    htab_output(t);
    htab_free(t);

   return EXIT_SUCCESS;
}
