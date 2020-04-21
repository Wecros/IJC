/**
 * @file htab_size.c
 * @author Marek Filip (xfilip46), FIT BUT
 * @date 2020-Apr-21
 * @brief IJC-DU2, příklad b)
 * @details Getter for getting the count of entries in hashtable.
 *          Function is in its own module so it can be changed in
 *          a statically built program.
 *          Compiled: gcc 9.3
 */

#include "private.h"

// Returns a count of entries of the hashtable.
size_t htab_size(const htab_t *t) {
    return t->size;
}
