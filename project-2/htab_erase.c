/**
 * @file htab_erase.c
 * @author Marek Filip (xfilip46), FIT BUT
 * @date 2020-Apr-21
 * @brief IJC-DU2, příklad b)
 * @details Remove a specified entry from hashtable.
 *          Function is in its own module so it can be changed in
 *          a statically built program.
 *          Compiled: gcc 9.3
 */

#include "private.h"

// Removes a specified entry from hashtable, doesn't change the iterator.
// Function redirects previous pointer to keep the list intact.
void htab_erase(htab_t *t, htab_iterator_t it) {
    // same hash tables and entry exists
    if (htab_iterator_valid(it) && t == it.t) {
        htab_iterator_t prev = htab_end(t);
        htab_iterator_t del_it = it;
        htab_iterator_t it = iterator_init(t, del_it.idx);
        // printf("%d:%d\n", it.idx, del_it.idx);
        while (it.idx == del_it.idx) {
            // printf("Coming through. %s: %d, %s: %d\n", it.ptr->key, it.ptr->count, del_it.ptr->key, del_it.ptr->count);
            if (htab_iterator_equal(it, del_it)) {
                // printf("Deleting.\n");
                if (it.ptr->next != NULL && htab_iterator_valid(prev)){
                    // relink the next entry to the previous on
                    // printf("\tRelinking.\n");
                    prev.ptr->next = it.ptr->next;
                } else if (htab_iterator_valid(prev)) {  // destroy the link of the previous pointer
                    // printf("\tDestroying link.\n");
                    prev.ptr->next = NULL;
                } else {
                    if (it.ptr->next != NULL) {
                        // printf("\tBase pointing to the next one.\n");
                        t->items[it.idx] = it.ptr->next;
                    }
                }
                item_free(t, del_it.ptr);  // erase the entry
                return;
            }
            prev = it;
            it = htab_iterator_next(it);
        }
    }
}
