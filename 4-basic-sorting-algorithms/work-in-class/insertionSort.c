#include <stdio.h>

void swap(int arr[], int i, int j) {
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}

int main(void) {

    int arr[10] = {5, 3, 8, 9, 4, 1, 6, 7, 2, 4};
    int n = 10;

    for (int i = 1; i < n; i++) {
        for (int j = i; j > 0 && arr[j] < arr[j-1]; j--) {
            swap(arr, j, j - 1);
        }
    }

    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}