#include <stdio.h>

int sum_digits(int number) {
    if (number == 0) {
        return 0;
    }

    return number % 10 + sum_digits(number / 10);
}

int main(void) {
    int number = 1234;

    printf("sum_digits(%d) = %d\n", number, sum_digits(number));

    return 0;
}
