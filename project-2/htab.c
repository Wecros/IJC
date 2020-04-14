/**
 * @file htab.c
 * @author Marek Filip (xfilip46), FIT BUT
 * @date 07/Apr/2020
 * @brief IJC-DU2, příklad b)
 * @details
 *          Compiled: gcc 9.3
 */

/*
- Když htab_init nebo htab_lookup_add nemohou alokovat paměť,
vrací NULL nebo nevalidní iterátor htab_end
(a uživatel musí testovat výsledek těchto operací)
*/

#include <inttypes.h>  // uint32_t
#include <string.h>    // size_t

#include "htab.h"
#include "private.h"

// rozptylovací (hash) funkce (stejná pro všechny tabulky v programu)
// pokud si v programu definujete stejnou funkci, použije se ta vaše
size_t htab_hash_fun(htab_key_t str) {
    uint32_t h = 0;     // musí mít 32 bitů
    const unsigned char *p;
    for (p = (const unsigned char*) str; *p != '\0'; p++) {
        h = 65599 * h + *p;
    }
    return h; 
}

// konstruktor tabulky
// funkce pro práci s tabulkou:
htab_t *htab_init(size_t n) {
    // allocate hashtable
    htab_t *hastable = malloc(sizeof(htab_t) + sizeof(struct htab_item) * n);
    // set the hashtable size
    hastable->size = 0;
    hastable->arr_size = 0;

    // set each item to NULL
    for (size_t i = 0; i < n; i++) {
        hastable->items[i] = NULL;
    }
    return hastable;
}
// počet záznamů v tabulce
size_t htab_size(const htab_t *t) {
    return t->size;
}
// velikost pole
size_t htab_bucket_count(const htab_t *t) {
    return t->arr_size;
}

// hledání
/*
V tabulce  t  vyhledá záznam odpovídající řetězci  key  a
    - pokud jej nalezne, vrátí iterátor na záznam
    - pokud nenalezne, vrátí iterátor htab_end(t)
*/
htab_iterator_t htab_find(htab_t *t, htab_key_t key) {
    const unsigned hash = htab_hash_fun(key);
    const unsigned slot = hash % t->size;
    // look up the iterator
    htab_iterator_t iter = { t->items[slot], t, slot };
    // no item found here
    if (iter.ptr == NULL) {
        return htab_end(t);
    }

    // walk through each item in the slot, for case when more items are present
    while (iter.ptr != NULL) {
        if (strcmp(iter.ptr->key, key) == 0) {
            return iter;
        }
        iter.ptr = iter.ptr->next;
    }
}
/*
V tabulce  t  vyhledá záznam odpovídající řetězci  key  a
    - pokud jej nalezne, vrátí iterátor na záznam
    - pokud nenalezne, automaticky přidá záznam a vrátí iterátor
*/
htab_iterator_t htab_lookup_add(htab_t *t, htab_key_t key) {
    const unsigned hash = htab_hash_fun(key);
    const unsigned slot = hash % t->size;
    // look up the iterator
    htab_iterator_t iter = { t->items[slot], t, slot }; 

    // walk through each item in the slot, for case when more items are present
    while (iter.ptr != NULL) {
        if (strcmp(iter.ptr->key, key) == 0) {
            return iter;
        }
        iter.ptr = iter.ptr->next;
    }

    // no item found here, slot is empty -> create a new one
    if (iter.ptr == NULL) {  // if statement not needed probably
        // TODO: make creating items into a function
        htab_item_t *item = malloc(sizeof(htab_item_t));
        item->key = key;
        item->count = 1;
        item->next = NULL;
        t->items[slot] = item;
        return iter;
    }
}

// ruší zadaný záznam
/*
ruší zadaný záznam v tabulce (dávejte pozor na zneplatnění it touto
operací - je to potenciální problém i v C++)
*/
void htab_erase(htab_t *t, htab_iterator_t it) {

}

// iterátor na první záznam
/* vrací iterátor odkazující na první záznam */
htab_iterator_t htab_begin(const htab_t *t) {
    
}
// iterátor _za_ poslední záznam
/* vrací iterátor označující (neexistující) první záznam za koncem */
htab_iterator_t htab_end(const htab_t *t) {

}

// iterátor++
/* 
posun iterátoru na další záznam v tabulce (nebo na htab_end(t))
Poznámka: toto dělá i C++ operátor ++ pro iterátory 
*/
htab_iterator_t htab_iterator_next(htab_iterator_t it) {

}

// čtení a zápis přes iterátor
/* vrací klíč, cíl musí existovat */
htab_key_t htab_iterator_get_key(htab_iterator_t it) {

}
/* vrací hodnotu, cíl musí existovat */
htab_value_t htab_iterator_get_value(htab_iterator_t it) {

}
/* přepisuje hodnotu, cíl musí existovat */
htab_value_t htab_iterator_set_value(htab_iterator_t it, htab_value_t val) {

}

// ruší všechny záznamy
void htab_clear(htab_t *t) {

}
// destruktor tabulky
void htab_free(htab_t *t) {

}
