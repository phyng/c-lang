#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define TIMES 100000000
#define frand() ((double) rand() / (RAND_MAX + 1.0))

main () {
    int times = TIMES;
    int in_count = 0;

    while (times-- > 0)
        if (sqrt(pow(frand(), 2) + pow(frand(), 2)) - 1 < 0)
            in_count++;

    printf("%f\n", 4.0 * in_count / TIMES);
}
