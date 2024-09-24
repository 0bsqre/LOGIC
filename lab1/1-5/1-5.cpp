#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
#include <string.h>  
#define MAX_NAME_LENGTH 20
#define MAX_GROUP_LENGTH 10

typedef struct {
    char surname[MAX_NAME_LENGTH];
    char name[MAX_NAME_LENGTH];
    char group[MAX_GROUP_LENGTH];
} Student;

void inputStudentData(Student* stud) {
    printf("Введите фамилию студента: ");
    scanf("%19s", stud->surname);
    printf("Введите имя студента %s: ", stud->surname);
    scanf("%19s", stud->name);
    printf("Введите номер группы студента %s %s (например, 101A): ", stud->surname, stud->name);
    scanf("%9s", stud->group);
}

void printStudent(const Student* stud) {
    printf("Студент %s %s, номер группы %s\n", stud->surname, stud->name, stud->group);
}

int main() {
    setlocale(LC_ALL, "Russian");

    int num_students;
    printf("Введите количество студентов: ");
    scanf("%d", &num_students);

    Student* students = (Student*)malloc(num_students * sizeof(Student));
    if (students == NULL) {
        printf("Ошибка выделения памяти!\n");
        return 1;
    }

    for (int i = 0; i < num_students; i++) {
        inputStudentData(&students[i]);
    }

    printf("\nВсе студенты:\n");
    for (int i = 0; i < num_students; i++) {
        printStudent(&students[i]);
    }

    char need_surname[MAX_NAME_LENGTH];
    printf("\nВведите фамилию необходимого студента: ");
    scanf("%19s", need_surname);

    printf("\nСтуденты с фамилией %s:\n", need_surname);
    for (int i = 0; i < num_students; i++) {
        if (strcmp(students[i].surname, need_surname) == 0) {
            printStudent(&students[i]);
        }
    }

    // Освобождаем выделенную память
    free(students);
    return 0;
}
