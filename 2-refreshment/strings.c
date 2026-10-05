#include <stdio.h>

int main() {

    char name[6] = {'Y', 'a', 'v', 'o', 'r', '\0'};
    for (int i = 0; i < 5; i++) {
        printf("%c", name[i]);
    }
    printf("\n");
    for (int i = 0; name[i] != '\0'; i++) {
        printf("%c", name[i]);
    }

    char name2[5] = "Anna";
    char name3[] = "Neli";

    printf("\n");
    printf("%s", name3);

    return 0;
}