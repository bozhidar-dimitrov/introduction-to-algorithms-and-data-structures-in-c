#include <stdio.h>

void swap(int arr[], int i, int j) {
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}

int main(void) {

    int arr[10] = {5, 3, 8, 9, 4, 1, 6, 7, 2, 4};
    int n = 10;

    for (int i = 0; i < n - 1; i++) {
        int mi = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[mi] > arr[j]) {
                mi = j;
            }
        }
        //Here mi - is the index of the smallest element of the unsorted array
        if (i != mi) {
            swap(arr, i, mi);
        }
    }

    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}