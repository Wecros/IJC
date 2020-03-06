#include <stdio.h>

int i = 5;
void f() {  // F function
    if (i > 0) {
        i--;
        printf("F\n");
        f();
    } else {
        printf("commited oznuk\n");
    }
        
    return;
    f();  // F
}

void printd(int n) {
    int i;
    if (n < 0) {
        putchar('-');
        n = -n;
    }
    if ((i = n/10) != 0) {
        printd(i);
    }
    putchar(n%10 + '0');
}

int main() {
    int i = 0;
    i = i++;  // WTF


    int arr[5] = {1, 2, 3, 4, 5};
    arr[0] = arr[0]++;  // WTF

    goto oznuk;
    printd(-9000);
    printf("\n");


    printf("val: %d\n", i);
    printf("val: %d\n", arr[0]);
    oznuk:
    f();
}