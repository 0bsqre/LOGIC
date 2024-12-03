#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <stdio.h>
#include <locale.h>
#include<climits>
#include <queue>
std::queue <int> Q;
int** createG(int size) {
    int** G = NULL;
    G = (int**)malloc(size * sizeof(int*));
    for (int i = 0; i < size; i++) {
        G[i] = (int*)malloc(size * sizeof(int));
    }
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            G[i][j] = rand() % 2;
            if (i == j) {
                G[i][j] = 0;
            }
            G[j][i] = G[i][j];
        }
    }
    return G;
}

void printG(int** G, int size) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            printf("%d  ", G[i][j]);
        }
        printf("\n");
    }
    return;
}

void bfsd(int** G, int size, int s, int* dist) {
    Q.push(s);
    dist[s] = 0;
    while (!Q.empty()) {
        s = Q.front();
        Q.pop();
        for (int i = 0; i < size; i++) {
            if (G[s][i] == 1 && dist[i] > dist[s] + 1) {
                Q.push(i);
                dist[i] = dist[s] + 1;
            }
        }
    }
}
int main()
{
    int s;
    setlocale(LC_ALL, "Rus");
    int size = 5;
    int** G1 = createG(size);
    printf("Введите размер матрицы \n");
    scanf("%d", &size);
    printf("Матрица 1\n");
    printG(G1, size);
    printf("Введите стартовую вершину \n");
    scanf("%d", &s);
    int* dist = NULL;
    dist = (int*)malloc(size * sizeof(int*));
    for (int i = 0; i < size; i++) {
        dist[i] = INT_MAX;
    }
    bfsd(G1, size, s, dist);
    for (int i = 0; i < size; i++) {
        printf("расстояние от %d до %d вершины = %d \n", s, i, dist[i]);
    }

    return 0;
}