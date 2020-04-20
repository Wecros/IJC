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
#include "io.h"

// defined this size so the disrtibution is alright and size
// is not very large but allows adequate speed
#define TABLE_SIZE 100000
#define MAX_WORD_LEN 127

#ifdef HASHTEST
// Modified loselose function to suit the universe's purpose.
size_t htab_hash_fun(htab_key_t str) {
    fprintf(stderr, "MY HASH FUNCTION USED\n");
    unsigned int h = 0;
	int c;
	while (c = *str++)
	    h += c;
        h *= 42;
	return h;
}
#endif

// Outputs the words in a 'key' \tab 'count' format.
void htab_output(const htab_t *t) {
    htab_iterator_t it = htab_begin(t);
    while (!htab_iterator_equal(it, htab_end(t))) {
        printf("%s\t%d\n", htab_iterator_get_key(it), htab_iterator_get_value(it));
        it = htab_iterator_next(it);
    }
}

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

    // htab_dump(t);
    htab_output(t);
    htab_free(t);

   return EXIT_SUCCESS;
}
