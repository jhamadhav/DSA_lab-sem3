#include <stdio.h>

void printArray(int arr[], int n) {
    printf("[ ");
    for (int i = 0;i < n;i++) {
        printf("%d ", arr[i]);
    }
    printf("]");
}

int* bubbleSort(int arr[], int n) {
    for (int i = 0;i < n;i++) {
        for (int j = 0;j < n;j++) {
            if (arr[i] < arr[j]) {
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
    return arr;
}

int main() {
    int n = 2;
    printf("\nEnter number of elements: ");
    scanf("%d", &n);

    int* arr;
    printf("Enter array elements: ");
    for (int i = 0;i < n;i++) {
        scanf("%d", &arr[i]);
    }

    printf("After sorting: ");
    arr = bubbleSort(arr, n);
    printArray(arr, n);
    printf("\n\n");
    return 0;
}