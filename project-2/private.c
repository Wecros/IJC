/**
 * @file private.h
 * @author Marek Filip (xfilip46), FIT BUT
 * @date 2020-Apr-15
 * @brief IJC-DU2, příklad b)
 * @details Module file for defining functions.
 *          Compiled: gcc 9.3
 */

#include <stdio.h>
#include <string.h>

#include "private.h"

htab_item_t *item_init(htab_key_t key) {
    htab_item_t *item = malloc(sizeof(htab_item_t *));
    item->key = malloc(strlen(key) + sizeof(char));
    if (item == NULL || item->key == NULL) {
        return NULL;
    }
    // item->key = key;
    strcpy(item->key, key);
    item->count = 1;
    item->next = NULL;
    return item;
}

void item_free(htab_item_t *item) {
    // item->key = NULL;  // const
    item->count = 0;
    free(item);
}

htab_iterator_t iterator_init(const htab_t *t, size_t idx) {
    htab_iterator_t it = { t->items[idx], t, idx };
    if (idx >= t->arr_size) {  // is this needed?
        it.ptr = NULL;
    }
    return it;
}

// nonessential, for debug, prints the hashtable
void htab_dump(const htab_t *t) {
    htab_iterator_t it = htab_begin(t);
    while (it.idx < htab_bucket_count(t)) {
        if (htab_iterator_valid(it)) {
            printf("%s\t%ld\n", it.ptr->key, it.ptr->count);
            it = htab_iterator_next(it);
            while (htab_iterator_valid(it)) {
                printf("%s\t%ld\n", it.ptr->key, it.ptr->count);
                // printf("|%s:%ld", it.ptr->key, it.ptr->count);
                it = htab_iterator_next(it);
            }
            // printf("\n");
        }

        it = htab_iterator_next(it); // go to next iterator
    }
}
