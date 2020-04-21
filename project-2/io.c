/**
 * @file io.c
 * @author Marek Filip (xfilip46), FIT BUT
 * @date 2020-Apr-21
 * @brief IJC-DU2, příklad b)
 * @details File for defining input-output functions.
 *          Compiled: gcc 9.3
 */

#include <stdio.h>    // input, output
#include <ctype.h>    // isspace()
#include <stdbool.h>  // bool

#include "io.h"

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
