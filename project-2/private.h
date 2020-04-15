/**
 * @file private.h
 * @author Marek Filip (xfilip46), FIT BUT
 * @date 2020-Apr-15
 * @brief IJC-DU2, příklad b)
 * @details Header file for defining private structs and functions.
 *          Compiled: gcc 9.3
 */

#include <string.h>  // size_t
#include <stdlib.h>  // malloc

#include "htab.h"

struct htab_item {
    const char *key;
    size_t count;
    struct htab_item *next;
};

struct htab {
    unsigned size;      // count of entries
    unsigned arr_size;  // count of buckets (linked lists)
    struct htab_item *items[];  // pointers to buckets
};

typedef struct htab_item htab_item_t;

htab_item_t *item_init(htab_key_t key);
void item_free(htab_item_t *item);
// htab_iterator_t iterator_init(htab_item_t *ptr, const htab_t *t, size_t idx);
htab_iterator_t iterator_init(const htab_t *t, size_t idx);
