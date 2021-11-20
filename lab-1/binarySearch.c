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

void binarySearch(int arr[], int* n, int* num, int* index) {
    int l = 0, r = *n - 1, m;
    int count = 0;
    while (l <= r && count < 100) {
        m = (l + r) / 2;
        if (arr[m] == *num) {
            *index = m;
            break;
        }
        else if (arr[m] < *num) {
            l = m + 1;
        }
        else {
            r = m;
        }
        count++;
    }
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

    int num;
    printf("\nEnter number to search: ");
    scanf("%d", &num);

    int index = -1;
    binarySearch(arr, &n, &num, &index);

    if (index == -1) {
        printf("Number not found!!!");
    }
    else {
        printf("Number found at index: %d", index);
    }
    printf("\n\n");
    return 0;
}