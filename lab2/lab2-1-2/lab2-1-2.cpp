#include <locale.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void)
{
    setlocale(LC_ALL, "RUS");
    setvbuf(stdin, NULL, _IONBF, 0);
    setvbuf(stdout, NULL, _IONBF, 0);

    int i, j, r, n;
    int** a, **b, **c;
    int elem_c;

    // Задаем размер матриц
    for (n = 100; n <= 10000;) {
        // Выделяем память под матрицы
        a = (int**)malloc(n * sizeof(int*));
        b = (int**)malloc(n * sizeof(int*));
        c = (int**)malloc(n * sizeof(int*));
        for (i = 0; i < n; i++) {
            a[i] = (int*)malloc(n * sizeof(int));
            b[i] = (int*)malloc(n * sizeof(int));
            c[i] = (int*)malloc(n * sizeof(int));
        }

        // Заполняем матрицы случайными числами
        srand(time(NULL));
        for (i = 0; i < n; i++) {
            for (j = 0; j < n; j++) {
                a[i][j] = rand() % 100 + 1;
                b[i][j] = rand() % 100 + 1;
            }
        }

        // Измеряем время выполнения перемножения матриц
        clock_t start, end;
        start = clock();
        for (i = 0; i < n; i++) {
            for (j = 0; j < n; j++) {
                elem_c = 0;
                for (r = 0; r < n; r++) {
                    elem_c += a[i][r] * b[r][j];
                }
                c[i][j] = elem_c;
            }
        }
        end = clock();

        // Вычисляем время выполнения в секундах
        double time_taken = (double)(end - start) / CLOCKS_PER_SEC;
        printf("Время выполнения для матриц размера %dx%d: %f секунд\n", n, n, time_taken);

        // Освобождаем память
        for (i = 0; i < n; i++) {
            free(a[i]);
            free(b[i]);
            free(c[i]);
        }
        free(a);
        free(b);
        free(c);
        break;
    }
    return 0;
}