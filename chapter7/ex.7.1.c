#include <stdio.h>


main (int argc, char *argv[]) {
    int i;
    char *s;
    for (i = 1; i < argc; i++) {
        s = argv[i];
        do {
            if (*s >= 'a' && *s <= 'z') {
                putchar(*s + ('A' - 'a'));
            }
            else if (*s >= 'A' && *s <= 'Z') {
                putchar(*s - ('A' - 'a'));
            }
            else {
                putchar(*s);
            }
        }
        while (*s++ != '\0');
        putchar(' ');
    }
    if (argc >= 2) {
        putchar('\n');
    }
}
