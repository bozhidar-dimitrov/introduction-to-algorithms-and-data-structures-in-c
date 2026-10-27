#include <stdio.h>

int main(void) {

    int arr[10] = {1, 5, 6, 3, -3, 7, 4 ,9, 8, 10};
    int n = 10;
    int minIndex = 0;
    for (int i = minIndex + 1; i < n; i++) {
        if (arr[minIndex] > arr[i]) {
            minIndex = i;
        }
    }

    printf("Min element index: %d \n", minIndex);
    return 0;
}