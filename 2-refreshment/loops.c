#include <stdio.h>


int main(void) {

    int i = 1;
    //0+
    while (i < 6) {
        printf("i=%d\n", i);
        i++;
    }

    printf("------------\n");

    int i2 = 1;
    //1+
    do {
        printf("i2 = %d\n", i2);
        i2++;
    } while (i2 < 6);

    int n = 0;
    printf("Please enter a value between 0 and 9:");
    scanf("%d", &n);
    while (n < 0 || n > 9) {
        printf("Please enter a value between 0 and 9:");
        scanf("%d", &n);
    }
    
    //DRY principle - Don't repeat yourself

    printf("------------\n");

    int n1 = 0;
    do {
        printf("Please enter a value between 0 and 9:");
        scanf("%d", &n1);
    } while (n < 0 || n > 9);
    printf("-------------\n");
    for (int i2 = 1; i2 < 6; i2++) {
        printf("i2 = %d\n", i2);
    }

    return 0;
}