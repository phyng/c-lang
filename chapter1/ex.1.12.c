#include <stdio.h>

// 对输入内容按单词逐行输出

#define OUT 0
#define IN 1

main () {
    int c;
    int state = IN;
    int prev = '\n';
    while ((c = getchar()) != EOF) {
        if (c == ' ' || c == '\n' || c == '\t') {
            state = OUT;
        }
        if (state == OUT) {
            if (prev != '\n') {
                putchar('\n');
                prev = '\n';
            }
            state = IN;
        }
        else {
            putchar(c);
            prev = c;
        }
    }
}
