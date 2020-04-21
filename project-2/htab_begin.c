/**
 * @file htab_begin.c
 * @author Marek Filip (xfilip46), FIT BUT
 * @date 2020-Apr-21
 * @brief IJC-DU2, příklad b)
 * @details Getter for getting iterator pointing to the first nonnull entry.
 *          Function is in its own module so it can be changed in
 *          a statically built program.
 *          Compiled: gcc 9.3
 */

#include "private.h"

// Returns an iterator pointing to the first nonnull entry in hastable.
htab_iterator_t htab_begin(const htab_t *t) {
    htab_iterator_t it = iterator_init(t, 0);
    htab_iterator_t end_it = htab_end(t);
    // go through indeces till you find entry, return htab_end if nothing found
    while (!htab_iterator_valid(it) && it.idx != end_it.idx) {
        it = htab_iterator_next(it);
    }
    return it;
}
