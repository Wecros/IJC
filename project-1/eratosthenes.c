/**
 * @file eratosthenes.c
 * @author Marek Filip (xfilip46), FIT BUT
 * @date 19/Mar/2020
 * @brief IJC-DU1, příklad a)
 * @details Eratosthenes sieve is an algorithm for computing prime numbers.
 *          We use bitset array for the implementation.
 *          Compiled: gcc 9.2
 */

#include <stdio.h>
#include <math.h>

#include "eratosthenes.h"

void sieve(bitset_t array) {
    bitset_setbit(array, 0, 1);
    bitset_setbit(array, 1, 1);

    for (bitset_index_t i = 2; i < sqrt(bitset_size(array)); i++) {
        if (!bitset_getbit(array, i)) {
            for (bitset_index_t j = i*i; j < bitset_size(array); j += i) {
                if (j == bitset_size(array)) {
                    printf("not allowed\n");
                }
                bitset_setbit(array, j, 1);
            }
        }
    }
}
