/**
 * @file private.h
 * @author Marek Filip (xfilip46), FIT BUT
 * @date 2020-Apr-15
 * @brief IJC-DU2, příklad b)
 * @details Module file for defining functions.
 *          Compiled: gcc 9.3
 */

#include "private.h"

htab_item_t *item_init(htab_key_t key) {
    htab_item_t *item = malloc(sizeof(htab_item_t *));
    item->key = key;
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
