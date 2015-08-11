#include <stdio.h>

double atof(char s[]) {
    double val, power;
    int i, sign;
    for (i = 0; isspace(s[i]); i++);
    sign = (s[i] == '-') ? -1 : 1;
    if (s[i] == '+' || s[i] == '-') i++;
    for (val = 0.0; isdigit(s[i]); i++) {
        val = 10.0 * val + (s[i] - '0');
    }
    if (s[i] == '.') i++;
    for (power = 1.0; isdigit(s[i]); i++) {
        val = 10.0 * val + (s[i] - '0');
        power *= 10.0;
    }
    val = sign * val / power;

    // 处理科学计数法
    int e;
    double base;
    double e_val;
    if (s[i] == 'e') i++;
    sign = (s[i] == '-') ? (base = 0.1) : (base = 10.0);
    if (s[i] == '+' || s[i] == '-') i++;
    for (e = 0; isdigit(s[i]); i++) {
        e = 10 * e + (s[i] - '0');
    }
    for (e_val = 1; e > 0; e--) {
        e_val *= base;
    }
    return val * e_val;
}

main () {
    printf("%g\n", atof("1.234"));
    printf("%g\n", atof("1e2"));
    printf("%g\n", atof("1e-2"));
    printf("%g\n", atof("123.45e+2"));
}
