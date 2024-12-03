#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include <time.h>
#include <queue>

// Структура для хранения элемента очереди на основе списка
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

// Функция для обхода в ширину с использованием стандартной очереди
void bfsUsingStdQueue(int** G, int size, int start) {
    int* visited = (int*)malloc(size * sizeof(int));
    for (int i = 0; i < size; i++) {
        visited[i] = 0; // Инициализация массива посещенных вершин
    }

    std::queue<int> Q;
    Q.push(start);
    visited[start] = 1;
    printf("Обход в ширину (стандартная очередь): %d ", start);

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

    // Измерение времени для стандартной очереди
    clock_t start_time = clock();
    bfsUsingStdQueue(G, size, 0); // Начинаем с вершины 0
    clock_t end_time = clock();
    double time_taken_std = ((double)(end_time - start_time)) / CLOCKS_PER_SEC;
    printf("Время выполнения (стандартная очередь): %f секунд\n", time_taken_std);

    // Измерение времени для очереди на основе списка
    start_time = clock();
    bfsUsingListQueue(G, size, 0); // Начинаем с вершины 0
    end_time = clock();
    double time_taken_list = ((double)(end_time - start_time)) / CLOCKS_PER_SEC;
    printf("Время выполнения (очередь на основе списка): %f секунд\n", time_taken_list);

    // Освобождение памяти
    for (int i = 0; i < size; i++) {
        free(G[i]);
    }
    free(G);

    return 0;
}


