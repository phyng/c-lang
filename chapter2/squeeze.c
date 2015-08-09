#include <stdio.h>


void sequeeze(char s1[], char s2[]) {
    int i, j, k, flag;
    for (i = k = 0; s1[i] != '\0'; ++i) {
        flag = 0;
        for (j = 0; s2[j] != '\0'; ++j) {
            if (s1[i] == s2[j]) {
                flag = 1;
            }
        }
        if (!flag) {
            s1[k++] = s1[i];
        }
    }
    s1[k] = '\0';
}


main () {
    char s1[] = "Hello world!";
    char s2[] = "ol";
    sequeeze(s1, s2);
    printf("%s\n", s1);
}
