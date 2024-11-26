#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <locale.h>

// Функция для генерации случайной матрицы смежности для неориентированного графа
int** createRandomAdjMatrix(int size) {
    int** G = (int**)malloc(size * sizeof(int*));
    for (int i = 0; i < size; i++) {
        G[i] = (int*)malloc(size * sizeof(int));
    }
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            if (i == j) {
                G[i][j] = 0;  // Нет петель
            }
            else {
                G[i][j] = rand() % 2;  // Случайное ребро (0 или 1)
                G[j][i] = G[i][j];  // Обеспечиваем симметрию для неориентированного графа
            }
        }
    }
    return G;
}

// Функция для вывода матрицы смежности
void printMatrix(int** G, int size) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            printf("%d ", G[i][j]);
        }
        printf("\n");
    }
}

// Непосредственный обход в глубину (DFS) с использованием стека
void dfsNonRecursive(int start, int** G, int size) {
    int* visited = (int*)malloc(size * sizeof(int));
    for (int i = 0; i < size; i++) {
        visited[i] = 0;  // Изначально все вершины не посещены
    }

    int* stack = (int*)malloc(size * sizeof(int)); // Стек для хранения вершин
    int top = -1;

    stack[++top] = start;  // Начинаем с заданной начальной вершины

    while (top != -1) {
        int v = stack[top--];  // Извлекаем вершину из стека

        if (!visited[v]) {
            printf("%d ", v);  // Посещаем вершину
            visited[v] = 1;     // Отмечаем как посещенную
        }

        // Добавляем непосещенные соседние вершины в стек
        for (int i = size - 1; i >= 0; i--) {
            if (G[v][i] == 1 && !visited[i]) {
                stack[++top] = i;  // Помещаем в стек
            }
        }
    }

    free(stack);
    free(visited);
}

int main() {
    setlocale(LC_ALL, "Rus");
    srand((unsigned)time(NULL));

    int size;
    printf("Введите размер матрицы: ");
    scanf("%d", &size);

    // Генерация и вывод матрицы смежности
    int** G = createRandomAdjMatrix(size);
    printf("Сгенерированная матрица смежности:\n");
    printMatrix(G, size);

    // Выполнение обхода в глубину начиная с вершины 0
    printf("Результат обхода в глубину начиная с вершины 0:\n");
    dfsNonRecursive(0, G, size);

    // Освобождение выделенной памяти
    for (int i = 0; i < size; i++) {
        free(G[i]);
    }
    free(G);

    return 0;
}