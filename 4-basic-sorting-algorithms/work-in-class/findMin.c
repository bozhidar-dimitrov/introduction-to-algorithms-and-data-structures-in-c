#include <stdio.h>

int main(void) {

    int arr[10] = {1, 5, 6, 3, -3, 7, 4 ,9, 8, 10};
    int n = 10;
    int minElement = arr[0];
    for (int i = 1; i < n; i++) {
        if (minElement > arr[i]) {
            minElement = arr[i];
        }
    }

    printf("Min element: %d \n", minElement);
    return 0;
}