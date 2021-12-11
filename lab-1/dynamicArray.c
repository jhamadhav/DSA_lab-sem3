#include <stdio.h>
#include <stdlib.h>

void printArray(int arr[], int n) {
    printf("[ ");
    for (int i = 0;i < n;i++) {
        printf("%d ", arr[i]);
    }
    printf("]\n");
}

void main() {
    int n = 5;
    int* arr;
    arr = calloc(n, sizeof(int));
    for (int i = 0;i < n;i++) {
        arr[i] = i + 1;
    }
    printf("\nArray size of %d: ", n);
    printArray(arr, n);

    printf("Increasing size of by by double: ");
    arr = (int*)realloc(arr, sizeof(int) * (2 * n));
    for (int i = n;i < 2 * n;i++) {
        arr[i] = i + 1;
    }
    printArray(arr, 2 * n);
    printf("\n");

    free(arr);
}