//#define _CRT_SECURE_NO_WARNINGS
//#include <stdio.h>
//#include <stdlib.h>
//#include <string.h>
//#include <locale.h>
//#include <time.h>
//#include <queue>
//
//// Структура для хранения элемента очереди на основе списка
//typedef struct node {
//    int vertex; // Вершина графа
//    struct node* next; // Указатель на следующий элемент
//} Node;
//
//Node* head = NULL; // Указатель на голову списка
//
//// Функция для создания нового элемента
//Node* createNode(int vertex) {
//    Node* p = (Node*)malloc(sizeof(Node));
//    if (p == NULL) {
//        printf("Ошибка при распределении памяти\n");
//        exit(1);
//    }
//    p->vertex = vertex;
//    p->next = NULL;
//    return p;
//}
//
//// Функция для добавления элемента в очередь
//void enqueue(int vertex) {
//    Node* p = createNode(vertex);
//    if (head == NULL) {
//        head = p;
//    }
//    else {
//        Node* current = head;
//        while (current->next != NULL) {
//            current = current->next;
//        }
//        current->next = p;
//    }
//}
//
//// Функция для удаления элемента из очереди
//int dequeue() {
//    if (head == NULL) {
//        return -1; // Очередь пуста
//    }
//    Node* temp = head;
//    int vertex = temp->vertex;
//    head = head->next;
//    free(temp);
//    return vertex;
//}
//
//// Функция для проверки, пуста ли очередь
//int isEmpty() {
//    return head == NULL;
//}
//
//// Функция для создания матрицы смежности
//void createAdjacencyMatrix(int** G, int size) {
//    for (int i = 0; i < size; i++) {
//        for (int j = i + 1; j < size; j++) {
//            G[i][j] = rand() % 2; // Случайное значение 0 или 1
//            G[j][i] = G[i][j]; // Симметричность для неориентированного графа
//        }
//        G[i][i] = 0; // Нет петель
//    }
//}
//
//// Функция для создания списка смежности
//int** createAdjacencyList(int** G, int size) {
//    int** adjacencyList = (int**)malloc(size * sizeof(int*));
//    for (int i = 0; i < size; i++) {
//        adjacencyList[i] = (int*)malloc((size + 1) * sizeof(int)); // +1 для завершающего элемента
//    }
//
//    for (int i = 0; i < size; i++) {
//        int count = 0;
//        for (int j = 0; j < size; j++) {
//            if (G[i][j] == 1) {
//                adjacencyList[i][count++] = j;
//            }
//        }
//        adjacencyList[i][count] = -1; // Завершающий элемент для списка
//    }
//    return adjacencyList;
//}
//
//// Функция для вывода списка смежности
//void printAdjacencyList(int** adjacencyList, int size) {
//    printf("Список смежности:\n");
//    for (int i = 0; i < size; i++) {
//        printf("%d: ", i);
//        for (int j = 0; adjacencyList[i][j] != -1; j++) {
//            printf("%d ", adjacencyList[i][j]);
//        }
//        printf("\n");
//    }
//}
//
//// Функция для обхода в ширину с использованием очереди на основе списка
//void bfsUsingListQueue(int** G, int size, int start) {
//    int* visited = (int*)malloc(size * sizeof(int));
//    for (int i = 0; i < size; i++) {
//        visited[i] = 0; // Инициализация массива посещенных вершин
//    }
//
//    enqueue(start);
//    visited[start] = 1;
//    printf("Обход в ширину (очередь на основе списка): %d ", start);
//
//    while (!isEmpty()) {
//        int current = dequeue();
//
//        for (int i = 0; i < size; i++) {
//            if (G[current][i] == 1 && !visited[i]) {
//                enqueue(i);
//                visited[i] = 1;
//                printf("%d ", i);
//            }
//        }
//    }
//    printf("\n");
//    free(visited);
//}
//
//// Функция для обхода в ширину с использованием стандартной очереди
//void bfsUsingStdQueue(int** G, int size, int start) {
//    int* visited = (int*)malloc(size * sizeof(int));
//    for (int i = 0; i < size; i++) {
//        visited[i] = 0; // Инициализация массива посещенных вершин
//    }
//
//    std::queue<int> Q;
//    Q.push(start);
//    visited[start] = 1;
//    printf("Обход в ширину (стандартная очередь): %d ", start);
//
//    while (!Q.empty()) {
//        int current = Q.front();
//        Q.pop();
//
//        for (int i = 0; i < size; i++) {
//            if (G[current][i] == 1 && !visited[i]) {
//                Q.push(i);
//                visited[i] = 1;
//                printf("%d ", i);
//            }
//        }
//    }
//    printf("\n");
//    free(visited);
//}
//
//// Функция для вывода матрицы смежности
//void printAdjacencyMatrix(int** G, int size) {
//    for (int i = 0; i < size; i++) {
//        for (int j = 0; j < size; j++) {
//            printf("%d ", G[i][j]);
//        }
//        printf("\n");
//    }
//}
//
//int main() {
//    setlocale(LC_ALL,"RUS");
//    srand(time(NULL)); // Инициализация генератора случайных чисел
//    int size;
//
//    printf("Введите размер матрицы: ");
//    scanf("%d", &size);
//
//    // Генерация матрицы смежности
//    int** G = (int**)malloc(size * sizeof(int*));
//    for (int i = 0; i < size; i++) {
//        G[i] = (int*)malloc(size * sizeof(int));
//    }
//    createAdjacencyMatrix(G, size);
//    printf("Матрица смежности:\n");
//    printAdjacencyMatrix(G, size);
//
//    // Создание списка смежности
//    int** adjacencyList = createAdjacencyList(G, size);
//    printAdjacencyList(adjacencyList, size); // Вывод списка смежности
//
//    // Измерение времени для стандартной очереди
//    clock_t start_time = clock();
//    bfsUsingStdQueue(G, size, 0); // Начинаем с вершины 0
//    clock_t end_time = clock();
//    double time_taken_std = ((double)(end_time - start_time)) / CLOCKS_PER_SEC;
//    printf("Время выполнения (стандартная очередь): %f секунд\n", time_taken_std);
//
//    // Измерение времени для очереди на основе списка
//    start_time = clock();
//    bfsUsingListQueue(G, size, 0); // Начинаем с вершины 0
//    end_time = clock();
//    double time_taken_list = ((double)(end_time - start_time)) / CLOCKS_PER_SEC;
//    printf("Время выполнения (очередь на основе списка): %f секунд\n", time_taken_list);
//
//    // Освобождение памяти
//    for (int i = 0; i < size; i++) {
//        free(G[i]);
//        free(adjacencyList[i]);
//    }
//    free(G);
//    free(adjacencyList);
//
//    return 0;
//}