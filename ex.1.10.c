#include <stdio.h>

// 将特殊字符用转义形式输出

main () {
    int c;
    while ((c = getchar()) != EOF) {
        if (c == '\t') {
            putchar('\\');
            putchar('t');
        }
        else {
            putchar(c);
        }
    }
}
