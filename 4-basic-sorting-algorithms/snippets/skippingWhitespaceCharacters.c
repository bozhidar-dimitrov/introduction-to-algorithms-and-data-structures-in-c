#include <stdio.h>

int main() {
    int option = 1;

    while (option != 0) {
        int readedCharacters = scanf("%d", &option);
        printf("%d\n", readedCharacters);
        
        //char test[40];
        //scanf("%s", test);
        //printf("%s\n", test);
        scanf("%*s");
    }

    return 0;
}