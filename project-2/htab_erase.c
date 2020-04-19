/**
 * @file htab_erase.c
 * @author Marek Filip (xfilip46), FIT BUT
 * @date 2020-Apr-15
 * @brief IJC-DU2, příklad b)
 * @details Remove a specified entry from hashtable.
 *          Function is in its own module so it can be changed in
 *          a statically built program.
 *          Compiled: gcc 9.3
 */

#include <stdlib.h>
#include "htab.h"
#include "private.h"

// Removes a specified entry from hashtable, doesn't change the iterator.
void htab_erase(htab_t *t, htab_iterator_t it) {
    // same hash tables and entry exists
    if (htab_iterator_valid(it) && t == it.t) {
        it.ptr->count = 0;
        it.ptr->next = NULL;
        free((char *) it.ptr->key);  // free the key pointer, casted
        free(it.ptr);
    }
}
