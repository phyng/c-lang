#include <stdio.h>

/* 统计表格、制表符、换行符 */

main () {

    int c, nb, nn, nt;
    nb = 0;
    nn = 0;
    nt = 0;
    while ((c = getchar()) != EOF) {
        if (c == '\n') {
            ++nn;
        }
        else if (c == '\t') {
            ++nt;
        }
        else  if (c == ' ') {
            ++nb;
        }
    }
    printf("%d\n", nb);
    printf("%d\n", nn);
    printf("%d\n", nt);


}
