/**
 * @file htab_free.c
 * @author Marek Filip (xfilip46), FIT BUT
 * @date 2020-Apr-15
 * @brief IJC-DU2, příklad b)
 * @details Destructor for hashtable.
 *          Function is in its own module so it can be changed in
 *          a statically built program.
 *          Compiled: gcc 9.3
 */

#include <stdlib.h>
#include "htab.h"

// Frees the hashtable
void htab_free(htab_t *t) {
    htab_clear(t);
    free(t);
}
