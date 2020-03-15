#include <stdio.h>
#include <math.h>
#include <assert.h>
#include "eratosthenes.h"

void sieve(bitset_t array) {
    bitset_setbit(array, 0, 1);
    bitset_setbit(array, 1, 1);

    for (size_t i = 0; i < sqrt(bitset_size(array)); i++) {
        if (!bitset_getbit(array, i)) {
            for (size_t j = i*i; j < bitset_size(array); j += i) {
                if (j == bitset_size(array)) {
                    printf("not allowed\n");
                }
                bitset_setbit(array, j, 1);
            }
        }
    }

    int arr[10];
    for (size_t i = bitset_size(array) - 1,  n = 10; (i > 0) && n; i--) {
        if (!bitset_getbit(array, i)) {
            arr[n-1] = i;
            n--;
        }
    }
    for (size_t i = 0; i < 10; i++) {
        printf("%d\n", arr[i]);
    }
}
