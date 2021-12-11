#include <stdio.h>
#include <stdlib.h>

void error(char e[]) {
    printf("\nERROR: %s!!\n", e);
}

typedef struct
{
    int top;
    int maxSize;
    double* arr;
} Stack;

Stack*
stackInitialize()
{
    Stack* sp;
    sp = (Stack*)malloc(sizeof(Stack));
    sp->top = -1;
    sp->maxSize = 1000;
    sp->arr = (double*)calloc(sp->maxSize, sizeof(double));
    return sp;
}

void
push(Stack* sp, double c)
{
    if (sp->top >= sp->maxSize - 1)
    {
        error("StackOverflow, Stack reformed");
        sp->maxSize *= 2;
        sp->arr = (double*)realloc(sp->arr, sp->maxSize * sizeof(double));
    }
    sp->arr[++sp->top] = c;
}

double
peek(Stack* sp)
{
    if (sp->top <= -1)
    {
        error("StackUnderflow, can't peek any element");
        return '0';
    }
    return sp->arr[sp->top];
}

double
pop(Stack* sp)
{
    if (sp->top <= -1)
    {
        error("StackUnderflow");
        return '0';
    }
    return sp->arr[sp->top--];
}

// int
// main()
// {
//     Stack* sp;
//     sp = stackInitialize();

//     peek(sp);
//     pop(sp);

//     for (int i = 0; i < 10; i++)
//     {
//         push(sp, i);
//         printf("peek: %f\n", peek(sp));
//     }

//     printf("\nPOP 4 elements\n");
//     for (int i = 0; i < 4; i++)
//     {
//         pop(sp);
//         printf("peek: %f\n", peek(sp));
//     }

//     return 0;
// }

