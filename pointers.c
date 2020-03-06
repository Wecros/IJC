#include <stdio.h>
#include <string.h>

char *strcpy(char *s1, const char *s2) {
    char *s = s1;
    while (*s++ = *s++);
    return s1;
}

int main(void) {
    int a[5] = {1, 2, 3, 4, 5};
    int *pa_1, *pa_2;
    pa_1 = &a[2];
    pa_2 = &a[3];

    int *ip = a;
    for (int i = 0; i < 5; i++, pa_1++) {
        printf("value of el: %d\n", *pa_1);
    }

    printf("number of elements: %d\n", pa_1 - pa_2);

    int *s = a;
    *s = 'A';

    for (int i = 0; i < 5; i++) {
        printf("value of el: %d\n", *(a+i));
    }

    char *message = "";
    message = "Now is the time.";
    char *message_2;

    printf("string: %s\n", message);

    printf("another string: %s\n", message_2);

    return 0;
}
