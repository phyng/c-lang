#include <stdio.h>

// 输入复制到输出，要求合并多个空格到一个空格
// getchar, 回车执行一次输入，但是是单个字符分别输入，Ctrl + D 是 EOF

main () {

    int c;
    int prev;
    prev = EOF;
    while ((c = getchar()) != EOF) {
        if (prev != ' ') {
            putchar(c);
        }
        prev = c;
    }

}
