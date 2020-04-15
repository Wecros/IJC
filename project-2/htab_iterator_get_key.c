/**
 * @file htab_iterator_get_key.c
 * @author Marek Filip (xfilip46), FIT BUT
 * @date 2020-Apr-15
 * @brief IJC-DU2, příklad b)
 * @details Function for getting an item's key value via iterator.
 *          Function is in its own module so it can be changed in
 *          a statically built program.
 *          Compiled: gcc 9.3
 */

#include "htab.h"
#include "private.h"

// Returns key value of an entry via iterator, NULL if key does not exist.
htab_key_t htab_iterator_get_key(htab_iterator_t it) {
    if (!htab_iterator_valid(it)) {
        return NULL;
    }
    return it.ptr->key;
}
