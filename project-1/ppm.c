#include <stdio.h>

#include "ppm.h"
#include "eratosthenes.h"
#include "error.h"

struct ppm * ppm_read(const char * filename) {
    FILE *file;
    if (fopen(filename, "r") == NULL) {
        error_exit("Chyba ve čtení souboru\n"); 
    }

    int c;
    while (c = fgetc(stdin) != EOF) {
        printf("%c", c);
    }

}

void ppm_free(struct ppm *p) {

}