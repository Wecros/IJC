#include <stdio.h>
#include <time.h>

#include "bitset.h"
#include "eratosthenes.c"

#define SIZE 100  // TODO: '-100' - compile error
#define SMALL_SIEVE 100
#define BIG_SIEVE 500000000

// extern bitset_free;
// extern bitset_size;
// extern bitset_setbit;
// extern bitset_getbit;

void test() {
    bitset_create(bitarr, SIZE);
    // bitset_alloc(bitarr, SIZE);

    const size_t bitarr_len = sizeof(bitarr) / sizeof(bitarr[0]);
    printf("bitarr len: %lu\n", bitarr_len);
    // static_assert(bitarr_len == 3, "bitarr is not right");

    for (size_t i = 0; i < bitarr_len; i++) {
        printf("arr[%lu]: %lu\n", i, (bitset_index_t) bitarr[i]);
    }

    for (bitset_index_t i = 0; i < 32; i++) {
        bitset_setbit(bitarr, i, 1);
    }

    // for (bitset_index_t i = 64; i < 96; i++) {
    //     bitset_setbit(bitarr, i, 1);
    // }

    bitset_setbit(bitarr, 87, 1);
    bitset_setbit(bitarr, 87, 0);
    bitset_setbit(bitarr, 86, 1); 
    bitset_setbit(bitarr, 88, 1);

 
    for (bitset_index_t i = 0; i < 100; i++) {
        printf("val [%lu]: %u\n", i, bitset_getbit(bitarr, i));
    }

    for (size_t i = 1; i < bitarr_len; i++) {
        printf("ultimate val: %lu\n", (bitset_index_t) bitarr[i]);
    }
    printf("bitsize: %lu\n", (bitset_index_t) bitset_size(bitarr));
    printf("\n");
    // bitset_free(bitarr);
}

int main() {
    const size_t start = clock();  // program's time start value

    // test();

    // bitset_create(bitarr, SMALL_SIEVE);
    bitset_create(bitarr, BIG_SIEVE);
    sieve(bitarr);

    fprintf(stderr, "Time=%.3g\n", (double)(clock()-start)/CLOCKS_PER_SEC);
    return 0;
}
