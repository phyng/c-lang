#include <stdio.h>


int binsearch(int x, int v[], int n) {
    int low, high, mid;
    low = 0;
    high = n - 1;
    while (low <= high) {
        mid = (low + high) / 2;
        if (x < v[mid]) {
            high = mid - 1;
        }
        else if (x > v[mid]) {
            low = mid + 1;
        }
        else {
            return mid;
        }
    }
}


int binsearch2(int x, int v[], int n) {
    int low, high, mid;
    low = 0;
    high = n - 1;
    while (low <= high) {
        mid = (low + high) / 2;
        x < v[mid] ? (high = mid - 1) : (low = mid + 1);
    }
    return high > low ? low : high;
}


main () {
    int x = 4;
    int n = 7;
    int v[] = {1, 2, 3, 4, 5, 6, 7};
    printf("%d\n", binsearch(x, v, n));
    printf("%d\n", binsearch2(x, v, n));
}
