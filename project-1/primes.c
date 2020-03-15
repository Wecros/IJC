#include <stdio.h>
#include <time.h>

#include <limits.h>
#include <math.h>

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

void test(bitset_t array) {
    // const size_t array_len = sizeof(array) / sizeof(array[0]);
    const size_t array_len = 3;
    printf("array len: %lu\n", array_len);

    for (size_t i = 0; i < array_len; i++) {
        printf("arr[%lu]: %lu\n", i, (bitset_index_t) array[i]);
    }

    for (bitset_index_t i = 0; i < 32; i++) {
        bitset_setbit(array, i, 1);
    }

    for (bitset_index_t i = 73; i < 94; i++) {
        bitset_setbit(array, i, 1);
    }

    bitset_setbit(array, 87, 1);
    bitset_setbit(array, 87, 0);
    bitset_setbit(array, 86, 1); 
    bitset_setbit(array, 88, 1);

 
    for (bitset_index_t i = 0; i < 100; i++) {
        printf("val [%lu]: %u\n", i, bitset_getbit(array, i));
    }

    for (size_t i = 1; i < array_len; i++) {
        printf("ultimate val: %lu\n", (bitset_index_t) array[i]);
    }
    printf("bitsize: %lu\n", (bitset_index_t) bitset_size(array));
}

int main() {
    const size_t start = clock();  // program's time start value
    // bitset_alloc(bitarr, SMALL_SIEVE);
    bitset_create(bitarr, SMALL_SIEVE); 

    // test(bitarr);

    sieve(bitarr);

    fprintf(stderr, "Time=%.3g\n", (double)(clock()-start)/CLOCKS_PER_SEC);

    // error_exit("bitset_getbit: Index %lu mimo rozsah 0..%lu\n", (unsigned long) 10, (unsigned long) 9);
    
    return 0;
}
