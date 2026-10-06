#include <stdio.h>

int sumN(int n) {
    if (n == 0) {
        return 0;
    }

    return sumN(n - 1) + n;
}

int main(void) {
    /**
     * sumN(5) = sumN(4) + 5
     * sumN(4) = sumN(3) + 4
     * sumN(3) = sumN(2) + 3
     * sumN(2) = sumN(1) + 2
     * sumN(1) = sumN(0) + 1
     * sumN(0) = 0
     * -----------------------
     * sumN(n) = sumN(n-1) + n
     * sumN(0) = 0
     */
    int result = sumN(5);
    printf("%d", result);
    return 0;
}