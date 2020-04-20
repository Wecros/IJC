/**
 * @file htab_iterator_next.c
 * @author Marek Filip (xfilip46), FIT BUT
 * @date 2020-Apr-15
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
        // there might be more items in this bucket
        if (it.ptr->next != NULL) {
            it.ptr = it.ptr->next;
        } else {
            it.ptr = NULL;
        }
    }
    // moving to the next bucket with an entry
    while (it.idx < htab_bucket_count(it.t) && !htab_iterator_valid(it)) {
        it.idx++;
        if (it.t->items[it.idx] != NULL) {
            it.ptr = it.t->items[it.idx];
        } else {
            it = htab_end(it.t);
        }
    }
    if (it.idx >= htab_bucket_count(it.t)) {
        it = htab_end(it.t); // end of hashtable
    }

    return it;
}
