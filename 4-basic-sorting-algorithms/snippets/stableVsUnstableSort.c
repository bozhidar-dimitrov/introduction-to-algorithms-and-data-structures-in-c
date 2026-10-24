#include <stdio.h>
#include <string.h>

typedef struct {
    int number;
    char name[40];
    double averageGrade;
} Student;

// Връща 1, ако a трябва да е след b по избраното поле (1 = номер, 2 = име, 3 = успех).
// При равни стойности връща 0 - това е важно за стабилността на сортирането.
int isGreater(Student a, Student b, int field) {
    if (field == 1) {
        return a.number > b.number;
    } else if (field == 2) {
        return strcmp(a.name, b.name) > 0;
    } else {
        return a.averageGrade > b.averageGrade;
    }
}

int main(void) {

    // Редът в началото е по номер в клас. Ученици с равен успех: Ivan/Georgi/Dimitar (5.50) и Maria/Elena/Stefan (4.00).
    Student original[10] = {
        {1, "Ivan", 5.50},
        {2, "Maria", 4.00},
        {3, "Georgi", 5.50},
        {4, "Elena", 4.00},
        {5, "Petar", 6.00},
        {6, "Dimitar", 5.50},
        {7, "Anna", 3.00},
        {8, "Stefan", 4.00},
        {9, "Nikolay", 6.00},
        {10, "Viktoria", 3.00}
    };
    Student students[10];
    int count = 10;

    // Работният масив започва като копие на оригинала
    for (int i = 0; i < count; i++) {
        students[i] = original[i];
    }

    int method = 1; // 1 = selection sort, 2 = bubble sort, 3 = insertion sort
    int running = 1;

    while (running) {
        printf("\n===== MENU =====\n");
        if (method == 1) {
            printf("Current method: selection sort (unstable)\n");
        } else if (method == 2) {
            printf("Current method: bubble sort (stable)\n");
        } else {
            printf("Current method: insertion sort (stable)\n");
        }
        printf("1. Print the table\n");
        printf("2. Choose sorting method\n");
        printf("3. Sort by class number\n");
        printf("4. Sort by name\n");
        printf("5. Sort by average grade\n");
        printf("0. Exit\n");
        printf("Your choice: ");

        int choice = -1;
        if (scanf("%d", &choice) != 1) {
            scanf("%*s"); // изхвърля неразбрания вход, иначе цикълът ще се върти безкрайно
            choice = -1;
        }

        if (choice == 0) {
            running = 0;
        } else if (choice == 1) {
            printf("\n%-6s %-12s %-6s\n", "No.", "Name", "Grade");
            printf("------ ------------ ------\n");
            for (int i = 0; i < count; i++) {
                printf("%-6d %-12s %-6.2lf\n", students[i].number, students[i].name, students[i].averageGrade);
            }
        } else if (choice == 2) {
            printf("1. Selection sort\n");
            printf("2. Bubble sort\n");
            printf("3. Insertion sort\n");
            printf("Your choice: ");
            int newMethod = 0;
            if (scanf("%d", &newMethod) != 1) {
                scanf("%*s");
                newMethod = 0;
            }
            if (newMethod >= 1 && newMethod <= 3) {
                method = newMethod;
            } else {
                printf("Invalid method.\n");
            }
        } else if (choice >= 3 && choice <= 5) {
            // 3 -> номер, 4 -> име, 5 -> успех
            int field = choice - 2;

            // Всяко сортиране започва от оригиналния ред, за да е демонстрацията повтаряема
            for (int i = 0; i < count; i++) {
                students[i] = original[i];
            }

            if (method == 1) {
                // Selection sort: разменя най-малкия с първия от неподредената част,
                // като прескача равните елементи -> нестабилен
                for (int i = 0; i < count - 1; i++) {
                    int minIndex = i;
                    for (int j = i + 1; j < count; j++) {
                        if (isGreater(students[minIndex], students[j], field)) {
                            minIndex = j;
                        }
                    }
                    if (minIndex != i) {
                        Student tmp = students[i];
                        students[i] = students[minIndex];
                        students[minIndex] = tmp;
                    }
                }
            } else if (method == 2) {
                // Bubble sort: разменя само съседни елементи и само при строго по-голям -> стабилен
                for (int i = 0; i < count - 1; i++) {
                    for (int j = 0; j < count - 1 - i; j++) {
                        if (isGreater(students[j], students[j + 1], field)) {
                            Student tmp = students[j];
                            students[j] = students[j + 1];
                            students[j + 1] = tmp;
                        }
                    }
                }
            } else {
                // Insertion sort: връща елемента назад със съседни размени, докато предишният е строго по-голям -> стабилен
                for (int i = 1; i < count; i++) {
                    int j = i;
                    while (j > 0 && isGreater(students[j - 1], students[j], field)) {
                        Student tmp = students[j - 1];
                        students[j - 1] = students[j];
                        students[j] = tmp;
                        j--;
                    }
                }
            }

            printf("Sorted. Choose option 1 to see the table.\n");
        } else {
            printf("Invalid choice.\n");
        }
    }

    return 0;
}
