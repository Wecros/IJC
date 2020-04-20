/**
 * @file htab_iterator_set_value.c
 * @author Marek Filip (xfilip46), FIT BUT
 * @date 2020-Apr-15
 * @brief IJC-DU2, příklad b)
 * @details Function for setting an item's count value via iterator.
 *          Function is in its own module so it can be changed in
 *          a statically built program.
 *          Compiled: gcc 9.3
 */

#include "private.h"

// Set the count value of an entry, returns passed value. Entry must exist.
htab_value_t htab_iterator_set_value(htab_iterator_t it, htab_value_t val) {
    it.ptr->count = val;
    return it.ptr->count;
}
