#include <stdio.h>


// 当遇到 s[i] == '\0' 时循环终止
void strcpys(char *s, char *t) {
    while (*s++ = *t++);
}


main () {
    char *s1 = "hello";
    char s2[50];
    strcpys(s2, s1);
    printf("%s\n", s2);
}
