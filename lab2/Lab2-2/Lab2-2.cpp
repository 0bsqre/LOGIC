#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h> 
#include <stdlib.h> 
#include <time.h> 
#include <Windows.h> 
#include <ctime>

int** s = (int**)malloc(size * sizeof(int*));
for (i = 0; i < size; i++) {
    s[i] = (int*)malloc(size * sizeof(int));
}

int randomArray[size], randomArray2[size], randomArray3[size];
int increasingArray[size], increasingArray2[size], increasingArray3[size];
int decreasingArray[size], decreasingArray2[size], decreasingArray3[size];
int halfIncHalfDecArray[size], halfIncHalfDecArray2[size], halfIncHalfDecArray3[size];

void copyArray(int* source, int* destination, int* destination2, int size) {
    for (int i = 0; i < size; i++) {
        destination[i] = source[i];
        destination2[i] = source[i];
    }
}

void shell(int* items, int count) {
    int i, j, gap, k;
    int x, a[5];

    a[0] = 9; a[1] = 5; a[2] = 3; a[3] = 2; a[4] = 1;

    for (k = 0; k < 5; k++) {
        gap = a[k];
        for (i = gap; i < count; ++i) {
            x = items[i];
            for (j = i - gap; (x < items[j]) && (j >= 0); j = j - gap)
                items[j + gap] = items[j];
            items[j + gap] = x;
        }
    }
}

int compare(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}

void qs(int* items, int left, int right) {
    int i, j;
    int x, y;

    i = left; j = right;
    x = items[(left + right) / 2];

    do {
        while ((items[i] < x) && (i < right)) i++;
        while ((x < items[j]) && (j > left)) j--;

        if (i <= j) {
            y = items[i];
            items[i] = items[j];
            items[j] = y;
            i++; j--;
        }
    } while (i <= j);

    if (left < j) qs(items, left, j);
    if (i < right) qs(items, i, right);
}

int main() {

    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    srand(time(NULL));

    double timeRandomShell, timeRandomQuick, timeRandomQSort, timeDescendingShell, timeDescendingQuick, timeDescendingQSort, timeAscendingShell, timeAscendingQuick, timeAscendingQSort, timeHalfShell, timeHalfQuick, timeHalfQSort;

    // Заполнение массивов
    for (int i = 0; i < size; i++) {
        randomArray[i] = rand() % 1000; // случайные числа от 0 до 999
        increasingArray[i] = i; // возрастающий
        decreasingArray[i] = size - i; // убывающий
        halfIncHalfDecArray[i] = (i < size / 2) ? i : size - i; // половина возрастающий, половина убывающий
    }

    copyArray(randomArray, randomArray2, randomArray3, size);
    copyArray(&increasingArray[size], &increasingArray2[size], &increasingArray3[size], size);
    copyArray(&decreasingArray[size], &decreasingArray2[size], &decreasingArray3[size], size);
    copyArray(&halfIncHalfDecArray[size], &halfIncHalfDecArray2[size], &halfIncHalfDecArray3[size], size);

    // Сортировка и замер времени для случайного массива
    clock_t start = clock();
    shell(randomArray, size);
    clock_t end = clock();
    timeRandomShell = ((double)(end - start) / CLOCKS_PER_SEC);

    start = clock();
    qs(randomArray2, 0, size - 1);
    end = clock();
    timeRandomQuick = ((double)(end - start) / CLOCKS_PER_SEC);

    start = clock();
    qsort(randomArray3, size, sizeof(int), compare);
    end = clock();
    timeRandomQSort = ((double)(end - start) / CLOCKS_PER_SEC);

    printf("Random Array:\n");
    printf("Shell: %lf seconds\n", timeRandomShell);
    printf("Quick Sort: %lf seconds\n", timeRandomQuick);
    printf("QSort: %lf seconds\n\n", timeRandomQSort);

    // Сортировка и замер времени для убывающего массива
    start = clock();
    shell(decreasingArray, size);
    end = clock();
    timeDescendingShell = ((double)(end - start) / CLOCKS_PER_SEC);

    start = clock();
    qs(decreasingArray2, 0, size - 1);
    end = clock();
    timeDescendingQuick = ((double)(end - start) / CLOCKS_PER_SEC);

    start = clock();
    qsort(decreasingArray3, size, sizeof(int), compare);
    end = clock();
    timeDescendingQSort = ((double)(end - start) / CLOCKS_PER_SEC);

    printf("Descending Array:\n");
    printf("Shell: %lf seconds\n", timeDescendingShell);
    printf("Quick Sort: %lf seconds\n", timeDescendingQuick);
    printf("QSort: %lf seconds\n\n", timeDescendingQSort);

    // Сортировка и замер времени для возрастающего массива
    start = clock();
    shell(increasingArray, size);
    end = clock();
    timeAscendingShell = ((double)(end - start) / CLOCKS_PER_SEC);

    start = clock();
    qs(increasingArray2, 0, size - 1);
    end = clock();
    timeAscendingQuick = ((double)(end - start) / CLOCKS_PER_SEC);

    start = clock();
    qsort(increasingArray3, size, sizeof(int), compare);
    end = clock();
    timeAscendingQSort = ((double)(end - start) / CLOCKS_PER_SEC);

    printf("Ascending Array:\n");
    printf("Shell: %lf seconds\n", timeAscendingShell);
    printf("Quick Sort: %lf seconds\n", timeAscendingQuick);
    printf("QSort: %lf seconds\n\n", timeAscendingQSort);

    // Сортировка и замер времени для половинчатого массива
    start = clock();
    shell(halfIncHalfDecArray, size);
    end = clock();
    timeHalfShell = ((double)(end - start) / CLOCKS_PER_SEC);

    start = clock();
    qs(halfIncHalfDecArray2, 0, size - 1);
    end = clock();
    timeHalfQuick = ((double)(end - start) / CLOCKS_PER_SEC);

    start = clock();
    qsort(halfIncHalfDecArray3, size, sizeof(int), compare);
    end = clock();
    timeHalfQSort = ((double)(end - start) / CLOCKS_PER_SEC);

    printf("Half-and-Half Array:\n");
    printf("Shell: %lf seconds\n", timeHalfShell);
    printf("Quick Sort: %lf seconds\n", timeHalfQuick);
    printf("QSort: %lf seconds\n\n", timeHalfQSort);
    for (int i = 0; i < size; i++) {
        free s[i];
     }
    free(s);
    return 0;
}
