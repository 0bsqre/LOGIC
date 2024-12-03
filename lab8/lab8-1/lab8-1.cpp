#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <queue>
#include <locale.h>

void createAdjacencyMatrix(int** G, int size) {
    for (int i = 0; i < size; i++) {
        for (int j = i + 1; j < size; j++) {
            G[i][j] = rand() % 2; // Случайное значение 0 или 1
            G[j][i] = G[i][j]; // Симметричность для неориентированного графа
        }
        G[i][i] = 0; // Нет петель
    }
}

void printAdjacencyMatrix(int** G, int size) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            printf("%d ", G[i][j]);
        }
        printf("\n");
    }
}

void bfs(int** G, int size, int start) {
    int* visited = (int*)malloc(size * sizeof(int));
    for (int i = 0; i < size; i++) {
        visited[i] = 0; // Инициализация массива посещенных вершин
    }

    std::queue<int> Q;
    Q.push(start);
    visited[start] = 1;
    printf("Обход в ширину: %d ", start);

    while (!Q.empty()) {
        int current = Q.front();
        Q.pop();

        for (int i = 0; i < size; i++) {
            if (G[current][i] == 1 && !visited[i]) {
                Q.push(i);
                visited[i] = 1;
                printf("%d ", i);
            }
        }
    }
    printf("\n");
    free(visited);
}

int** createAdjacencyList(int** G, int size) {
    int** adjacencyList = (int**)malloc(size * sizeof(int*));
    for (int i = 0; i < size; i++) {
        adjacencyList[i] = (int*)malloc((size + 1) * sizeof(int)); // +1 для завершающего элемента
    }

    for (int i = 0; i < size; i++) {
        int count = 0;
        for (int j = 0; j < size; j++) {
            if (G[i][j] == 1) {
                adjacencyList[i][count++] = j;
            }
        }
        adjacencyList[i][count] = -1; // Завершающий элемент для списка
    }
    return adjacencyList;
}

void printAdjacencyList(int** adjacencyList, int size) {
    printf("Список смежности:\n");
    for (int i = 0; i < size; i++) {
        printf("%d: ", i);
        for (int j = 0; adjacencyList[i][j] != -1; j++) {
            printf("%d ", adjacencyList[i][j]);
        }
        printf("\n");
    }
}

void bfsUsingAdjacencyList(int** adjacencyList, int size, int start) {
    int* visited = (int*)malloc(size * sizeof(int));
    for (int i = 0; i < size; i++) {
        visited[i] = 0; // Инициализация массива посещенных вершин
    }

    std::queue<int> Q;
    Q.push(start);
    visited[start] = 1;
    printf("Обход в ширину (список смежности): %d ", start);

    while (!Q.empty()) {
        int current = Q.front();
        Q.pop();

        for (int i = 0; adjacencyList[current][i] != -1; i++) {
            int neighbor = adjacencyList[current][i];
            if (!visited[neighbor]) {
                Q.push(neighbor);
                visited[neighbor] = 1;
                printf("%d ", neighbor);
            }
        }
    }
    printf("\n");
    free(visited);
}

int main() {
    setlocale(LC_ALL, "Rus");
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

    // Обход в ширину с использованием матрицы смежности
    bfs(G, size, 0); // Начинаем с вершины 0

    // Создание списка смежности
    int** adjacencyList = createAdjacencyList(G, size);

    // Вывод списка смежности
    printAdjacencyList(adjacencyList, size);

    // Обход в ширину с использованием списка смежности
    bfsUsingAdjacencyList(adjacencyList, size, 0); // Начинаем с вершины 0

    // Освобождение памяти
    for (int i = 0; i < size; i++) {
        free(G[i]);
        free(adjacencyList[i]);
    }
    free(G);
    free(adjacencyList);

    return 0;
}