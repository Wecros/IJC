#include <stdio.h>
#include "ppm.h"

int main(int argc, char *argv[]) {
    

    struct ppm *ppm = ppm_read("du1-obrazek.ppm");

    ppm_file(ppm);
    
    return 0;
}