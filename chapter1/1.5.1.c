#include <stdio.h>

main() {
    int c;
    c = getchar();
    printf("%d\n", 1);
    while (c != EOF) {
        putchar(c);
        c = getchar();
    }
}
