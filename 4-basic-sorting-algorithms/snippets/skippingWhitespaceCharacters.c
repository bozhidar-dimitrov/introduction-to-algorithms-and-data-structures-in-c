#include <stdio.h>

int main() {
    int option = 1;
    //int anotherOption = 1;

    // int readedCharacters = scanf("%d %d", &option, &anotherOption);
    // printf("Readed characters: %d\n", readedCharacters);
    // printf("Option: %d\n", option);

    // char test[100];
    // scanf("%s", test);
    // printf("%s", test);

    while (option != 0) {
        printf("Your choice:");
        int readedCharacters = scanf("%d", &option);
        if (readedCharacters != 1) {
            scanf("%*s");
        }
        
        // char test[40];
        // scanf("%s", test);
        // printf("%s\n", test);
        
    }

    return 0;
}