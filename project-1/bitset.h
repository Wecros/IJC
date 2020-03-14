#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define N 100

typedef unsigned long bitset_index_t;
typedef bitset_index_t * bitset_t; 

#define BITSIZE (bitset_index_t) (sizeof(bitset_index_t) * CHAR_BIT)

// TODO: check the array's bounds
// TODO: Makefile finishing

/**
 * @brief Macro for creating bitset array.
 * @param array Name of the bitset.
 * @param size Size of the array in bits.
 */
#define bitset_create(array, size)  \
    static_assert(size > 0, "Size of the bitset must be greater than 0"); \
    bitset_index_t array[size / BITSIZE + ((size % BITSIZE) ? 2 : 1)] = {size}

/**
 * @brief Macro for creating a dynamic bitset array.
 * @param array Name of the bitset.
 * @param size Size of the array in bits.
 */
#define bitset_alloc(array, size) \
    static_assert(size > 0, "Size of the bitset must be greater than 0"); \
    bitset_t array = calloc(size, sizeof(bitset_index_t)); \
    array[0] = size;

// #define USE_INLINE
#ifndef USE_INLINE

/**
 * @brief Macro for freeing a dynamic bitset array.
 * @param array Name of the bitset.
 */
#define bitset_free(array) free(array)

/**
 * @brief Macro for getting the bitset's size.
 * @param array Name of the bitset.
 */
#define bitset_size(array) array[0]

/**
 * @brief Macro for setting a bit in the bitset.
 * @param array Name of the bitset.
 * @param index Index of the array.
 * @param value Bit value. True value -> 1, False value -> 0. 
 */
#define bitset_setbit(array, index, value)  \
    array[index / BITSIZE + 1] = \
        (bitset_index_t) (array[index / BITSIZE + 1] \
        & (value ? (bitset_index_t)  ~0 : (bitset_index_t) ~(1 << (index % (BITSIZE))))) \
        | (value ? (bitset_index_t) 1 << (index % BITSIZE) : 0)

/**
 * @brief Macro for getting a bit value in the bitset.
 * @param array Name of the bitset.
 * @param index Index of the array.
 * @return Either 0 or 1.
 */
#define bitset_getbit(array, index) \
    ((bitset_index_t) array[(index / BITSIZE) + 1] \
    & ((bitset_index_t) 1 << (index % BITSIZE))) ? 1 : 0    

/* #define bitset_getbit(array, index) \
    (index < (bitset_size(array)) && index > 0) ? ( \
    ((bitset_index_t) array[(index / BITSIZE) + 1] \
    & ((bitset_index_t) 1 << (index % BITSIZE))) ? 1 : 0) \
        : error_exit("bitset_getbit: Index %lu mimo rozsah 0..%lu\n", \
            (unsigned long) index, (unsigned long) bitset_size(array))
*/

#else

extern inline void bitset_free(bitset_t array) {
    free(array);
} 

extern inline unsigned bitset_size(bitset_t array) {
    return array[0];
}

extern inline void bitset_setbit(bitset_t array, bitset_index_t index, unsigned value) {
    array[index / BITSIZE + 1] =
        (bitset_index_t) (array[index / BITSIZE + 1]
        & (value ? (bitset_index_t) ~0 : (bitset_index_t) ~(1 << (index % (BITSIZE)))))
        | (value ? (bitset_index_t) 1 << (index % BITSIZE) : 0);
}

// extern inline void bitset_setbit(bitset_t array, bitset_index_t index, unsigned value) {
//     unsigned bitsize = sizeof(bitset_index_t) * CHAR_BIT;

//     int i = (index / bitsize) + 1;
//     int pos = index % bitsize;
//     unsigned flag = (bitset_index_t) 1 << pos;

//     if (value) {
//         array[i] |= flag;
//     } else {
//         array[i] &= ~flag;
//     }
// }

extern inline unsigned bitset_getbit(bitset_t array, bitset_index_t index) {
    return ((bitset_index_t) array[(index / BITSIZE) + 1]
    & ((bitset_index_t) 1 << (index % BITSIZE))) ? 1 : 0;
}

// extern inline unsigned bitset_getbit(bitset_t array, bitset_index_t index) {
//     unsigned bitsize = sizeof(bitset_index_t) * CHAR_BIT;

//     int i = (index / bitsize) + 1;
//     int pos = index % bitsize;
//     int arrval = array[i];

//     // unsigned long flag = 1 << pos;  // TOFIX: WHY DOESNT THIS WORK?
//     unsigned long flag = (bitset_index_t) 1 << pos;

//     // printf("idx: %lu, pos: %lu, flag: %lu, arr: %lu, BIT: %lu\n", i, pos, flag, arrval, arrval & flag);
    
//     int bit = arrval & flag ? 1 : 0;
//     return bit;
// }


#endif
