#include <stdio.h>

int main() {

    int arr[3];
    
    arr[0] = 7;
    arr[1] = 5;
    arr[2] = 3;

    for (int i = 0; i < 3; i++) {
        printf("%d ", arr[i]);
    }

    int arr2[3] = {1, 2, 3}; //initializing an array with array literal
    //arr2 = {5, 6, 7} - not allowed - compiler error

    int arr3[] = {4, 5, 6, 7};

    return 0;
}