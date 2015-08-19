#include <stdio.h>


int strends(char *s, char *t) {
    int i = 0;
    while (*s++);
    while (*t++) i++;
    s -= 2;
    t -= 2;
    while (*t-- == *s--) i--;
    return i ? 0 : 1;
}


main () {
    char *s = "abcdefghijklmn";
    char *t = "klmn";
    printf("%d\n", strends(s, t));
}
