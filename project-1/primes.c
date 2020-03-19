#include <stdio.h>
#include <time.h>

#include "eratosthenes.h"
#include "error.h"

#define SMALL_SIEVE 100
#define BIG_SIEVE 500000001


void printPrimes(bitset_t primes) {
    int arr[10];  
    for (size_t i = bitset_size(primes) - 1,  n = 10; (i > 0) && n; i--) {
        if (!bitset_getbit(primes, i)) {
            arr[n-1] = i;
            n--;
        }
    }
    for (size_t i = 0; i < 10; i++) {
        printf("%d\n", arr[i]); 
    }
}

int main() {
    const size_t start = clock();  // program's time start value 
    bitset_create(bitarr, BIG_SIEVE); 

    sieve(bitarr);
    printPrimes(bitarr);

    fprintf(stderr, "Time=%.3g\n", (double)(clock()-start)/CLOCKS_PER_SEC);
    return 0;
}
