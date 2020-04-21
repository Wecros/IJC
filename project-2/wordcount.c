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
What I found when comparing times between C and C++ versions:
    - The times are almost identical in most cases.
    - In cases where C has the ideal table_size, it is faster.
      e.g. for input seq 100000 1000000 if TABLE_SIZE = 900000
      the C program is about 20-30% faster compared to the C++ program.
    - Choosing big enough TABLE_SIZE is crucial, if the TABLE_SIZE is smaller
      than the count of entries it lowers the time efficiency significantly.
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "htab.h"
#include "io.h"
#include "private.h"  // TODO: remove

// defined this size so the disrtibution is alright and size
// is not very large but allows adequate speed
#define TABLE_SIZE      100000
#define MAX_WORD_LEN    127
#define EXIT_SUCCESS    0   // exited normally
#define EXIT_LONG_WORD  1   // exited with encountered word over limit
#define EXIT_ERROR      2   // program terminated, exit failure

#ifdef HASHTEST
// Modified loselose function to suit the universe's purpose.
// When tested, this function was miles worse than the given one.
size_t htab_hash_fun(htab_key_t str) {
    unsigned int h = 42;
	int c;
	while ((c = *str++))
	    h += 42 * c;
	return h;
}
#endif

#ifdef DEBUG
// nonessential, for debug, prints the hashtable
void htab_dump(const htab_t *t) {
    if (htab_size(t) <= 0) {
        return;
    }
    htab_iterator_t it = htab_begin(t);
    while (!htab_iterator_equal(it, htab_end(t))) {
        printf("[bucket %4ld]: %s:%d\n", it.idx, htab_iterator_get_key(it),
            htab_iterator_get_value(it));
        it = htab_iterator_next(it); // go to next iterator
    }
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
    if (t == NULL) {
        fprintf(stderr, "ERROR: Allocation of memory failed.");
        return EXIT_ERROR;
    }

    int exitcode = EXIT_SUCCESS;
    int retcode = 0;
    while (retcode != EOF) {
        char word[MAX_WORD_LEN] = "\0";
        retcode = get_word(word, MAX_WORD_LEN, stdin);
        if (retcode != EOF) {
            // Add the word to the hashtable or increment the count of word
            htab_iterator_t iter = htab_lookup_add(t, word);
            if (!htab_iterator_valid(iter)) {
                fprintf(stderr, "ERROR: Allocation of memory failed.");
                return EXIT_ERROR;
            }
        } else if (retcode == 1) {
            exitcode = EXIT_LONG_WORD;
        }
    }

    htab_output(t);
    #ifdef DEBUG
    htab_dump(t);
    #endif
    htab_free(t);

    return exitcode;
}
