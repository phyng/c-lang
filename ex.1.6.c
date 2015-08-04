#include <stdio.h>


main () {
    printf("%d\n", EOF);    /* EOF == -1 */
    int c;
    c = getchar();
    printf("%d\n", c);
}
