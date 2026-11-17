#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 1024000   // най-голямата големина от sizes

// Масивите са глобални, защото са големи и не бива да са в стека на main
int original[N];
int arr[N];
int tmp[N];

void swap(int a[], int i, int j) {
    int temp = a[i];
    a[i] = a[j];
    a[j] = temp;
}

void copy_array(int from[], int to[], int n) {
    for (int i = 0; i < n; i++) {
        to[i] = from[i];
    }
}

void bubble_sort(int a[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int swapped = 0;

        for (int j = 0; j < n - i - 1; j++) {
            if (a[j] > a[j + 1]) {
                swap(a, j, j + 1);
                swapped = 1;
            }
        }

        if (!swapped) {
            break;
        }
    }
}

void selection_sort(int a[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int min_index = i;
        for (int j = i + 1; j < n; j++) {
            if (a[min_index] > a[j]) {
                min_index = j;
            }
        }
        if (min_index != i) {
            swap(a, min_index, i);
        }
    }
}

void insertion_sort(int a[], int n) {
    for (int i = 1; i < n; i++) {
        for (int j = i; j > 0 && a[j - 1] > a[j]; j--) {
            swap(a, j - 1, j);
        }
    }
}

void merge(int a[], int left, int mid, int right) {
    int i = left;
    int j = mid + 1;
    int k = left;

    while (i <= mid && j <= right) {
        if (a[i] <= a[j]) {
            tmp[k] = a[i];
            i++;
        } else {
            tmp[k] = a[j];
            j++;
        }
        k++;
    }

    while (i <= mid) {
        tmp[k] = a[i];
        i++;
        k++;
    }

    while (j <= right) {
        tmp[k] = a[j];
        j++;
        k++;
    }

    for (k = left; k <= right; k++) {
        a[k] = tmp[k];
    }
}

void merge_sort(int a[], int left, int right) {
    if (left >= right) {
        return;
    }

    int mid = (left + right) / 2;

    merge_sort(a, left, mid);
    merge_sort(a, mid + 1, right);
    merge(a, left, mid, right);
}

int partition(int a[], int left, int right) {
    int pivot = a[right];
    int i = left;

    for (int j = left; j < right; j++) {
        if (a[j] < pivot) {
            swap(a, i, j);
            i++;
        }
    }

    swap(a, i, right);
    return i;
}

void quick_sort(int a[], int left, int right) {
    if (left >= right) {
        return;
    }

    int p = partition(a, left, right);

    quick_sort(a, left, p - 1);
    quick_sort(a, p + 1, right);
}

// Отпечатва колко секунди са минали от start насам
void print_time(clock_t start) {
    double seconds = (double)(clock() - start) / CLOCKS_PER_SEC;
    printf("%10.3f", seconds);
}

int main(void) {

    // Всяка големина е 4 пъти по-голяма от предишната:
    // при O(n^2) времето расте около 16 пъти, при O(n log n) - малко над 4 пъти
    int sizes[6] = {1000, 4000, 16000, 64000, 256000, 1024000};
    int count = 6;

    srand(time(NULL));

    for (int i = 0; i < N; i++) {
        original[i] = rand();
    }

    printf("Time in second\n\n");
    printf("%8s%10s%10s%10s%10s%10s%10s\n", "n", "Bubble", "Selection", "Insertion", "Merge", "Quick", "Q. worst");

    for (int s = 0; s < count; s++) {
        int n = sizes[s];
        clock_t start;

        printf("%8d", n);

        // Всеки алгоритъм сортира копие на същите n случайни числа.
        // Над 64000 елемента O(n^2) алгоритмите биха работили минути, затова ги пропускаме.
        if (n <= 64000) {
            copy_array(original, arr, n);
            start = clock();
            bubble_sort(arr, n);
            print_time(start);

            copy_array(original, arr, n);
            start = clock();
            selection_sort(arr, n);
            print_time(start);

            copy_array(original, arr, n);
            start = clock();
            insertion_sort(arr, n);
            print_time(start);
        } else {
            printf("%10s%10s%10s", "-", "-", "-");
        }

        copy_array(original, arr, n);
        start = clock();
        merge_sort(arr, 0, n - 1);
        print_time(start);

        copy_array(original, arr, n);
        start = clock();
        quick_sort(arr, 0, n - 1);
        print_time(start);

        // Най-лошият случай за схемата на Ломуто: масивът вече е сортиран и опорният
        // елемент винаги е най-големият. Сложността става O(n^2), а рекурсията е дълбока n нива.
        if (n <= 64000) {
            start = clock();
            quick_sort(arr, 0, n - 1);
            print_time(start);
        } else {
            printf("%10s", "-");
        }

        printf("\n");
    }

    return 0;
}
