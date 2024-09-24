#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <locale.h>

int main() {
    setlocale(LC_ALL, "Russian");

    //Количество строк и столбцов
    int rows, cols;
    printf("Введите количество строк: ");
    scanf("%d", &rows);
    printf("Введите количество столбцов: ");
    scanf("%d", &cols);

    //Выделение памяти
    int** arr = (int**)malloc(rows * sizeof(int*));
    for (int i = 0; i < rows; i++) {
        arr[i] = (int*)malloc(cols * sizeof(int));
    }

    //Заполнение массива
    srand(time(NULL));
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            arr[i][j] = rand() % 81 - 30; 
        }
    }
    //Вычисление суммы элементов выше главной диагонали
    int sum = 0;
    for (int i = 0; i < rows; i++) {
        for (int j = i + 1; j < cols; j++) {
            sum += arr[i][j];
        }
    }

    //Вывод массива и суммы
    printf("Двумерный массив:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%3d ", arr[i][j]);
        }
        printf("\n");
    }
    printf("Сумма элементов выше главной диагонали: %d\n", sum);
    //Освобождение памяти
    for (int i = 0; i < rows; i++) {
        free(arr[i]);
    }
    free(arr);

    return 0;
}