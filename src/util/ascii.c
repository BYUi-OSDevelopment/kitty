//
// Created by AIDAN PRATT on 7/3/2024.
//

#include "ascii.h"


void from_int(int n, char dest[12]) {
    char str[12];
    int i, sign;
    if ((sign = n) < 0) n = -n;
    i = 0;
    do {
        str[i++] = n % 10 + '0';
    } while ((n /= 10) > 0);

    if (sign < 0) str[i++] = '-';
    str[i] = '\0';

    dest[i] = '\0';

    int j;
    for(j = 0; j < i; j++) {
        dest[j] = str[i - 1 - j];
    }
}