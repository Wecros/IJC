/**
 * @file htab_bucket_count.c
 * @author Marek Filip (xfilip46), FIT BUT
 * @date 2020-Apr-15
 * @brief IJC-DU2, příklad b)
 * @details Getter for getting the bucket size of hashtable.
 *          Function is in its own module so it can be changed in
 *          a statically built program.
 *          Compiled: gcc 9.3
 */

#include <string.h>

#include "htab.h"
#include "private.h"

// Returns bucket count of passed hashtable.
size_t htab_bucket_count(const htab_t *t) {
    return t->arr_size;
}
