/**
 * @file htab_clear.c
 * @author Marek Filip (xfilip46), FIT BUT
 * @date 2020-Apr-21
 * @brief IJC-DU2, příklad b)
 * @details Function for deleting every entry in a hashtable.
 *          Function is in its own module so it can be changed in
 *          a statically built program.
 *          Compiled: gcc 9.3
 */

#include "private.h"

// Removes all entries from passed hashtable.
void htab_clear(htab_t *t) {
    // go through each entry and erase it
    htab_iterator_t it = htab_begin(t);
    while (!htab_iterator_equal(it, htab_end(t))) {
        htab_iterator_t next = htab_iterator_next(it);
        htab_erase(t, it);
        it = next;
    }
}
