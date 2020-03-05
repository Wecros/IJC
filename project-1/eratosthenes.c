#include <stdio.h>
#include <math.h>
#include <assert.h>

#include "bitset.h"

#define BITSIZE 100

void sieve(size_t el_count) {
    (void) el_count;
    // bitset_t bitarr[10];
    // // bitset_create(bitarr, el_count);
    // // bitset_alloc(bitarr, el_count);

    // for (size_t i = 0; i < el_count; i++) {
    //     bitarr[i] = 1;
    // } 

    // // bitarr[0] = 1;
    // // bitarr[1] = 1;

    // for (size_t i = 0; i < sqrt(el_count); i++) {
    //     if (bitarr[i]) {
    //         for (size_t j = pow(i, 2); j < el_count; j += i) {
    //             bitarr[j] = 0;
    //         }
    //     }
    // }
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

    for (bitset_index_t i = 0; i < 3; i++) {
        bitset_setbit(bitarr, i, 1);
    }

    // bitset_setbit(bitarr, 1, 0);

    for (bitset_index_t i = 64; i < 67; i++) {
        bitset_setbit(bitarr, i, 1);
    }

    // bitset_setbit(bitarr, 87, 1);
    // bitset_setbit(bitarr, 87, 0);
    // bitset_setbit(bitarr, 86, 1);
    // bitset_setbit(bitarr, 88, 1);

    for (bitset_index_t i = 0; i < 100; i++) {
        printf("val [%lu]: %u\n", i, bitset_getbit(bitarr, i));
    }

    for (size_t i = 1; i < size; i++) {
        printf("ultimate val: %lu\n", bitarr[i]);
    }
    printf("bitsize: %lu\n", bitset_size(bitarr));

    return 0;
}