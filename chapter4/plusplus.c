#include <stdio.h>


main () {
    int a = 0;
    int b = 0;
    int c, d;
    c = a++; // c = a, a = a + 1
    d = ++b; // b = b + 1, c = b
    printf("%d %d %d %d\n", a, b, c, d);
}
