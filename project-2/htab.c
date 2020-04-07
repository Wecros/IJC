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

#include "htab.h"

// rozptylovací (hash) funkce (stejná pro všechny tabulky v programu)
// pokud si v programu definujete stejnou funkci, použije se ta vaše
size_t htab_hash_fun(htab_key_t str) {

}

// funkce pro práci s tabulkou:
// konstruktor tabulky
htab_t *htab_init(size_t n) {

}
// počet záznamů v tabulce
size_t htab_size(const htab_t * t) {

}
// velikost pole
size_t htab_bucket_count(const htab_t * t) {

}

// hledání
/*
V tabulce  t  vyhledá záznam odpovídající řetězci  key  a
    - pokud jej nalezne, vrátí iterátor na záznam
    - pokud nenalezne, vrátí iterátor htab_end(t)
*/
htab_iterator_t htab_find(htab_t * t, htab_key_t key) {

}
/*
V tabulce  t  vyhledá záznam odpovídající řetězci  key  a
    - pokud jej nalezne, vrátí iterátor na záznam
    - pokud nenalezne, automaticky přidá záznam a vrátí iterátor
*/
htab_iterator_t htab_lookup_add(htab_t * t, htab_key_t key) {

}

// ruší zadaný záznam
/*
ruší zadaný záznam v tabulce (dávejte pozor na zneplatnění it touto
operací - je to potenciální problém i v C++)
*/
void htab_erase(htab_t * t, htab_iterator_t it) {

}

// iterátor na první záznam
/* vrací iterátor odkazující na první záznam */
htab_iterator_t htab_begin(const htab_t * t) {

}
// iterátor _za_ poslední záznam
/* vrací iterátor označující (neexistující) první záznam za koncem */
htab_iterator_t htab_end(const htab_t * t) {

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
void htab_clear(htab_t * t) {

}
// destruktor tabulky
void htab_free(htab_t * t) {

}