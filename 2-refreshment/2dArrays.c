#include <stdio.h>

int main(void) {

    int array2d[5][4] = {
        {1, 2, 3, 4}, 
        {5, 6, 7, 8}, 
        {9, 10, 11, 12}, 
        {13, 14, 15, 16}, //-> subarray
        {17, 18, 19, 20}
    };

    printf("%d", array2d[2][2]);
    printf("\n");
    
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 4; j++) {
            printf("%d ", array2d[i][j]);
        }
        printf("\n");
    }



    return 0;
}