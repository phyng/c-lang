#include <stdio.h>


void swap(int v[], int i, int j) {
    int temp;
    temp = v[i];
    v[i] = v[j];
    v[j] = temp;
}

void qsort(int v[], int left, int right) {
    printf("%d %d\n", left, right);
    int i, last;
    if (left >= right)
        return;
    swap(v, left, (left + right) / 2);
    last = left;
    for (i = left + 1; i <= right; i++) {
        if (v[i] < v[left])
            swap(v, ++last, i);
    }
    swap(v, left, last);
    qsort(v, left, last - 1);
    qsort(v, last + 1, right);
}

main () {
    int v[] = {2, 1, 7, 8, 3, 5, 7, 2, 3, 6, 5, 1, 2};
    qsort(v, 0, 12);
    int i;
    for (i = 0; i <= 12; i++) {
        printf("%d\n", v[i]);
    }
}
