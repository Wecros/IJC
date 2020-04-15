/**
 * @file htab_find.c
 * @author Marek Filip (xfilip46), FIT BUT
 * @date 2020-Apr-15
 * @brief IJC-DU2, příklad b)
 * @details Function for returning an iterator to specified entry in hashtable.
 *          Function is in its own module so it can be changed in
 *          a statically built program.
 *          Compiled: gcc 9.3
 */

#include "htab.h"
#include "private.h"

// Returns an iterator containing the specified key, htab_end(t) if not found.
htab_iterator_t htab_find(htab_t *t, htab_key_t key) {
    const unsigned hash = htab_hash_fun(key);
    const unsigned idx = hash % htab_bucket_count(t);
    htab_iterator_t it = iterator_init(t, idx); // look up the iterator
    // walk through each item in the bucket, for case when more items are present
    while (it.ptr != NULL) {
        if (strcmp(htab_iterator_get_key(it), key) == 0) {
            return it;
        }
        htab_iterator_next(it);
    }
    // item not found
    return htab_end(t);
}
