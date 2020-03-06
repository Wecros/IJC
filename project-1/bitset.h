#include <stdio.h>
#include <stdlib.h>

#define N 100

typedef unsigned long bitset_index_t;
typedef bitset_index_t * bitset_t; 

// #define bitset_create(array, size)  ( size % (sizeof(bitset_index_t) * __CHAR_BIT__) ? \
//     bitset_t array[size / (sizeof(bitset_index_t) * __CHAR_BIT__) + 2] : \
//     bitset_t array[size / (sizeof(bitset_index_t) * __CHAR_BIT__) + 1] )

#define bitset_create(array, size)  bitset_t bitarr[size / (sizeof(bitset_index_t) * __CHAR_BIT__) \
    + ((size % (sizeof(bitset_index_t) * __CHAR_BIT__)) ? 2 : 1)] = {size}

// #define bitset_create(array, size) do { \
//     unsigned bitsize = sizeof(bitset_index_t) * __CHAR_BIT__; \
//     bitset_t array[size / bitsize + bitsize % 32 ? 1 : 2]; \
//     for (size_t i = 0; i < size / bitsize; i++) array[i] = 0; \
//     array[0] = size; \
// } while (0)

// #define bitset_create(array, size) do { \
//     unsigned bitsize = sizeof(bitset_index_t) * __CHAR_BIT__; \
//     bitset_t array[size / bitsize + bitsize % 32 ? 1 : 2]; \
//     for (size_t i = 0; i < size / bitsize; i++) array[i] = 0; \
//     array[0] = size; \
// } while (0)


// #define bitset_create(array, size) ();
    //    definuje a _nuluje_ proměnnou jmeno_pole
    //    (POZOR: opravdu musí _INICIALIZOVAT_ pole bez ohledu na
    //    to, zda je pole statické nebo automatické/lokální!
    //    Vyzkoušejte obě varianty, v programu použijte lokální pole.)
    //    Použijte  static_assert  pro kontrolu velikosti pole.
    //    Př: static bitset_create(p,100); // p = pole 100 bitů, nulováno
    //        bitset_create(q,100000L);    // q = pole 100000 bitů, nulováno
    //        bitset_create(q,-100);       // chyba při překladu

// #define bitset_alloc(array, size);
    //    definuje proměnnou jmeno_pole tak, aby byla kompatibilní s polem
    //    vytvořeným pomocí bitset_create, ale pole bude alokováno dynamicky.
    //    Př: bitset_alloc(q,100000L); // q = pole 100000 bitů, nulováno
    //    Použijte  assert  pro kontrolu maximální možné velikosti pole.
    //    Pokud alokace selže, ukončete program s chybovým hlášením:
    //    "bitset_alloc: Chyba alokace paměti"
    
// #define bitset_free(array);
    //    uvolní paměť dynamicky alokovaného pole

// #define bitset_size(array);
    //    vrátí deklarovanou velikost pole v bitech (uloženou v poli)

// #define bitset_setbit(array, index, value) (array[(index/32)] |= (value << (index % 32)))
    //  bitset_setbit(jmeno_pole,index,výraz)
    //    nastaví zadaný bit v poli na hodnotu zadanou výrazem
    //    (nulový výraz == bit 0, nenulový výraz == bit 1)
    //    Př: bitset_setbit(p,20,1);

// #define bitset_getbit(array, index) (1 & array[(index/32)] >> (index % 32))
    //  bitset_getbit(jmeno_pole,index)
    //    získá hodnotu zadaného bitu, vrací hodnotu 0 nebo 1
    //    Př: if(bitset_getbit(p,i)==1) printf("1");
    //        if(!bitset_getbit(p,i))   printf("0");


// void bitset_alloc(bitset_t array, int size) {
//     array = calloc(size, sizeof(bitset_t));
    
// }

void bitset_free(bitset_t array) {
    free(array);
}

unsigned long bitset_size(bitset_t array) {
    return array[0];
}

#define bitset_setbit(array, index, value)  \
    array[index / (sizeof(bitset_index_t) * __CHAR_BIT__) + 1] = \
        (bitset_index_t) array[index / (sizeof(bitset_index_t) * __CHAR_BIT__) + 1] \
        & (value ? ~0 : ~(1 << (index % ((sizeof(bitset_index_t) * __CHAR_BIT__))))) \
        | (value ? 1 << (index % (sizeof(bitset_index_t) * __CHAR_BIT__)) : 0)

// void bitset_setbit(bitset_t array, bitset_index_t index, unsigned int value) {
//     array[index / (sizeof(bitset_index_t) * __CHAR_BIT__) + 1] =
//         array[index / (sizeof(bitset_index_t) * __CHAR_BIT__) + 1]
//         & (value ? ~0 : ~(1 << (index % ((sizeof(bitset_index_t) * __CHAR_BIT__)))))
//         | (value ? 1 << (index % (sizeof(bitset_index_t) * __CHAR_BIT__)) : 0)
//     ;
// }

// void bitset_setbit(bitset_t array, bitset_index_t index, unsigned int value) {
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

// #define bitset_getbit(array, index) {
    
// }

unsigned bitset_getbit(bitset_t array, bitset_index_t index) {
    return 0;

    unsigned bitsize = sizeof(bitset_index_t) * __CHAR_BIT__;

    int i = (index / bitsize) + 1;
    int pos = index % bitsize;
    int arrval = array[i];

    // unsigned long flag = 1 << pos;  // TOFIX: WHY DOESNT THIS WORK?
    unsigned long flag = 1;
    flag = flag << pos;

    // printf("idx: %lu, pos: %lu, flag: %lu, arr: %lu, BIT: %lu\n", i, pos, flag, arrval, arrval & flag);
    
    int bit = arrval & flag ? 1 : 0;
    return bit;
}

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
