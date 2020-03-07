#include <stdio.h>
#include <math.h>
#include <assert.h>

#include "bitset.h"

#define BITSIZE 100  // TODO: '-100' - compile error
#define SIZE 500000000

/**
 * @brief Algorithm for getting prime numbers 
 */
void sieve(const size_t el_count) {
    bitset_create(bitarr, SIZE);
    // bitset_alloc(bitarr, SIZE);
 
    bitset_setbit(bitarr, 0, 1);
    bitset_setbit(bitarr, 1, 1);

    for (size_t i = 0; i < sqrt(el_count); i++) {
        if (!bitset_getbit(bitarr, i)) {
            for (size_t j = i*i; j < el_count; j += i) {
                if (j == bitset_size(bitarr)) {
                    printf("not allowed\n");
                }
                bitset_setbit(bitarr, j, 1);
            }
        }
    }

    for (size_t i = el_count - 1, n = 5; (i > 0) && n; i--) {
        if (!bitset_getbit(bitarr, i)) {
            // printf("Prime: %d\n", i);
            printf("%d\n", i);
            n--;
        }
    }

    // bitset_free(bitarr);
}

void test() {
    bitset_create(bitarr, BITSIZE);
    // bitset_alloc(bitarr, BITSIZE);

    const size_t bitarr_len = sizeof(bitarr) / sizeof(bitarr[0]);
    printf("bitarr len: %lu\n", bitarr_len);
    // static_assert(bitarr_len == 3, "bitarr is not right");

    for (size_t i = 0; i < bitarr_len; i++) {
        printf("arr[%lu]: %lu\n", i, bitarr[i]);
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
        printf("ultimate val: %lu\n", bitarr[i]);
    }
    printf("bitsize: %lu\n", bitset_size(bitarr));
    printf("\n");
    // bitset_free(bitarr);
}

int main() {
    test();

    // sieve(SIZE);

    return 0;
}