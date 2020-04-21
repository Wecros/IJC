/**
 * @file htab_free.c
 * @author Marek Filip (xfilip46), FIT BUT
 * @date 2020-Apr-21
 * @brief IJC-DU2, příklad b)
 * @details Destructor for hashtable.
 *          Function is in its own module so it can be changed in
 *          a statically built program.
 *          Compiled: gcc 9.3
 */

#include "private.h"

// Frees the hashtable
void htab_free(htab_t *t) {
    if (htab_size(t) > 0) {
        htab_clear(t);
    }
    free(t);
}
