//#define _CRT_SECURE_NO_WARNINGS
//#include <stdio.h>
//#include <stdlib.h>
//#include <time.h>
//#include <locale.h>
//
//// Структура для узла списка смежности
//typedef struct AdjListNode {
//    int dest;
//    struct AdjListNode* next;
//} AdjListNode;
//
//// Структура для списка смежности
//typedef struct AdjList {
//    AdjListNode* head;
//} AdjList;
//
//// Структура для графа
//typedef struct Graph {
//    int V;
//    AdjList* array;
//} Graph;
//
//// Функция для создания нового узла списка смежности
//AdjListNode* newAdjListNode(int dest) {
//    AdjListNode* newNode = (AdjListNode*)malloc(sizeof(AdjListNode));
//    newNode->dest = dest;
//    newNode->next = NULL;
//    return newNode;
//}
//
//// Функция для создания графа с V вершинами
//Graph* createGraph(int V) {
//    Graph* graph = (Graph*)malloc(sizeof(Graph));
//    graph->V = V;
//    graph->array = (AdjList*)malloc(V * sizeof(AdjList));
//    for (int i = 0; i < V; ++i) {
//        graph->array[i].head = NULL;
//    }
//    return graph;
//}
//
//// Функция для добавления ребра в неориентированный граф
//void addEdge(Graph* graph, int src, int dest) {
//    // Добавляем ребро от src до dest
//    AdjListNode* newNode = newAdjListNode(dest);
//    newNode->next = graph->array[src].head;
//    graph->array[src].head = newNode;
//
//    // Поскольку граф неориентированный, добавляем ребро от dest до src также
//    newNode = newAdjListNode(src);
//    newNode->next = graph->array[dest].head;
//    graph->array[dest].head = newNode;
//}
//
//// Функция для генерации случайной матрицы смежности для неориентированного графа
//int** createRandomAdjMatrix(int size) {
//    int** G = (int**)malloc(size * sizeof(int*));
//    for (int i = 0; i < size; i++) {
//        G[i] = (int*)malloc(size * sizeof(int));
//    }
//    for (int i = 0; i < size; i++) {
//        for (int j = 0; j < size; j++) {
//            if (i == j) {
//                G[i][j] = 0;
//            }
//            else {
//                G[i][j] = rand() % 2;
//                G[j][i] = G[i][j];  // Обеспечиваем симметрию для неориентированного графа
//            }
//        }
//    }
//    return G;
//}
//
//// Функция для вывода матрицы смежности
//void printMatrix(int** G, int size) {
//    for (int i = 0; i < size; i++) {
//        for (int j = 0; j < size; j++) {
//            printf("%d ", G[i][j]);
//        }
//        printf("\n");
//    }
//}
//
//// Рекурсивная вспомогательная функция DFS для представления в виде списка смежности
//void DFSUtil(int v, int visited[], Graph* graph) {
//    visited[v] = 1;
//    printf("%d ", v);
//
//    AdjListNode* temp = graph->array[v].head;
//    while (temp) {
//        int adjVertex = temp->dest;
//        if (!visited[adjVertex]) {
//            DFSUtil(adjVertex, visited, graph);
//        }
//        temp = temp->next;
//    }
//}
//
//// Выполнение обхода в глубину с использованием списка смежности
//void DFS(Graph* graph, int startVertex) {
//    int* visited = (int*)malloc(graph->V * sizeof(int));
//    for (int i = 0; i < graph->V; i++) {
//        visited[i] = 0;
//    }
//    DFSUtil(startVertex, visited, graph);
//    free(visited);
//}
//
//int main() {
//    setlocale(LC_ALL, "Rus");
//    srand((unsigned)time(NULL));
//
//    int size;
//    printf("Введите размер матрицы: ");
//    scanf("%d", &size);
//
//    // Генерация и вывод матрицы смежности
//    int** G = createRandomAdjMatrix(size);
//    printf("Сгенерированная матрица смежности:\n");
//    printMatrix(G, size);
//
//    // Создание графа из матрицы смежности
//    Graph* graph = createGraph(size);
//    for (int i = 0; i < size; i++) {
//        for (int j = i + 1; j < size; j++) {
//            if (G[i][j] == 1) {
//                addEdge(graph, i, j);
//            }
//        }
//    }
//
//    // Выполнение обхода в глубину начиная с вершины 0
//    printf("Результат обхода в глубину начиная с вершины 0:\n");
//    DFS(graph, 0);
//
//    // Освобождение выделенной памяти
//    for (int i = 0; i < size; i++) {
//        free(G[i]);
//    }
//    free(G);
//
//    for (int i = 0; i < size; i++) {
//        AdjListNode* current = graph->array[i].head;
//        while (current) {
//            AdjListNode* temp = current;
//            current = current->next;
//            free(temp);
//        }
//    }
//    free(graph->array);
//    free(graph);
//
//    return 0;
//}
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <locale.h>

void dfs(int** adj_matrix, int* visited, int start, int n) {
    visited[start] = 1;
    printf("%d ", start);

    for (int i = 0; i < n; i++) {
        if (adj_matrix[start][i] && !visited[i]) {
            dfs(adj_matrix, visited, i, n);
        }
    }
}

void dfs_adj_list(int** adj_list, int* visited, int start, int n) {
    visited[start] = 1;
    printf("%d ", start);

    for (int i = 0; i < adj_list[start][0]; i++) {
        int neighbor = adj_list[start][i + 1];
        if (!visited[neighbor]) {
            dfs_adj_list(adj_list, visited, neighbor, n);
        }
    }
}

int main() {
    setlocale(LC_ALL,"RUS");
    int n;
    printf("Введите количество вершин в графе: ");
    scanf("%d", &n);

    // Генерация матрицы смежности
    int** adj_matrix = (int**)malloc(n * sizeof(int*));
    for (int i = 0; i < n; i++) {
        adj_matrix[i] = (int*)malloc(n * sizeof(int));
    }

    // Заполнение матрицы смежности случайными значениями 0 или 1
    srand(time(NULL));
    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            adj_matrix[i][j] = rand() % 2;
            adj_matrix[j][i] = adj_matrix[i][j];
        }
    }

    printf("Матрица смежности:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", adj_matrix[i][j]);
        }
        printf("\n");
    }

    // Обход в глубину для матрицы смежности
    int* visited = (int*)calloc(n, sizeof(int));
    printf("\nОбход в глубину (матрица смежности):\n");
    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            dfs(adj_matrix, visited, i, n);
        }
    }

    // Генерация списков смежности
    int** adj_list = (int**)malloc(n * sizeof(int*));
    for (int i = 0; i < n; i++) {
        adj_list[i] = (int*)malloc((n + 1) * sizeof(int));
        adj_list[i][0] = 0; // Количество соседей
    }

    // Заполнение списков смежности (предполагается, что они уже сгенерированы)

    // Обход в глубину для списков смежности
    visited = (int*)calloc(n, sizeof(int));
    printf("\nОбход в глубину (списки смежности):\n");
    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            dfs_adj_list(adj_list, visited, i, n);
        }
    }

    // Освобождение памяти
    for (int i = 0; i < n; i++) {
        free(adj_matrix[i]);
        free(adj_list[i]);
    }
    free(adj_matrix);
    free(adj_list);
    free(visited);

    return 0;
}