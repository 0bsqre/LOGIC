#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>


struct node {
    char inf[256];          // Данные элемента
    struct node* next;     // Указатель на следующий элемент
};

struct node* top = NULL; // Указатель на верхний элемент стека

// Функция для создания нового элемента
struct node* get_struct(void) {
    struct node* p = NULL;
    char s[256];
    setlocale(LC_ALL, "RUS");

    if ((p = (struct node*)malloc(sizeof(struct node))) == NULL) {
        printf("Ошибка при распределении памяти\n");
        exit(1);
    }

    printf("Введите название объекта: \n");
    scanf("%s", s);
    if (*s == 0) {
        printf("Запись не была произведена\n");
        free(p); // Освобождаем память, если запись не была произведена
        return NULL;
    }
    strcpy(p->inf, s);
    p->next = NULL;

    return p; // Возвращаем указатель на созданный элемент
}

// Функция для добавления элемента в стек
void push(void) {
    struct node* p = get_struct();
    if (p != NULL) {
        p->next = top; // Новый элемент указывает на текущий верхний элемент
        top = p;       // Обновляем верхний элемент
    }
}

// Функция для удаления элемента из стека
void pop(void) {
    setlocale(LC_ALL, "RUS");
    if (top == NULL) {
        printf("Стек пуст\n");
        return;
    }
    struct node* temp = top; // Сохраняем указатель на верхний элемент
    top = top->next;         // Обновляем верхний элемент
    free(temp);              // Освобождаем память
}

// Функция для просмотра содержимого стека
void review(void) {
    setlocale(LC_ALL, "RUS");
    struct node* struc = top;
    if (top == NULL) {
        printf("Стек пуст\n");
        return;
    }
    while (struc) {
        printf("%s ", struc->inf);
        struc = struc->next;
    }
    printf("\n");
}

int main() {
    char choice;
    setlocale(LC_ALL, "RUS");

    do {
        printf("Выберите действие:\n");
        printf("1. Добавить элемент в стек\n");
        printf("2. Удалить элемент из стека\n");
        printf("3. Просмотреть содержимое стека\n");
        printf("4. Выход\n");
        printf("Ваш выбор: ");
        scanf(" %c", &choice); // Запрос на выбор действия

        switch (choice) {
        case '1':
            push(); // Добавление элемента в стек
            break;
        case '2':
            pop(); // Удаление элемента из стека
            break;
        case '3':
            review(); // Просмотр содержимого стека
            break;
        case '4':
            printf("Выход из программы.\n");
            break;
        default:
            printf("Неверный выбор. Пожалуйста, попробуйте снова.\n");
        }

        // Очистка буфера ввода
        while (getchar() != '\n') continue;

    } while (choice != '4'); // Продолжаем, пока пользователь не выберет выход

    return 0;
}