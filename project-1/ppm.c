/**
 * @file ppm.c
 * @author Marek Filip (xfilip46), FIT BUT
 * @date 19/Mar/2020
 * @brief IJC-DU1, příklad b)
 * @details Reads a ppm picture and stores the important details in a struct
 *          that can be easily accessed by other programs.
 *          Compiled: gcc 9.2
 */


#include <stdio.h>
#include <stdlib.h>

#include "ppm.h"
#include "error.h"

#define MAX_DATA_SIZE (8000 * 8000 * 3)

struct ppm * ppm_read(const char * filename) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        warning_msg("Soubor nebylo možné nahrát.\n");
        return NULL;
    }

    char format[2];
    unsigned xsize, ysize;
    unsigned char color;
    int scan_count = fscanf(file, "%2c \n%u %u \n%hhu\n", format, &xsize, &ysize, &color);
    if (scan_count != 4 || (format[0] != 'P' || format[1] != '6') || color != 255) {
        warning_msg("Špatný formát obrázku.\n");
        return NULL;
    }

    unsigned data_size = xsize * ysize * 3;
    if (data_size > MAX_DATA_SIZE) {
        warning_msg("Příliš velký obrázek.\n");
        return NULL;
    }

    struct ppm *ppm = malloc(sizeof(struct ppm) + sizeof(char) * data_size);
    if (ppm == NULL) {
        warning_msg("Chyba alokace paměti.\n");
        return NULL;
    }
    ppm->xsize = xsize;
    ppm->ysize = ysize;

    if (fread(ppm->data, sizeof(char), data_size, file) != data_size) {
        warning_msg("Nepodařilo se nahrát data obrázku.\n");
        ppm_free(ppm);
        return NULL;
    }
    fclose(file);
    return ppm;
}

void ppm_free(struct ppm *p) {
    free(p);
}
