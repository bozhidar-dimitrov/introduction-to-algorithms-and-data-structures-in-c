#include <stdio.h>

// n е броят на елементите, които остават за проверка
int count_occurrences(int array[], int n, int searchElement) {
    if (n == 0) {
        return 0;
    }

    int found = 0;
    if (array[n - 1] == searchElement) {
        found = 1;
    }

    return found + count_occurrences(array, n - 1, searchElement);
}

int main(void) {
    int array[] = {3, 7, 3, 1, 3, 9, 7};
    int n = sizeof(array) / sizeof(array[0]);
    int searchElement = 3;

    printf("count_occurrences(%d) = %d\n", searchElement, count_occurrences(array, n, searchElement));

    return 0;
}
