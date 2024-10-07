#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h> 
#include <stdlib.h> 
#include <locale.h>

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// Функция для создания дерева
struct Node* CreateTree(struct Node* root, int data) {
    if (root == NULL) {
        struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
        if (newNode == NULL) {
            printf("Ошибка выделения памяти");
            exit(0);
        }
        newNode->data = data;
        newNode->left = NULL;
        newNode->right = NULL;
        return newNode;
    }

    // Проверка на уникальность значения
    if (data < root->data) {
        root->left = CreateTree(root->left, data);
    }
    else if (data > root->data) {
        root->right = CreateTree(root->right, data);
    }
    else {
        printf("Значение %d уже существует в дереве.\n", data);
    }

    return root;
}

// Функция для вывода дерева
void print_tree(struct Node* r, int l) {
    if (r == NULL) {
        return;
    }

    print_tree(r->right, l + 1);
    for (int i = 0; i < l; i++) {
        printf(" ");
    }
    printf("%d\n", r->data);
    print_tree(r->left, l + 1);
}

// Функция для поиска значения в дереве
struct Node* search(struct Node* root, int value) {
    if (root == NULL || root->data == value) {
        return root;
    }
    if (value < root->data) {
        return search(root->left, value);
    }
    else {
        return search(root->right, value);
    }
}

int main() {
    setlocale(LC_ALL, "");
    int D, start = 1;
    struct Node* root = NULL;

    printf("-1 - окончание построения дерева\n");
    while (start) {
        printf("Введите число: ");
        scanf("%d", &D);
        if (D == -1) {
            printf("Построение дерева окончено\n\n");
            start = 0;
        }
        else {
            root = CreateTree(root, D);
        }
    }

    print_tree(root, 0);

    printf("Введите значение для поиска: ");
    scanf("%d", &D);
    struct Node* found = search(root, D);
    if (found != NULL) {
        printf("Значение %d найдено в дереве.\n", D);
    }
    else {
        printf("Значение %d не найдено в дереве.\n", D);
    }

    return 0;
}
