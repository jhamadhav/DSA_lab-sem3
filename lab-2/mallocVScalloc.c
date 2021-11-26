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

    int* p;
    p = (int*)malloc(3 * sizeof(int));
    p[0] = 1;p[1] = 2;
    printArray(p, 3);

    p = (int*)calloc(3, sizeof(int));
    p[0] = 1;p[1] = 2;
    printArray(p, 3);
}

// calloc initializes with value 0 but malloc doesn't