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

#include "htab.h"
#include "private.h"

// Moves the iterator to the next entry in a hashtable.
htab_iterator_t htab_iterator_next(htab_iterator_t it) {
    if (it.idx < htab_bucket_count(it.t) - 1) {
        it.idx++;
        it.ptr = it.t->items[it.idx];
        return it;
    } 
    return htab_end(it.t);
}
