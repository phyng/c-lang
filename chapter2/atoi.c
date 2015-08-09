#include <stdio.h>

int myatoi(char s[]) {
    int i;
    int n = 0;
    for (i = 0; s[i] >= '0' && s[i] <= '9'; ++i) {
        n = 10 * n + s[i] - '0';
    }
    return n;
}

main () {
    char a[] = "1234";
    printf("%d\n", atoi(a));
    printf("%d\n", myatoi(a));
}
