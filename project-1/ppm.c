#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "ppm.h"
#include "eratosthenes.h"
#include "error.h"
#include "ctype.h"

// TODO: Marty - close file, free line

struct ppm * ppm_read(const char * filename) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        error_exit("Soubor nebylo možné nahrát.\n"); 
    }

    char buffer[5];
    unsigned xsize, ysize; 
    unsigned color; 

    fscanf(file, "%s \n%u %u \n%u\n", buffer, &xsize, &ysize, &color);

    struct ppm *ppm = malloc(sizeof(struct ppm) + sizeof(char) * xsize * ysize * 3); 
    ppm->xsize = xsize;
    ppm->ysize = ysize;

    unsigned size = 3 * xsize * ysize;
    fread(ppm->data, sizeof(char), size, file);

    fclose(file);
    return ppm;
}

void ppm_free(struct ppm *p) {
    free(p);
}