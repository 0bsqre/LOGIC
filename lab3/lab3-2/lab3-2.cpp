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

struct node* get_struct(void)

{
    struct node* p = NULL;
    char s[256];
    setlocale(LC_ALL, "RUS");

    if ((p = (struct node*)malloc(sizeof(struct node))) == NULL)
    {
        printf("Ошибка при распределении памяти\n");
        exit(1);
    }

    printf("Введите название объекта: \n");
    scanf_s("%s", s);
    if (*s == 0)
    {
        printf("Запись не была произведена\n");
        return NULL;
    }
    strcpy(p->inf, s);

    p->next = NULL;

    return p;
}

void enqueue(void)
{
    struct node* p = NULL;
    p = get_struct();
    if (head == NULL && p != NULL)
    {
        head = p;
        last = p;
    }
    else if (head != NULL && p != NULL)
    {
        last->next = p;
        last = p;
    }
    return;
}

void dequeue(void)
{
    setlocale(LC_ALL, "RUS");
    struct node* temp = head;
    if (head == NULL)
    {
        printf("Очередь пуста\n");
        return;
    }
    head = head->next;
    if (head == NULL)
    {
        last = NULL;
    }
    free(temp);
    return;
}

void review(void)
{
    setlocale(LC_ALL, "RUS");
    struct node* struc = head;
    if (head == NULL)
    {
        printf("Очередь пуста\n");
    }
    while (struc)
    {
        printf("%s ", struc->inf);
        struc = struc->next;
    }
    printf("\n");
}

int main() {
    enqueue();
    enqueue();
    enqueue();
    review();
    dequeue();
    review();
    return 0;
}
