/**
 * @file private.h
 * @author Marek Filip (xfilip46), FIT BUT
 * @date 14/Apr/2020
 * @brief IJC-DU2, příklad b)
 * @details Header file for defining private structs and functions.
 *          Compiled: gcc 9.3
 */

#include <string.h>  // size_t 

#include "htab.h"

struct htab_item {
    char *key;
    size_t count;
    struct htab_item *next;
};

struct htab {
    struct htab_item **items;
};
