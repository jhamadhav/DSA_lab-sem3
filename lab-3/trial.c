#include <stdio.h>
#include <stdlib.h>

void printArray(int arr[], int n) {
    printf("[ ");
    for (int i = 0;i < n;i++) {
        printf("%d ", arr[i]);
    }
    printf("]\n");
}

int main(void) {
    int* a;
    a = (int*)calloc(3, sizeof(int));
    a[0] = 2;
    printArray(a, 3);
    a = (int*)realloc(a, 4 * sizeof(int));
    a[3] = 2;
    printArray(a, 4);
    return 0;
}