#include <stdio.h>

void swapByReference(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
    printf("\nSwapped in function:\na: %d; b: %d", *a, *b);
}

int main()
{
    int a = 10, b = 15;

    printf("\n\nCall by Reference\n");
    printf("Before swap:\na: %d; b: %d", a, b);
    swapByReference(&a, &b);
    printf("\nAfter swap:\na: %d; b: %d", a, b);

    return 0;
}
