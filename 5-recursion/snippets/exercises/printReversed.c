#include <stdio.h>

// n е броят на елементите, които остават за извеждане
void print_reversed(int array[], int n) {
    if (n == 0) {
        return;
    }

    printf("%d ", array[n - 1]);
    print_reversed(array, n - 1);
}

int main(void) {
    int array[] = {1, 2, 3, 4, 5};
    int n = sizeof(array) / sizeof(array[0]);

    print_reversed(array, n);
    printf("\n");

    return 0;
}
