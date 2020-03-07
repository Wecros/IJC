#include <stdio.h>
#include <stdlib.h>

#define N 100

typedef unsigned long bitset_index_t;
typedef bitset_index_t * bitset_t; 

#define BITSIZE (sizeof(bitset_index_t) * __CHAR_BIT__)

/**
 * @brief Macro for creating bitset array.
 * @param array Name of the bitset.
 * @param size Size of the array in bits.
 */
#define bitset_create(array, size)  bitset_t array[size / (sizeof(bitset_index_t) * __CHAR_BIT__) \
    + ((size % (sizeof(bitset_index_t) * __CHAR_BIT__)) ? 2 : 1)] = {size}

/**
 * @brief Macro for creating a dynamic bitset array.
 * @param array Name of the bitset.
 * @param size Size of the array in bits.
 */
#define bitset_alloc(array, size) \
    bitset_t array = calloc(size, sizeof(bitset_index_t))

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
    array[index / (sizeof(bitset_index_t) * __CHAR_BIT__) + 1] = \
        (bitset_index_t) array[index / (sizeof(bitset_index_t) * __CHAR_BIT__) + 1] \
        & (value ? ~0 : (bitset_index_t) ~(1 << (index % ((sizeof(bitset_index_t) * __CHAR_BIT__))))) \
        | (value ? (bitset_index_t) 1 << (index % (sizeof(bitset_index_t) * __CHAR_BIT__)) : 0)

/**
 * @brief Macro for getting a bit value in the bitset.
 * @param array Name of the bitset.
 * @param index Index of the array.
 */
#define bitset_getbit(array, index) \
    ((bitset_index_t) array[(index / (sizeof(bitset_index_t) * __CHAR_BIT__)) + 1] \
    & ((bitset_index_t) 1 << (index % (sizeof(bitset_index_t) * __CHAR_BIT__)))) ? 1 : 0    



// void bitset_setbit(bitset_t array, bitset_index_t index, unsigned int value) {
//     array[index / (sizeof(bitset_index_t) * __CHAR_BIT__) + 1] =
//         array[index / (sizeof(bitset_index_t) * __CHAR_BIT__) + 1]
//         & (value ? ~0 : ~(1 << (index % ((sizeof(bitset_index_t) * __CHAR_BIT__)))))
//         | (value ? 1 << (index % (sizeof(bitset_index_t) * __CHAR_BIT__)) : 0)
//     ;
// }

// void bitset_setbit(bitset_t array, bitset_index_t index, unsign  ed int value) {
//     unsigned bitsize = sizeof(bitset_index_t) * __CHAR_BIT__;

//     int i = (index / bitsize) + 1;
//     int pos = index % bitsize;
//     unsigned flag = 1 << pos;

//     if (value) {
//         array[i] |= flag;
//     } else {
//         array[i] &= ~flag;
//     }
// }

// unsigned bitset_getbit(bitset_t array, bitset_index_t index) {
//     return (array[index / (sizeof(bitset_index_t) * __CHAR_BIT__) + 1] 
//         & (1 << (index % (sizeof(bitset_index_t) * __CHAR_BIT__)))) ? 1 : 0
//     ;


//     unsigned bitsize = sizeof(bitset_index_t) * __CHAR_BIT__;

//     int i = (index / bitsize) + 1;
//     int pos = index % bitsize;
//     int arrval = array[i];

//     // unsigned long flag = 1 << pos;  // TOFIX: WHY DOESNT THIS WORK?
//     unsigned long flag = 1;
//     flag = flag << pos;

//     // printf("idx: %lu, pos: %lu, flag: %lu, arr: %lu, BIT: %lu\n", i, pos, flag, arrval, arrval & flag);
    
//     int bit = arrval & flag ? 1 : 0;
//     return bit;
// }

// unsigned bitset_getbit(bitset_t array, bitset_index_t index) {
//     unsigned bitsize = sizeof(bitset_index_t) * __CHAR_BIT__;

//     int i = (index / bitsize) + 1;
//     int pos = index % bitsize;
//     int arrval = array[i];

//     // unsigned long flag = 1 << pos;  // TOFIX: WHY DOESNT THIS WORK?
//     unsigned long flag = 1;
//     flag = flag << pos;

//     // printf("idx: %lu, pos: %lu, flag: %lu, arr: %lu, BIT: %lu\n", i, pos, flag, arrval, arrval & flag);
    
//     int bit = arrval & flag ? 1 : 0;
//     return bit;
// }
