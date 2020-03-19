/**
 * @file steg-decode.c
 * @author Marek Filip (xfilip46), FIT BUT
 * @date 19/Mar/2020
 * @brief IJC-DU1, příklad b)
 * @details Program for decoding a hidden message in a ppm picture.
 *          The encoding is similar to the method of Steganography.
 *          Compiled: gcc 9.2
 * @see http://en.wikipedia.org/wiki/Steganography
 */

#include <stdio.h>
#include <limits.h>

#include "ppm.h"
#include "error.h"
#include "eratosthenes.h"

// find and decode the hidden message
void decode_and_print(bitset_t bitarr, struct ppm *p, unsigned data_size) {
    unsigned pos = 0;
    unsigned char byte = 0;
    for (bitset_index_t i = 23; i < data_size; i++) {
        if (!bitset_getbit(bitarr, i)) {
            unsigned char LSb = p->data[i] & 1;
            byte |= LSb << pos;

            pos++;
            if (pos == CHAR_BIT) {
                printf("%c", byte);
                if (byte == '\0') {
                    break;
                }
                pos = 0;
                byte = 0;
            }
        }
    }
    printf("\n");
}

int main(int argc, char *argv[]) {
    if (argc < 2 || argc > 2) {  // test arguments
        error_exit("Invalid arguments\n");
    }

    // try to load picture into the struct
    struct ppm *ppm = ppm_read(argv[1]);
    if (ppm == NULL) {
        error_exit("Obrázek nemohl být nahrán.\n");
    }

    // create bitset array according to ppm file
    unsigned data_size = 3 * ppm->xsize * ppm->ysize;
    bitset_alloc(primes, data_size);
    sieve(primes);
    decode_and_print(primes, ppm, data_size);

    // free the allocated memory
    bitset_free(primes);
    ppm_free(ppm);
    return 0;
}
