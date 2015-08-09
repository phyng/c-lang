#include <stdio.h>


int htoi(char s[]) {
    int i;
    char c;
    int n = 0;
    for (i = 0; s[i] != '\0'; ++i) {
        c = s[i];
        if (c >= 'A' && c <= 'Z') {
            c = c - ('A' - 'a');
        }
        if (c >= '0' && c <= '9') {
            n = n * 16 + (c - '0');
        }
        else if (c >= 'a' && c <= 'f') {
            n = n * 16 + (c - 'a' + 10);
        }
        printf("%d %d\n", c, n);
    }
    return n;
}

main () {
    char s[] = "0xF1F1F1";
    printf("%d\n", htoi(s));
}
