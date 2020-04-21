/**
 * @file io.c
 * @author Marek Filip (xfilip46), FIT BUT
 * @date 2020-Apr-15
 * @brief IJC-DU2, příklad b)
 * @details File for defining input-output functions.
 *          Compiled: gcc 9.3
 */

#include <ctype.h>    // isspace()
#include <string.h>   // strcpy()
#include <stdbool.h>  // bool

#include "io.h"


/*
čte jedno slovo ze souboru f do zadaného pole znaků
a vrátí délku slova (z delších slov načte prvních max-1 znaků,
a zbytek přeskočí). Funkce vrací EOF, pokud je konec souboru.
Umístěte ji do zvláštního modulu "io.c" (nepatří do knihovny).
Poznámka: Slovo je souvislá posloupnost znaků oddělená isspace znaky.

Omezení: řešení v C bude tisknout jinak uspořádaný výstup
    a je povoleno použít implementační limit na maximální
    délku slova (např. 127 znaků), delší slova se ZKRÁTÍ a program
    při prvním delším slovu vytiskne varování na stderr (max 1 varování).


Poznámka: Vhodný soubor pro testování je například seznam slov
    v souboru /usr/share/dict/words
    nebo texty z http://www.gutenberg.org/
    případně výsledek příkazu:  "seq 1000000 2000000|shuf"
*/


/**
 * @brief Loads the word from specified stream and saves it to
 *        the specified character pointer, max length needed.
 * @param s Pointer to a char variable.
 * @param max Maximum length of a word.
 * @param f Pointer to file stream.
 * @returns Returns EOF (-1) if EOF encountered
 *          0 if word loaded without problems
 *          1 if word over limit
 */
int get_word(char *s, int max, FILE *f) {
    char c;
    bool charFound = false;
    int charIndex = 0;
    static bool warningPrinted = false;  // static, print only one warning

    while ((c = fgetc(f)) != EOF) {
        if (charIndex >= max && !isspace(c)) {
            if (!warningPrinted) {
                warningPrinted = true;
                fprintf(stderr, "Encountered word longer than 127 characters, "
                                "skipping the rest of the word.\n");
            }
            // skip the rest of word
            while (!isspace(c) && c != EOF) {
                c = fgetc(f);
            }
            s[charIndex] = '\0';  // we need to terminate the string
            return 1;
        } else if (isspace(c) && charFound) {
            break;  // break out of the loop if char is space and word found
        } else if (!isspace(c)) {
            // character is something other than space
            charFound = true;
            s[charIndex] = c;
            charIndex++;
        }
    }
    s[charIndex] = '\0';  // we need to terminate the string

    if (c == EOF) {
        return EOF;
    } else {
        return 0;
    }
}
