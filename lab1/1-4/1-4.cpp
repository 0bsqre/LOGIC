#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <malloc.h> 
#include <stdlib.h>
#include <time.h>
int main(void)
{
    int  sum, Arr[3][5]{};
    srand(time(NULL));
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 5; j++)
            Arr[i][j] = rand() % 100;
    /**************вывод на экран массива*/
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 5; j++)
            printf("%3d ", Arr[i][j]);
        printf("\n");
    }
    printf("\n");
    /**************вывод суммы столбцов*/
    for (int k = 0; k < 5; k++)
    {
        sum = 0;
        for (int i = 0; i < 3; i++)
            for (int j = k; j < 5; j += 5)
                sum += Arr[i][j];
        printf("Sum %d : %d\n", k + 1, sum);
    }
    return 0;
}
