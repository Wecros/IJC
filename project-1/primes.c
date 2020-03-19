/**
 * @file primes.c
 * @author Marek Filip (xfilip46), FIT BUT
 * @date 19/Mar/2020
 * @brief IJC-DU1, příklad a)
 * @details Program that prints last 10 prime numbers of 500,000,000.
 *          Compiled: gcc 9.2
 */

#include <stdio.h>
#include <time.h>

#include "eratosthenes.h"
#include "error.h"

#define BIG_SIEVE 500000001
#define PRINT_COUNT 10

// print the last N prime numbers from primes array
void printPrimes(size_t count, bitset_t primes) {
    int arr[count];
    for (size_t i = bitset_size(primes) - 1,  n = count; (i > 0) && n; i--) {
        if (!bitset_getbit(primes, i)) {
            arr[n-1] = i;
            n--;
        }
    }
    for (size_t i = 0; i < count; i++) {
        printf("%d\n", arr[i]);
    }
}

int main() {
    const size_t start = clock();  // program's time start value
    bitset_create(bitarr, BIG_SIEVE);

    sieve(bitarr);
    printPrimes(PRINT_COUNT, bitarr);

    fprintf(stderr, "Time=%.3g\n", (double)(clock()-start)/CLOCKS_PER_SEC);
    return 0;
}
