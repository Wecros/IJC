/**
 * @file htab_lookup_add.c
 * @author Marek Filip (xfilip46), FIT BUT
 * @date 2020-Apr-15
 * @brief IJC-DU2, příklad b)
 * @details Lookup or add a specified entry to hashtable.
 *          Function is in its own module so it can be changed in
 *          a statically built program.
 *          Compiled: gcc 9.3
 */

#include "htab.h"
#include "private.h"

// Returns an iterator containing the specified key. Creates a new entry 
// in the hashtable and returns appropriate iterator if key not found.
htab_iterator_t htab_lookup_add(htab_t *t, htab_key_t key) {
    const unsigned hash = htab_hash_fun(key);
    const unsigned idx = hash % htab_bucket_count(t);
    htab_iterator_t it = iterator_init(t, idx); // look up the iterator
    // walk through each item in the bucket, for case when more items are present
    while (htab_iterator_valid(it)) {
        if (strcmp(htab_iterator_get_key, key) == 0) {
            return it;
        }
        htab_iterator_next(it);
    }
    // item not found, create a new one, return iterator
    it.ptr = item_init(key);
    t->items[idx] = it.ptr;
    return it;
}
