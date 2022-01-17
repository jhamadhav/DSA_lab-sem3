#include <stdio.h>
#include <stdlib.h>

void printArray(int arr[], int n) {
    printf("[ ");
    for (int i = 0;i < n;i++) {
        printf("%d ", arr[i]);
    }
    printf("]\n");
}

void minMax(int arr[], int* n, int* max, int* min) {
    for (int i = 0;i < *n;i++) {
        if (arr[i] >= *max) {
            *max = arr[i];
        }
        if (arr[i] <= *min) {
            *min = arr[i];
        }
    }
}

int main() {
    int n = 2;
    printf("\nEnter number of elements: ");
    scanf("%d", &n);

    int* arr;
    arr = (int*)calloc(n, sizeof(int));
    printf("Enter array elements: ");
    for (int i = 0;i < n;i++) {
        scanf("%d", &arr[i]);
    }

    int min = INT_MAX, max = -INT_MAX;
    minMax(arr, &n, &max, &min);

    printf("\nMax element: %d", max);
    printf("\nMin element: %d", min);
    printf("\n\n");
    free(arr);
    return 0;
}