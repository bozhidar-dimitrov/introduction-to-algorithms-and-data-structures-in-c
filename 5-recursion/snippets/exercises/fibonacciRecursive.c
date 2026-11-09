#include <stdio.h>

int fibonacci(int n) {
    // Дъно на рекурсията: F(0) = 0 и F(1) = 1
    if (n == 0) {
        return 0;
    }
    if (n == 1) {
        return 1;
    }

    // Всяко число е сумата от предишните две
    return fibonacci(n - 1) + fibonacci(n - 2);
}

int main(void) {
    int count = 10;

    for (int i = 0; i < count; i++) {
        printf("fibonacci(%d) = %d\n", i, fibonacci(i));
    }

    return 0;
}
