#include <stdio.h>
#include <math.h>

#include "bitset.h"

void sieve(int el_count) {
    bitset_t bitarr;
    // bitset_create(bitarr, el_count);
    // bitset_alloc(bitarr, el_count);

    for (size_t i = 0; i < el_count; i++) {
        bitarr[i] = 1;
    } 

    // bitarr[0] = 1;
    // bitarr[1] = 1;

    for (size_t i = 0; i < sqrt(el_count); i++) {
        if (bitarr[i]) {
            for (size_t j = pow(i, 2); j < el_count; j += i) {
                bitarr[j] = 0;
            }
        }
    }
    
}

int main() {
    bitset_t bitarr[10];

    for (bitset_index_t i = 0; i < 4; i++) {
        bitset_setbit(bitarr, i, 1);
    }

    for (bitset_index_t i = 0; i < 10; i++) {
        printf("val [%d]: %d\n", i, bitset_getbit(bitarr, i));
    }

    return 0;
}