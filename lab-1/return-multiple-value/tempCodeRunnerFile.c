#include <stdio.h>
#include <stdlib.h>

int* initialize()
{
    int* temp = (int*)malloc(sizeof(int) * 3);

    *temp = 10;
    *(temp + 1) = 20;
    *(temp + 2) = 30;

    return temp;
}

int main(void)
{
    int a, b, c;

    int* arr = initialize();

    a = arr[0];
    b = arr[1];
    c = arr[2];

    printf("a = %d, b = %d, c = %d", a, b, c);

    return 0;
}