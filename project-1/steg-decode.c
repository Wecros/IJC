#include <stdio.h>

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
    
    bitset_alloc(primearr, data_size);
    sieve(primearr);

    unsigned pos = 0;
    unsigned char byte = 0;
    for (bitset_index_t i = 23; i < data_size; i++) {
        if (bitset_getbit(primearr, i)) { 
            unsigned char LSb = ppm->data[i];
            byte |= (LSb & 1) << pos;
 
            pos++;
            printf("%u", LSb & 1); 
            if (pos == 8) { 
                printf("\n");
                printf("%c", byte);

                if (byte == '\0') {
                    printf("\n ZERO CHAR FOUND \n");
                    break;
                }
                pos = 0;
                byte = 0;
                break;
            }
        }
    }

    printf("\n");
    ppm_free(ppm);
    return 0;
}