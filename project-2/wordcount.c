/**
 * @file wordcount.c
 * @author Marek Filip (xfilip46), FIT BUT
 * @date 2020-Apr-15
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
#include "private.h"
#include "io.h"

// defined this size so the disrtibution is alright and size is not very large
#define TABLE_SIZE 100000

int main() {
    htab_t *t = htab_init(TABLE_SIZE);
    htab_key_t htab_key = "pyro";

    printf("%ld\n", htab_hash_fun(htab_key));

    htab_lookup_add(t, "a");
    htab_lookup_add(t, "b");
    htab_lookup_add(t, "c");
    htab_lookup_add(t, "pizza");
    htab_lookup_add(t, "pyro");
    htab_lookup_add(t, "kalix");
    htab_lookup_add(t, "wecros");

    htab_dump(t);


    int retcode = 0;
    while (retcode != EOF) {
        char word[MAX_WORD_LEN] = "\0";
        retcode = get_word(word, MAX_WORD_LEN, stdin);
        // printf("%s ", word);

        // htab_lookup_add(t, word);
        htab_iterator_t iter = htab_find(t, word);
        if (htab_iterator_equal(iter, htab_end(t))) {
            htab_lookup_add(t, word);
        } else {
            iter.ptr->count++;
        }
    }
    printf("\n");

    htab_dump(t);

    // for (size_t i = 0; i < 100; i++) {
    //     char word[MAX_WORD_LEN] = "\0";
    //     retcode = get_word(word, MAX_WORD_LEN, stdin);
    //     printf("%s ", word);
    // }

    printf("End of wordcount.c\n");
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
