#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>


struct node {
    char inf[256];
    struct node* next;
};

struct node* head = NULL;
struct node* last = NULL;

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

    return p;
}

void enqueue(void) {
    struct node* p = get_struct();
    if (head == NULL && p != NULL) {
        head = p;
        last = p;
    }
    else if (head != NULL && p != NULL) {
        last->next = p;
        last = p;
    }
}

void dequeue(void) {
    setlocale(LC_ALL, "RUS");
    struct node* temp = head;
    if (head == NULL) {
        printf("Очередь пуста\n");
        return;
    }
    head = head->next; // Удаляем первый элемент
    if (head == NULL) {
        last = NULL; // Если очередь стала пустой, обнуляем указатель на последний элемент
    }
    free(temp); // Освобождаем память
}

void review(void) {
    setlocale(LC_ALL, "RUS");
    struct node* struc = head;
    if (head == NULL) {
        printf("Очередь пуста\n");
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
    do {
        enqueue(); // Добавление нового элемента в очередь
        printf("Хотите добавить ещё один объект? (y/n): ");
        scanf(" %c", &choice); // Запрос на продолжение добавления

        // Очистка буфера ввода
        while (getchar() != '\n') continue;

    } while (choice == 'y' || choice == 'Y');

    printf("Содержимое очереди:\n");
    review(); // Вывод содержимого очереди

    // Удаление элементов из очереди до её опустошения
    if (head != NULL) {
        dequeue(); // Удаляем первый элемент
        review();
    }
    else {
        printf("Очередь опустошена.\n");
    }
    return 0;
}
