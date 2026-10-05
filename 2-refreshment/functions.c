#include <stdio.h>

int add(int a, int b) {
    int result = a + b;
    return result;
}

void printHello() {
    printf("Hello, world \n");
}

int main(void) {

    int x = 5;
    int y = 7;

    int z = add(x, y);
    printf("The result is: %d\n", z);

    printHello();

    return 0;
}