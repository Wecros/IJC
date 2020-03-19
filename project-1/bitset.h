#include <stdlib.h>
#include <limits.h>
#include <assert.h>

#include "error.h"

typedef unsigned long bitset_index_t;
typedef bitset_index_t * bitset_t;

#define BITSIZE (bitset_index_t) (sizeof(bitset_index_t) * CHAR_BIT)

// TODO: check the array's bounds
 
/**  
 * @brief Macro for creating bitset array.
 * @param array Name of the bitset.
 * @param size Size of the array in bits.
 */
#define bitset_create(array, size)  \
    bitset_index_t array[size / BITSIZE + ((size % BITSIZE) ? 2 : 1)] = {size}; \
    static_assert(size > 0, "Size of the bitset must be greater than 0")

/**
 * @brief Macro for creating a dynamic bitset array.
 * @param array Name of the bitset.
 * @param size Size of the array in bits.
 */
#define bitset_alloc(array, size) \
    assert(size > 0); \
    bitset_t array = calloc(size / BITSIZE + ((size % BITSIZE) ? 2 : 1), sizeof(bitset_index_t)); \
    if (array == NULL) { \
        error_exit("bitset_alloc: Chyba alokace paměti\n"); \
    } \
    array[0] = size;

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
#define bitset_size(array) (array[0])

/**
 * @brief Macro for setting a bit in the bitset.
 * @param array Name of the bitset.
 * @param index Index of the array.
 * @param value Bit value. True value -> 1, False value -> 0. 
 */
#define bitset_setbit(array, index, value)  \
    if (index >= bitset_size(array)) { \
        error_exit("bitset_getbit: Index %lu mimo rozsah 0..%lu\n", \
            (unsigned long) index, (unsigned long) bitset_size(array)); } \
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
    (index >= bitset_size(array) ? (error_exit("bitset_getbit: Index %lu mimo rozsah 0..%lu\n", \
        (unsigned long) index, (unsigned long) bitset_size(array)), 0) \
    : (((bitset_index_t) array[(index / BITSIZE) + 1] \
    & ((bitset_index_t) 1 << (index % BITSIZE))) ? 1 : 0))
 
#else

inline void bitset_free(bitset_t array) {
    free(array);
}

inline unsigned bitset_size(bitset_t array) {
    return array[0]; 
}

inline void bitset_setbit(bitset_t array, bitset_index_t index, unsigned value) {
    if (index >= bitset_size(array)) {
        error_exit("bitset_getbit: Index %lu mimo rozsah 0..%lu\n",
            (unsigned long) index, (unsigned long) bitset_size(array)); }
    array[index / BITSIZE + 1] =
        (bitset_index_t) (array[index / BITSIZE + 1]
        & (value ? (bitset_index_t)  ~0 : (bitset_index_t) ~(1 << (index % (BITSIZE)))))
        | (value ? (bitset_index_t) 1 << (index % BITSIZE) : 0);
}

inline unsigned bitset_getbit(bitset_t array, bitset_index_t index) {
    return index >= bitset_size(array) ? (error_exit("bitset_getbit: Index %lu mimo rozsah 0..%lu\n",
        (unsigned long) index, (unsigned long) bitset_size(array)), 0)
    : (((bitset_index_t) array[(index / BITSIZE) + 1]
    & ((bitset_index_t) 1 << (index % BITSIZE))) ? 1 : 0);
}

#endif
