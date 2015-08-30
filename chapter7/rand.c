#include <stdio.h>
#include <stdlib.h>

#define frand() ((double) rand() / (RAND_MAX + 1.0))

main () {
    int i = 0;
    while (i++ < 5) {
        printf("%f\n", frand());
    }
}
