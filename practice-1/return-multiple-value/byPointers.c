#include <stdio.h>

void initialize(int* a, int* b, char* c)
{
    *a = 10;
    *b = 20;
    *c = 'A';
}

int main(void)
{
    int a, b;
    char c;

    initialize(&a, &b, &c);
    printf("a = %d, b = %d, c = %c", a, b, c);

    return 0;
}