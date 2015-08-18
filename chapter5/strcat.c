#include <stdio.h>


// s--是为了回退到'\0'
void strcats(char *s, char *t) {
    while (*s++);
    s--;
    while (*s++ = *t++);
}


main () {
    char s[1000] = "hello ";
    char *t = "world!";
    strcats(s, t);
    printf("%s\n", s);
}
