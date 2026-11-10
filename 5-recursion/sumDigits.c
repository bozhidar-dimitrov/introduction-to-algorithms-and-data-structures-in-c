#include <stdio.h>

int sumDigitsNormal(int n) {
    //TODO:
    int sum = 0;
    while(n > 0) {
        int r = n % 10;
        sum = sum + r;
        n = n / 10;
    }
    return sum;
}

int sumDigitsRecursive(int n) {
    if(n==0){
        return 0;
    }
    return sumDigitsRecursive(n/10) + n%10;
}

int main(void) {

    int n = 1245;

    int result1 = sumDigitsNormal(n);
    printf("%d\n", result1);

    int result2 = sumDigitsRecursive(n);
    printf("%d\n", result2);

    return 0;
}