#include <stdio.h>

void printArray(int array[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");
}

int binarySearchRecursive(int array[], int searchElement, int left, int right) {
    int mid = (left + right) / 2;
    if (left > right) {
        return -1;
    }

    if (array[mid] == searchElement) {
        return mid;
    } else if (searchElement < array[mid]) {
        return binarySearchRecursive(array, searchElement, 0, mid-1);
    } else {
        return binarySearchRecursive(array, searchElement, mid + 1, right);
    }
}

int main(void) {

    int array[] = {1, 1, 3, 4, 5, 5, 8, 10, 11};
    int n = sizeof(array) / sizeof(array[0]);

    printArray(array, n);
    int result = binarySearchRecursive(array, 12, 0, n-1);
    printf("%d\n", result);

    return 0;
}