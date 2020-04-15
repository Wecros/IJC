/**
 * @file htab_end.c
 * @author Marek Filip (xfilip46), FIT BUT
 * @date 2020-Apr-15
 * @brief IJC-DU2, příklad b)
 * @details Get iterator pointing to nonexisting entry at the end of hastable.
 *          Function is in its own module so it can be changed in
 *          a statically built program.
 *          Compiled: gcc 9.3
 */

#include "htab.h"
#include "private.h"

// Returns iterator pointing to nonexisting entry at the end of hashtable.
htab_iterator_t htab_end(const htab_t *t) {
    return iterator_init(t, t->arr_size);  // idx equals to the bucket count
}
