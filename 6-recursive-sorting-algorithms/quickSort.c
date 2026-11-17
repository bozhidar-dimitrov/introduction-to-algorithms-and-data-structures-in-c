#include <stdio.h>

void swap(int arr[], int i, int j) {
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}

int partition(int arr[], int left, int right) {
    int pivot = arr[right];
    int i = left;

    for (int j = left; j < right; j++) {
        if (arr[j] < pivot) {
            swap(arr, i, j);
            i++;
        }
    }

    swap(arr, i, right);
    return i; 
}

void quickSort(int arr[], int left, int right) {
    if (left >= right) {
        return;
    }

    int pivotIndex = partition(arr, left, right);
    quickSort(arr, left, pivotIndex - 1);
    quickSort(arr, pivotIndex + 1, right);
}

int main(void) {

    int arr[10] = {4, 2, 6, 7, 10, 5, 3, 1, 9, 8};
    int n = 10;

    //Quick sort is an unstable sorting algorithm
    quickSort(arr, 0, n - 1);

    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}