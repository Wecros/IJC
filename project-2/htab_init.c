/**
 * @file htab_init.c
 * @author Marek Filip (xfilip46), FIT BUT
 * @date 2020-Apr-15
 * @brief IJC-DU2, příklad b)
 * @details Constructor for hashtable.
 *          Function is in its own module so it can be changed in
 *          a statically built program.
 *          Compiled: gcc 9.3
 */

#include "private.h"

// Initializes a hashatble with passed bucket count.
htab_t *htab_init(size_t n) {
    // allocate hashtable
    htab_t *hashtable = (htab_t *) malloc(sizeof(htab_t) + sizeof(htab_item_t) * n);
    if (hashtable == NULL) {
        return NULL;  // allocation of memory failed
    }
    hashtable->size = 0;
    hashtable->arr_size = n; // set the hashtable bucket count

    // set each item to NULL; n + 1 is needed for htab_end(t)
    for (size_t i = 0; i < n + 1; i++) {
        hashtable->items[i] = NULL;
    }
    return hashtable;
}
