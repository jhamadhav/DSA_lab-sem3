#include <stdio.h>

struct Tuple {
    int a, b;
    char c;
};

struct Tuple initialize()
{
    struct Tuple tuple = { 10, 20, 'A' };

    return tuple;
}

int main(void)
{
    int a, b;
    char c;

    struct Tuple tuple = initialize();

    a = tuple.a;
    b = tuple.b;
    c = tuple.c;

    printf("a = %d, b = %d, c = %c", a, b, c);

    return 0;
}