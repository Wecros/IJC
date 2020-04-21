/**
 * @file htab_iterator_next.c
 * @author Marek Filip (xfilip46), FIT BUT
 * @date 2020-Apr-21
 * @brief IJC-DU2, příklad b)
 * @details Function for moving iterator to the next entry in hashtable.
 *          Function is in its own module so it can be changed in
 *          a statically built program.
 *          Compiled: gcc 9.3
 */

#include "private.h"

// Moves the iterator to the next entry in a hashtable.
htab_iterator_t htab_iterator_next(htab_iterator_t it) {
    if (htab_iterator_valid(it)) {
        // there are more items in this bucket
        it.ptr = it.ptr->next;
    }
    // moving to the next bucket with an entry
    while (!htab_iterator_valid(it) && it.idx < htab_bucket_count(it.t)) {
        it.idx++;
        it.ptr = it.t->items[it.idx];
    }
    if (it.idx >= htab_bucket_count(it.t)) {
        it = htab_end(it.t); // end of hashtable
    }

    return it;
}
