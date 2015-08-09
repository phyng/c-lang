#include <stdio.h>

/*
    单词长度直方图
        * 最大长度小于20
        * 最大次数限制为20
        * 只认可[A-Za-z]作为单词字符

*/
#define OUT 0
#define IN 1


main () {
    int c, i, j, k;
    int length = 0;

    int ndigit[20];
    for (i = 0; i < 20; ++i) {
        ndigit[i] = 0;
    }

    while ((c = getchar()) != EOF) {
        if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z')) {
            ++length;
        }
        else {
            if (length > 0) {
                ++ndigit[length];
            }
            length = 0;
        }
    }
    if (c == EOF) {
        if (length > 0) {
            ++ndigit[length];
        }
    }

    printf("ndigit: ");
    for (i = 0; i < 20; ++i) {
        printf("%d ", ndigit[i]);
    }
    putchar('\n');

    // 水平直方图
    for (i = 0; i < 20; ++i) {
        printf("%2d %2d: |", i, ndigit[i]);
        for (j = 0; j < ndigit[i]; ++j) {
            printf("▇");
        }
        putchar('\n');
    }

    // 水平直方图
    for (i = 20; i > -1; --i) {
        for (j = 0; j < 20; ++j) {
            if (i == (ndigit[j] + 1)) {
                printf("%2d", ndigit[j]);
            }
            else if (ndigit[j] >= i) {
                printf("██");
            }
            else {
                printf("  ");
            }
        }
        putchar('\n');
    }
    for (j = 0; j < 20; ++j) {
        printf("%2d", j);
    }
    putchar('\n');
}
