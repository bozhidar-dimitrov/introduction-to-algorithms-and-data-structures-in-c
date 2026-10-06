#include <stdio.h>
#include <string.h>

struct student {
    int number;
    char name[40];
    double averageGrade;
};

typedef struct {
    int number;
    char name[40];
    double averageGrade;
} Student;

int main(void) {

    struct student viktor;
    viktor.number = 5;
    strcpy(viktor.name, "Viktor");
    viktor.averageGrade = 5.92;

    printf("Number:%d\n", viktor.number);
    printf("Name:%s\n", viktor.name);
    printf("Average grade:%.2lf\n", viktor.averageGrade);

    Student asen;

    return 0;
}