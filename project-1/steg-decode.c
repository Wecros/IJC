#include <stdio.h>
#include <limits.h>

#include "ppm.h"
#include "error.h"
#include "eratosthenes.h"


int main(int argc, char *argv[]) {
    if (argc < 2 || argc > 2) {
        error_exit("Invalid arguments\n");
    }

    struct ppm *ppm = ppm_read(argv[1]);
    printf("xsize: %u\n", ppm->xsize);
    printf("ysize: %u\n", ppm->ysize);
    
    unsigned data_size = 3 * ppm->xsize * ppm->ysize;
     
    bitset_alloc(primes, data_size);
    sieve(primes);
 
    unsigned pos = 0; 
    unsigned char byte = 0;
    for (bitset_index_t i = 23; i < data_size; i++) {
        if (!bitset_getbit(primes, i)) {  
            unsigned char LSb = ppm->data[i] & 1;
            byte |= LSb << pos;
 
            pos++;
            if (pos == CHAR_BIT) { 
                printf("%c", byte);
                if (byte == '\0') {
                    break;
                }
                pos = 0;
                byte = 0;
            }
        }
    }
    printf("\n");

    ppm_free(ppm);
    return 0;
}