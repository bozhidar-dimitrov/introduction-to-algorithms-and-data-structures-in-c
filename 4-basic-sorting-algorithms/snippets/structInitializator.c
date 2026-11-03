#include <stdio.h>
#include <string.h>

typedef struct {
    int number;
    char name[40];
    double averageGrade;
} Student;

int main(void) {

    Student ivan;
    ivan.number = 15;
    strcpy(ivan.name, "Ivan");
    ivan.averageGrade = 5.5;

    int arr[3];
    arr[0] = 1;
    arr[1] = 2;
    arr[2] = 3;

    int arr2[3] = {1, 2, 3};
    //arr2 = {4, 5, 6}; not allowed

    Student anna = {1, "Anna", 5.5}; //Normal struct initializer
    Student nikola = { //Dedicated struct initializer 
        .name = "Nikola", 
        .number = 2, 
        .averageGrade = 5.75
    };

    return 0;
}