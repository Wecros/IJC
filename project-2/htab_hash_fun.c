/**
 * @file htab_hash_fun.c
 * @author Marek Filip (xfilip46), FIT BUT
 * @date 2020-Apr-15
 * @brief IJC-DU2, příklad b)
 * @details Hashing function for the hashtable.
 *          Function is in its own module so it can be changed in
 *          a statically built program.
 *          Compiled: gcc 9.3
 */

#include <string.h>
#include <inttypes.h>

#include "htab.h"

// Uniform distribution hash function (sdbm) for hashtable, returns a hash num
size_t htab_hash_fun(htab_key_t str) {
    uint32_t h = 0;  // must have 32 bits
    const unsigned char *p;
    for (p = (const unsigned char *) str; *p != '\0'; p++) {
        h = 65599 * h + *p;
    }
    return h; 
}
