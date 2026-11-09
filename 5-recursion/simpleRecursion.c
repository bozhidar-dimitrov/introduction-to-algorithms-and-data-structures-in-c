#include <stdio.h>

int sumNGaus(int n) {
    return n * (n + 1) / 2;
}

int sumNRecursive(int n) {
    if (n == 1) { //Стопиращо условие
        return 1; //Дъно на рекурсията
    }
    //Ако нямаме стопиращо условие и дъно на рекурсията получаваме препълване на стека на функциите.

    return sumNRecursive(n - 1) + n;
}

int sumNNormal(int n) {
    int sum = 0;
    for(int i = 1; i<=n; i++){
        sum+=i;
    }
    return sum;
}

int main(void) {

    int n = 5;
    int result=sumNNormal(n);
    printf("Sum (Normal) is: %d\n", result);

    int result2=sumNRecursive(n);
    printf("Sum (Recursive) is: %d\n", result2);

    int result3=sumNGaus(n);
    printf("Sum (Gaus) is: %d\n", result3);

    return 0;
}