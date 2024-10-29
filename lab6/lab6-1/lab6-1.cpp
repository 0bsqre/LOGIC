#include <stdio.h>
#include <malloc.h>
#include <conio.h>
#include <random>
#include <Windows.h>
#include <time.h>

int createG(int size) {
    int G = NULL;
    G = (int**)malloc(size * sizeof(int*));
    for (int i = 0; i < size; i++)
        G[i] = (int*)malloc(size * sizeof(int));
    for (int i = 0; i < size; i++)
        for (int j = i; j < size; j++) {
            G[i][j] = rand() % 2;
            if (i == j)
                G[i][j] = 0;
            G[j][i] = G[i][j];
        }
    return G;
}

void printG(int** G, int size) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++)
            printf("%d ", G[i][j]);
        printf("\n");
    }
}

int main(void) {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    srand(time(NULL));

    int nG1 = 0, nG2 = 0;
    printf("Количество вершин графа G1: ");
    scanf_s("%d", &nG1);
    printf("Количество вершин графа G2: ");
    scanf_s("%d", &nG2);
    int** G1 = createG(nG1);
    int** G2 = createG(nG2);
    printf("Граф G1:\n");
    printG(G1, nG1);
    printf("Граф G2:\n");
    printG(G2, nG2);

    return 0;
}