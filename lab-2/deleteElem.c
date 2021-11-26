#include <stdio.h>
#include <stdlib.h>

void printArray(int arr[], int n) {
    printf("[ ");
    for (int i = 0;i < n;i++) {
        printf("%d ", arr[i]);
    }
    printf("]\n");
}

void linearSearch(int arr[], int* n, int* num, int* index) {
    for (int i = 0;i < *n;i++) {
        if (arr[i] == *num) {
            *index = i;
            break;
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

    int num;
    printf("Enter number to search: ");
    scanf("%d", &num);

    int index = -1;
    linearSearch(arr, &n, &num, &index);

    if (index == -1) {
        printf("Number not found!!!");
    }
    else {
        printf("Number found at index: %d", index);
        for (int i = index;i < n;i++) {
            arr[i] = arr[i + 1];
        }
        n--;
        printf("\nElement deleted: ");
        printArray(arr, n);
    }
    printf("\n\n");
    free(arr);
    return 0;
}