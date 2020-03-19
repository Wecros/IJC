/**
 * @file ppm.h
 * @author Marek Filip (xfilip46), FIT BUT
 * @date 19/Mar/2020
 * @brief IJC-DU1, příklad b)
 * @details Header file declaring struct and functions compatible
 *          with ppm pictures.
 *          Compiled: gcc 9.2
 */

struct ppm {
    unsigned xsize;
    unsigned ysize;
    char data[];    // RGB bajty, celkem 3*xsize*ysize
};

struct ppm * ppm_read(const char * filename);

void ppm_free(struct ppm *p);

