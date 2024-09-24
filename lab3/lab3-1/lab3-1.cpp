#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

// Структура для хранения элемента очереди
typedef struct node {
    char inf[256];    // Информация об элементе
    int priority;     // Приоритет элемента
    struct node* next; // Указатель на следующий элемент
} Node;

Node* head = NULL; // Указатель на голову списка

// Функция для создания нового элемента
Node* get_struct(void) {
    setlocale(LC_ALL, "RUS");
    Node* p = (Node*)malloc(sizeof(Node));
    if (p == NULL) {
        printf("Ошибка при распределении памяти\n");
        exit(1);
    }

    printf("Введите название объекта: \n");
    scanf("%s", p->inf);

    printf("Введите приоритет объекта: \n");
    scanf("%d", &(p->priority));

    p->next = NULL;
    return p;
}

// Функция для добавления элемента в очередь с учетом приоритета
void spstore(void) {
    Node* p = get_struct();
    if (head == NULL || head->priority < p->priority) {
        p->next = head;
        head = p;
    }
    else {
        Node* current = head;
        while (current->next != NULL && current->next->priority >= p->priority) {
            current = current->next;
        }
        p->next = current->next;
        current->next = p;
    }
}

// Функция для просмотра содержимого списка
void review(void) {
    setlocale(LC_ALL, "RUS");
    Node* struc = head;
    if (head == NULL) {
        printf("Список пуст\n");
        return;
    }
    while (struc) {
        printf("%d) %s\n", struc->priority, struc->inf);
        struc = struc->next;
    }

}

int main() {
    spstore();
    spstore();
    spstore();
    review();
    return 0;
}
