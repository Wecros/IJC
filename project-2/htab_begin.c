/**
 * @file htab_begin.c
 * @author Marek Filip (xfilip46), FIT BUT
 * @date 2020-Apr-15
 * @brief IJC-DU2, příklad b)
 * @details Getter for getting iterator pointing to the first nonnull entry.
 *          Function is in its own module so it can be changed in
 *          a statically built program.
 *          Compiled: gcc 9.3
 */

#include "htab.h"
#include "private.h"

// Returns an iterator pointing to the first nonnull entry in hastable.
htab_iterator_t htab_begin(const htab_t *t) {
    htab_iterator_t it = iterator_init(t, 0);
    // go through indeces until you find an entry, return htab_end if not found
    while (it.ptr == NULL) {
        htab_iterator_next(it);
    }
    return it;
}
