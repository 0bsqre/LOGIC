#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include <time.h>

// Структура для хранения элемента очереди
typedef struct node {
    int vertex; // Вершина графа
    struct node* next; // Указатель на следующий элемент
} Node;

Node* head = NULL; // Указатель на голову списка

// Функция для создания нового элемента
Node* createNode(int vertex) {
    Node* p = (Node*)malloc(sizeof(Node));
    if (p == NULL) {
        printf("Ошибка при распределении памяти\n");
        exit(1);
    }
    p->vertex = vertex;
    p->next = NULL;
    return p;
}

// Функция для добавления элемента в очередь
void enqueue(int vertex) {
    Node* p = createNode(vertex);
    if (head == NULL) {
        head = p;
    }
    else {
        Node* current = head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = p;
    }
}

// Функция для удаления элемента из очереди
int dequeue() {
    if (head == NULL) {
        return -1; // Очередь пуста
    }
    Node* temp = head;
    int vertex = temp->vertex;
    head = head->next;
    free(temp);
    return vertex;
}

// Функция для проверки, пуста ли очередь
int isEmpty() {
    return head == NULL;
}

// Функция для создания матрицы смежности
void createAdjacencyMatrix(int** G, int size) {
    for (int i = 0; i < size; i++) {
        for (int j = i + 1; j < size; j++) {
            G[i][j] = rand() % 2; // Случайное значение 0 или 1
            G[j][i] = G[i][j]; // Симметричность для неориентированного графа
        }
        G[i][i] = 0; // Нет петель
    }
}

// Функция для обхода в ширину с использованием очереди на основе списка
void bfsUsingListQueue(int** G, int size, int start) {
    int* visited = (int*)malloc(size * sizeof(int));
    for (int i = 0; i < size; i++) {
        visited[i] = 0; // Инициализация массива посещенных вершин
    }

    enqueue(start);
    visited[start] = 1;
    printf("Обход в ширину (очередь на основе списка): %d ", start);

    while (!isEmpty()) {
        int current = dequeue();

        for (int i = 0; i < size; i++) {
            if (G[current][i] == 1 && !visited[i]) {
                enqueue(i);
                visited[i] = 1;
                printf("%d ", i);
            }
        }
    }
    printf("\n");
    free(visited);
}

// Функция для вывода матрицы смежности
void printAdjacencyMatrix(int** G, int size) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            printf("%d ", G[i][j]);
        }
        printf("\n");
    }
}

int main() {
    setlocale(LC_ALL, "RUS");
    srand(time(NULL)); // Инициализация генератора случайных чисел
    int size;

    printf("Введите размер матрицы: ");
    scanf("%d", &size);

    // Генерация матрицы смежности
    int** G = (int**)malloc(size * sizeof(int*));
    for (int i = 0; i < size; i++) {
        G[i] = (int*)malloc(size * sizeof(int));
    }
    createAdjacencyMatrix(G, size);
    printf("Матрица смежности:\n");
    printAdjacencyMatrix(G, size);

    // Обход в ширину с использованием очереди на основе списка
    bfsUsingListQueue(G, size, 0); // Начинаем с вершины 0

    // Освобождение памяти
    for (int i = 0; i < size; i++) {
        free(G[i]);
    }
    free(G);

    return 0;
}