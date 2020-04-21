/**
 * @file private.h
 * @author Marek Filip (xfilip46), FIT BUT
 * @date 2020-Apr-21
 * @brief IJC-DU2, příklad b)
 * @details Header file for defining private structs and functions.
 *          Compiled: gcc 9.3
 */

#include <string.h>  // size_t
#include <stdlib.h>  // malloc, free

#include "htab.h"

typedef struct htab_item htab_item_t;

struct htab_item {
    htab_key_t key; // hash key
    size_t count;   // entry count
    struct htab_item *next; // pointer to the next item in a bucket
};

struct htab {
    unsigned size;      // count of entries
    unsigned arr_size;  // count of buckets (linked lists)
    htab_item_t *items[];  // pointers to buckets
};


// Function for entry initialization.
htab_item_t *item_init(htab_t *t, htab_key_t key);

// Function for freeing the item and reducing the entry count.
void item_free(htab_t *t, htab_item_t *item);

// Function for iterator initialization.
htab_iterator_t iterator_init(const htab_t *t, const size_t idx);

// Create the iterator from the passed key. Uses hashing function.
htab_iterator_t get_iterator_from_key(const htab_t *t, htab_key_t key);
