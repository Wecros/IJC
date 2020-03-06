#include <stdio.h>
#include <math.h>
#include <assert.h>

#include "bitset.h"

#define BITSIZE 100
#define SIZE 50000000

void sieve(const size_t el_count) {

    bitset_create(bitarr, 100);

    for (size_t i = 1; i < el_count; i++) {
        bitset_setbit(bitarr, i, 1);
    }

    for (size_t i = 2; i < sqrt(el_count); i++) {
        if (bitset_getbit(bitarr, i)) {
            for (size_t j = i * i; j < el_count; j += i) {
                bitset_setbit(bitarr, j, 0);
            }
        }
    }

    for (size_t i = 0; i < bitset_size(bitarr); i++) {
        if (bitset_getbit(bitarr, i)) {
            printf("Prime: %d\n", i);
        }
    }

    return bitarr;
}

/**
 * @brief Algorithm for getting prime numbers 
 */
void pepe_sieve(const size_t el_count) {
    bitset_create(bitarr, SIZE);
 
    bitset_setbit(bitarr, 0, 1);
    bitset_setbit(bitarr, 1, 1);

    for (size_t i = 2; i <= sqrt(el_count); i++) {
        if (!bitset_getbit(bitarr, i)) {
            for (size_t j = i*i; j <= el_count; j += i) {
                bitset_setbit(bitarr, j, 1);
            }
        }
    }

    for (size_t i = el_count, n = 5; (i > 0) && n; i--) {
        if (!bitset_getbit(bitarr, i)) {
            printf("Prime: %d\n", i);
            n--;
        }
    }
}

int main() {
    const unsigned long size = 3;
    

    bitset_create(bitarr, BITSIZE);

    const size_t bitarr_len = sizeof(bitarr) / sizeof(bitarr[0]);
    printf("bitarr len: %lu\n", bitarr_len);
    // static_assert(bitarr_len == 3, "bitarr is not right");

    for (size_t i = 0; i < bitarr_len; i++) {
        printf("arr[%lu]: %lu\n", i, bitarr[i]);
    }

    for (bitset_index_t i = 0; i < 32; i++) {
        bitset_setbit(bitarr, i, 1);
    }

    for (bitset_index_t i = 64; i < 96; i++) {
        bitset_setbit(bitarr, i, 1);
    }

    bitset_setbit(bitarr, 87, 1);
    bitset_setbit(bitarr, 87, 0);
    bitset_setbit(bitarr, 86, 1);
    bitset_setbit(bitarr, 88, 1);

    for (bitset_index_t i = 0; i < 100; i++) {
        printf("val [%lu]: %u\n", i, bitset_getbit(bitarr, i));
    }

    for (size_t i = 1; i < size; i++) {
        printf("ultimate val: %lu\n", bitarr[i]);
    }
    printf("bitsize: %lu\n", bitset_size(bitarr));

    // sieve(100);
    printf("\n");
    pepe_sieve(SIZE);

    return 0;
}