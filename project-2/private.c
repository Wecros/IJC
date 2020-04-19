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
    char *keymem = malloc(strlen(key) + sizeof(char));
    if (item == NULL || keymem == NULL) {
        return NULL;
    }
    strcpy(keymem, key);
    item->key = keymem;
    item->count = 1;
    item->next = NULL;
    return item;
}

htab_iterator_t iterator_init(const htab_t *t, size_t idx) {
    htab_iterator_t it = { t->items[idx], t, idx };
    if (idx >= t->arr_size) {
        it.ptr = NULL;
    }
    return it;
}

void htab_output(const htab_t *t) {
    htab_iterator_t it = htab_begin(t);
    while (it.idx < htab_bucket_count(t)) {
        if (htab_iterator_valid(it)) {
            printf("%s\t%d\n", htab_iterator_get_key(it),
                htab_iterator_get_value(it));
            it = htab_iterator_next(it);
            while (htab_iterator_valid(it)) {
                printf("%s\t%d\n", htab_iterator_get_key(it),
                    htab_iterator_get_value(it));
                it = htab_iterator_next(it);
            }
        }

        it = htab_iterator_next(it); // go to next iterator
    }
}

// nonessential, for debug, prints the hashtable
void htab_dump(const htab_t *t) {
    htab_iterator_t it = htab_begin(t);
    while (it.idx < htab_bucket_count(t)) {
        if (htab_iterator_valid(it)) {
            printf("[bucket %4ld]: %s:%d", it.idx, htab_iterator_get_key(it),
                htab_iterator_get_value(it));
            it = htab_iterator_next(it);
            while (htab_iterator_valid(it)) {
                printf("|%s:%d", htab_iterator_get_key(it),
                    htab_iterator_get_value(it));
                it = htab_iterator_next(it);
            }
            printf("\n");
        }

        it = htab_iterator_next(it); // go to next iterator
    }
}
