#include <stdio.h>

void printArray(int arr[], int n) {
    printf("[ ");
    for (int i = 0;i < n;i++) {
        printf("%d ", arr[i]);
    }
    printf("]");
}

int main() {
    int n = 2;
    printf("Enter number of elements: ");
    scanf("%d", &n);

    int arr[n];
    printf("Enter array elements: ");
    for (int i = 0;i < n;i++) {
        scanf("%d", &arr[i]);
    }

    int num;
    printf("Enter number to search: ");
    scanf("%d", &num);
    int index = -1;
    for (int i = 0;i < n;i++) {
        if (arr[i] == num) {
            index = i;
            break;
        }
    }

    if (index == -1) {
        printf("Number not found!!!");
    }
    else {
        printf("Number found at index: %d", index);
    }
    return 0;
}