#include <stdio.h>

int getlines(char s[], int lim) {
    int c, i;
    for (i = 0; i < lim - 1 && (c = getchar()) != EOF && c != '\n'; ++i) {
        s[i] = c;
    }
    if (c == '\n') {
        s[i] = c;
        ++i;
    }
    s[i] = '\0';
    return i;
}

void print_line(char line[]) {
    int i;
    for (i = 0; line[i] != '\0'; ++i) {
        putchar(line[i]);
    }
}

/* 计算字符数组的长度 hello\n\0 */
int len(char line[]) {
    int i = 0;
    while (line[i] != '\0') {
        ++i;
    }
    ++i;
    return i;
}

/* 倒转字符数组 \nolleh\0 */
void reverse(char from[], char to[]) {
    int length = len(from);
    int i, j;
    j = 0;
    for (i = length - 2; i > -1; --i) {
        to[j] = from[i];
        ++j;
    }
    to[j] = '\0';
}

/* 去除字符数组右侧的空白字符 */
int rstrip_index(char from[]) {
    int length = len(from);
    int index = 0;
    int i;
    for (i = 0; from[i] != '\0'; ++i) {
        if ((from[i] != ' ') && (from[i] != '\n') && (from[i] != '\t')) {
            index = i;
        }
    }
    return index;
}


main () {
    int length;
    int limit = 100;
    char line[limit];

    while ((length = getlines(line, limit)) > 0) {
        print_line(line);
        printf("length: %d\n", len(line));
        char reversed_line[limit];
        reverse(line, reversed_line);
        print_line(reversed_line);

        int i;
        int index = rstrip_index(line);
        char array[index + 1];
        for (i = 0; i <= index; ++i) {
            array[i] = line[i];
        }
        array[index + 1] = '\0';
        printf("\nrstrip: ");
        print_line(array);
    }
}
