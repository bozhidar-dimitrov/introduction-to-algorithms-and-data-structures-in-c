#include <stdio.h>

int main() {

    int arr[7] = {7, 3, 6, 2, 4, 1, 5};
    int n = 7;

    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - 1 - i; j++) {
            if (arr[j] > arr[j+1]) {
                int c = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = c;
            }
        }
    }

    for (int i = 0; i < n; i++) {
        printf("%d", arr[i]);
    }

    return 0;
}