#include <stdio.h>

int strlens(char *s) {
    int i;
    for (i = 0; *s != '\0'; s++) {
        i++;
    }
    return i;
}


main () {
    printf("%d\n", strlens("hello world!"));
}
