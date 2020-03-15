#include <stdio.h>
#include <time.h>

#include "bitset.h"
#include "eratosthenes.h"
#include "error.h"

#define SIZE 100  // TODO: '-100' - compile error
#define SMALL_SIEVE 100
#define BIG_SIEVE 500000000

#ifdef USE_INLINE 
extern bitset_free; 
extern bitset_size; 
extern bitset_setbit;
extern bitset_getbit; 
#endif 
 
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
    // bitset_alloc(bitarr, SMALL_SIEVE);
    bitset_create(bitarr, BIG_SIEVE); 

    sieve(bitarr);
    printPrimes(bitarr);

    fprintf(stderr, "Time=%.3g\n", (double)(clock()-start)/CLOCKS_PER_SEC);

    // error_exit("bitset_getbit: Index %lu mimo rozsah 0..%lu\n", (unsigned long) 10, (unsigned long) 9);
    
    return 0;
}
