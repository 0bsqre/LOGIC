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
    push();
    push();
    push();
    review();
    pop();
    review();
    return 0;
}
