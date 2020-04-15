/**
 * @file htab_clear.c
 * @author Marek Filip (xfilip46), FIT BUT
 * @date 2020-Apr-15
 * @brief IJC-DU2, příklad b)
 * @details Function for deleting every entry in a hashtable.
 *          Function is in its own module so it can be changed in
 *          a statically built program.
 *          Compiled: gcc 9.3
 */

#include "htab.h"
#include "private.h"

// Removes all entries from passed hashtable.
void htab_clear(htab_t *t) {
    // For bucket in hashtable, for item in bucket, free item
    for (size_t i = 0; i < t->arr_size - 1; i++) {
        for (htab_item_t *item = t->items[i]; item != NULL ; item = item->next) {
            item_free(item);
        }
    } 
    t->size = 0; // set entry count to 0
}
