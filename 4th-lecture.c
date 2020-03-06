#include <stdio.h>

struct X {
    int x;
    struct  {
        int y;
    };
    union  {
        int i;
        float f;
    };
} s;

int main(int argc, char *argv[]) {
    s.x = 4;
    s.y = 1;
    s.f = 3.14F;

    printf("%d, %f\n", s.x, s.f);

    printf("%d, %d, %d, %d\n", 5 % 3, 5 % -3, -5 % 3, -5 % -3);

    return 0;
}