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
struct Node* CreateTree(struct Node* r, int data) {
    if (r == NULL) {
        r = (struct Node*)malloc(sizeof(struct Node));
        if (r == NULL) {
            printf("Ошибка выделения памяти");
            exit(0);
        }

        r->left = NULL;
        r->right = NULL;
        r->data = data;
        return r;
    }

    // Добавляем дубликаты в правое поддерево
    if (data >= r->data) {
        r->right = CreateTree(r->right, data);
    }
    else {
        r->left = CreateTree(r->left, data);
    }

    return r;
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

// Функция для подсчёта числа вхождений элемента в дереве
int count_occurrences(struct Node* root, int value) {
    if (root == NULL) {
        return 0;
    }
    int count = 0;
    if (root->data == value) {
        count = 1;
    }
    return count + count_occurrences(root->left, value) + count_occurrences(root->right, value);
}

// Функция для нахождения уровней первого и последнего вхождения
void find_levels(struct Node* root, int value, int level, int* first_level, int* last_level) {
    if (root == NULL) {
        return;
    }

    if (root->data == value) {
        if (*first_level == -1) {
            *first_level = level; // Запоминаем уровень первого вхождения
        }
        *last_level = level; // Обновляем уровень последнего вхождения
    }

    find_levels(root->left, value, level + 1, first_level, last_level);
    find_levels(root->right, value, level + 1, first_level, last_level);
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

    printf("Введите значение для подсчёта вхождений: ");
    scanf("%d", &D);
    int occurrences = count_occurrences(root, D);
    printf("Значение %d встречается в дереве %d раз(а).\n", D, occurrences);

    int first_level = -1, last_level = -1;
    find_levels(root, D, 0, &first_level, &last_level);

    if (first_level != -1) {
        printf("Первое вхождение %d на уровне %d.\n", D, first_level);
        printf("Последнее вхождение %d на уровне %d.\n", D, last_level);
    }
    else {
        printf("Значение %d не найдено в дереве.\n", D);
    }

    return 0;
}
