#include <stdio.h>

int power(int base, int exponent) {
    if (exponent == 0) {
        return 1;
    }

    return base * power(base, exponent - 1);
}

int main(void) {
    int base = 2;
    int exponent = 10;

    printf("power(%d, %d) = %d\n", base, exponent, power(base, exponent));

    return 0;
}
