#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <locale.h>
#define MAX_SIZE 100 

int findMaxInRange(const int* arr, int size, int K, int M);

int main(void) {
    setlocale(LC_CTYPE, "RUS");
    int arr[MAX_SIZE]; 
    int n;
    
    printf("Введите размер массива (от 1 до %d): ", MAX_SIZE);
    scanf("%d", &n);

    if (n <= 0 || n > MAX_SIZE) {
        printf("Ошибка: недопустимый размер массива.\n");
        return 1;
    }

    printf("Введите %d элементов массива через пробел:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("\nВведенный массив:\n");
    for (int i = 0; i < n; i++) {
        printf("[%d] -> %d\n", i, arr[i]);
    }

    int K, M;
    printf("\nВведите индекс K (от 0 до %d): ", n - 1);
    scanf("%d", &K);

    printf("Введите индекс M (от 0 до %d): ", n - 1);
    scanf("%d", &M);

    if (K < 0 || K >= n || M < 0 || M >= n) {
        printf("Ошибка: индексы выходят за границы массива [0, %d]!\n", n - 1);
        return 1;
    }

    int result = findMaxInRange(arr, n, K, M);
    printf("\nМаксимальное значение в интервале [%d, %d] = %d\n", K, M, result);

    return 0;
}

int findMaxInRange(const int* arr, int size, int K, int M) {
    if (K > M) {
        int temp = K;
        K = M;
        M = temp;
    }

    int maxVal = arr[K];
    for (int i = K + 1; i <= M; i++) {
        if (arr[i] > maxVal) {
            maxVal = arr[i];
        }
    }
    return maxVal;
}
