#include <stdio.h>

int fibunaci(int n) {
    if (n == 0) {
        return 0;
    }

    if (n == 1) {
        return 1;
    }

    return fibunaci(n - 1) + fibunaci(n - 2);
}

int fibunaciNormal(int n) {
    
    int a = 0;
    int b = 1;
    int current = 0;
    for(int i = 0; i < n; i++) {
        current = a + b;
        a = b;
        b = current;
    }
    return a;
}

int main(void) {

    int n = 4;
    int result = fibunaci(n);
    printf("%d\n", result);
    int result_normal = fibunaciNormal(n);
    printf("%d\n", result_normal);

    return 0;
}