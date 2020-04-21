/**
 * @file htab_find.c
 * @author Marek Filip (xfilip46), FIT BUT
 * @date 2020-Apr-21
 * @brief IJC-DU2, příklad b)
 * @details Function for returning an iterator to specified entry in hashtable.
 *          Function is in its own module so it can be changed in
 *          a statically built program.
 *          Compiled: gcc 9.3
 */

#include "private.h"

// Returns an iterator containing the specified key, htab_end(t) if not found.
htab_iterator_t htab_find(htab_t *t, htab_key_t key) {
    if (htab_size(t) == 0) {
        return htab_end(t); // no entries to look for
    }
    htab_iterator_t it = get_iterator_from_key(t, key);
    // walk through each item in the bucket, for case when more items are present
    if (htab_iterator_valid(it)) {
        size_t old_idx = it.idx;
        while (it.idx == old_idx) {
            if (strcmp(htab_iterator_get_key(it), key) == 0) {
                return it;
            }
            it = htab_iterator_next(it);
        }
    }
    // item not found
    return htab_end(t);
}
