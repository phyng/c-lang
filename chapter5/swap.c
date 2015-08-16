#include <stdio.h>

void swap(int *px, int *py) {
    int temp = *px;
    *px = *py;
    *py = temp;
}

main () {
    int x = 1;
    int y = 2;
    swap(&x, &y);
    printf("%d %d\n", x, y);
}
