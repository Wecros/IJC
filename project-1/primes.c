#include <stdio.h>

#include "bitset.h";

int main(int argc, char* argv[]) {
    for (int i = 1; i < argc; i++) {
        printf("Arg %d: %s\n", i, argv[i]);
    }
    
    printf("am prime\n");

    return 0;
}