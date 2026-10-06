#include <stdio.h>

int main() {

    int arr[] = {1, 2, 2, 3, 5, 5, 7, 8, 10, 13};
    int n = 10;
    int search = 12;
    int index = -1;

    int left = 0;
    int right = n - 1;
    while (left <= right) {
        int mid = (left + right) / 2;
        if (arr[mid] == search) {
            index = mid;
            break;
        } else if (search < arr[mid]) {
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }

    if (index != -1) {
        printf("Index is %d\n", index);
    } else {
        printf("Element is not in the array!\n");
    }

    return 0;
}