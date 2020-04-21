/**
 * @file private.h
 * @author Marek Filip (xfilip46), FIT BUT
 * @date 2020-Apr-15
 * @brief IJC-DU2, příklad b)
 * @details Module file for defining functions.
 *          Compiled: gcc 9.3
 */

#include <stdio.h> // TODO: remove
#include <string.h>

#include "private.h"

// Extern the inline functions from 'htab.h'
extern bool htab_iterator_valid(htab_iterator_t it);
extern bool htab_iterator_equal(htab_iterator_t it1, htab_iterator_t it2);

htab_item_t *item_init(htab_t *t, htab_key_t key) {
    htab_item_t *item = (htab_item_t *) malloc(sizeof(htab_item_t));
    char *keymem = malloc(strlen(key) + sizeof(char));
    if (item == NULL || keymem == NULL) {
        return NULL;
    }
    strcpy(keymem, key);
    item->key = keymem;
    item->count = 1;
    item->next = NULL;
    t->size++;  // increment the entry count
    return item;
}

void item_free(htab_t *t, htab_item_t *item) {
    item->count = 0;
    item->next = NULL;
    free((char *) item->key);  // free the key pointer, casted
    free(item);
    t->size--;  // decerement the entry count
}

htab_iterator_t iterator_init(const htab_t *t, const size_t idx) {
    htab_iterator_t it = { t->items[idx], t, idx };
    if (idx >= htab_bucket_count(t)) {
        it.ptr = NULL;
    }
    return it;
}

htab_iterator_t get_iterator_from_key(const htab_t *t, htab_key_t key) {
    const unsigned hash = htab_hash_fun(key);
    const unsigned idx = hash % htab_bucket_count(t);
    return iterator_init(t, idx);
}
