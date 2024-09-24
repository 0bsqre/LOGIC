#include <locale.h>
#include <stdio.h>

int main() {
    setlocale(LC_ALL, "Rus");
    int arr[6] = { 5, 3, 8, 1, -9, 2 }; // пример массива

    int maxEl = arr[0];
    int minEl = arr[0];

    for (int i = 1; i < 6; i++) {
        if (arr[i] > maxEl) {
            maxEl = arr[i];
        }
        if (arr[i] < minEl) {
            minEl = arr[i];
        }
    }

    int difference = maxEl - minEl;

    printf("Максимальный элемент: %d\n", maxEl);
    printf("Минимальный элемент: %d\n", minEl);
    printf("Разница: %d\n", difference);

    return 0;
}
