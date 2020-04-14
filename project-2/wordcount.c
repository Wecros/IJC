/**
 * @file wordcount.c
 * @author Marek Filip (xfilip46), FIT BUT
 * @date 07/Apr/2020
 * @brief IJC-DU2, příklad b)
 * @details The assigment is to rewrite a C++ program to pure C.
 *          The program counts the frequency of words in the output text.
 *          Word counts as anything seperated by whitespace.
 *          Program relies on hashtable implementation.
 *          Compiled: gcc 9.3
 */

/*
Things to look for:
    types of parameters in fuctions, good usage of 'const'
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "htab.h"

#define TABLE_SIZE 100000

int main() {
    htab_t *t;
    htab_t *t2;
    bool b;
    htab_iterator_t ptr;

    htab_t *htab = htab_init(TABLE_SIZE);
    htab_key_t htab_key = "wecros"; 

    printf("%d\n", htab_hash_fun(htab_key));

    /*
    using namespace std;
    unordered_map<string,int> m;  // asociativní pole
                    // mapuje klíč/string na hodnotu/int
    string word;
    while (cin >> word) // čtení slova (jako scanf "%s", ale bezpečné)
        m[word]++;      // počítání výskytů slova (zvýší hodnotu pro
                        // zadaný klíč/slovo pzokud záznam existuje,
                        // jinak vytvoří nový záznam s hodnotou 0 a
                        // tu operace ++ zvýší na 1)

    for (auto &mi: m)   // pro všechny prvky kontejneru m
        cout << mi.first << "\t" << mi.second << "\n";
        //      klíč/slovo          hodnota/počet
        // prvky kontejneru typu "map" jsou dvojice (klíč,hodnota)
    */

   return EXIT_SUCCESS;
}
