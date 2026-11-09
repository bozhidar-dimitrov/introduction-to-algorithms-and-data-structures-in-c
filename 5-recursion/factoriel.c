#include <stdio.h>

int factoriel(int n) {
    if (n == 1){
        return 1;
    }
    return n * factoriel(n-1);
}

int main(void) {

    int result = factoriel(5);
    printf("%d\n", result);

    return 0;
}