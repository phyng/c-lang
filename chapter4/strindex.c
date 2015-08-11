#include <stdio.h>
#define MAXLINE 1000


int getlines(char s[], int limit) {
    int c, i;
    i = 0;
    while (--limit > 0 && (c = getchar() != EOF && c != '\n')) {
        s[i++] = c;
    }
    if (c == '\n') {
        s[i++] = c;
    }
    s[i] = '\0';
    return i;
}


int strindex(char s[], char t[]) {
    int i, j, k;
    for (i = 0; s[i] != '\0'; i++) {
        for (j = 1, k =0; t[k] != '\0' && s[j] == t[k]; j++, k++);
        if (k > 0 && t[k] == '\0') {
            return i;
        }
    }
    return -1;
}


main () {
    char line[MAXLINE];
    char pattern[] = "ould";
    int found = 0;
    while (getlines(line, MAXLINE) > 0) {
        if (strindex(line, pattern) >= 0) {
            printf("%s", line);
            found++;
        }
    }
    return found;
}
