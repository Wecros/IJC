#include <stdio.h>
#include <stdlib.h>

#define N 100

typedef int * bitset_t; 

typedef unsigned long bitset_index_t;

// #define bitset_create(array, size) ();
    //    definuje a _nuluje_ proměnnou jmeno_pole
    //    (POZOR: opravdu musí _INICIALIZOVAT_ pole bez ohledu na
    //    to, zda je pole statické nebo automatické/lokální!
    //    Vyzkoušejte obě varianty, v programu použijte lokální pole.)
    //    Použijte  static_assert  pro kontrolu velikosti pole.
    //    Př: static bitset_create(p,100); // p = pole 100 bitů, nulováno
    //        bitset_create(q,100000L);    // q = pole 100000 bitů, nulováno
    //        bitset_create(q,-100);       // chyba při překladu

#define bitset_alloc(array, size);
    //    definuje proměnnou jmeno_pole tak, aby byla kompatibilní s polem
    //    vytvořeným pomocí bitset_create, ale pole bude alokováno dynamicky.
    //    Př: bitset_alloc(q,100000L); // q = pole 100000 bitů, nulováno
    //    Použijte  assert  pro kontrolu maximální možné velikosti pole.
    //    Pokud alokace selže, ukončete program s chybovým hlášením:
    //    "bitset_alloc: Chyba alokace paměti"
    
#define bitset_free(array);
    //    uvolní paměť dynamicky alokovaného pole

#define bitset_size(array);
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

void bitset_create(bitset_t array, int size) {
    array = calloc(size, sizeof(bitset_t));
}

void bitset_setbit(bitset_t array, bitset_index_t index, unsigned int value) {
    int i = index / 32;
    int pos = index % 32;

    unsigned int flag = value << pos;

    printf("index: %d, flag: %d\n", i, array[i] | flag);
    array[i] |= flag;
}

int bitset_getbit(bitset_t array, bitset_index_t index) {
    int arrval = array[index / 32];
    int bit = 1 & (arrval >> (index % 32));
    return bit;
}