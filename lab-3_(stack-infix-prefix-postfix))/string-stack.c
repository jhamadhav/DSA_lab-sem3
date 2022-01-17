#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void error(char e[]) {
    printf("\nERROR: %s!!\n", e);
}

typedef struct
{
    int top;
    int maxSize;
    char** arr;

} StringStack;

StringStack*
stringStackInitialize()
{
    StringStack* sp;
    sp = (StringStack*)malloc(sizeof(StringStack));
    sp->top = -1;
    sp->maxSize = 1000;
    sp->arr = (char**)calloc(sp->maxSize, sizeof(char*));
    return sp;
}

void
spush(StringStack* sp, char* c)
{
    if (sp->top >= sp->maxSize - 1)
    {
        error("StackOverflow, Stack reformed");
        sp->maxSize *= 2;
        sp->arr = (char**)realloc(sp->arr, sp->maxSize * sizeof(char*));
    }
    sp->arr[++sp->top] = c;
}

char* speek(StringStack* sp)
{
    if (sp->top <= -1)
    {
        error("StackUnderflow, can't peek any element");
        return NULL;
    }
    return sp->arr[sp->top];
}

char*
spop(StringStack* sp)
{
    if (sp->top <= -1)
    {
        error("StackUnderflow");
        return 0;
    }
    return sp->arr[sp->top--];
}

int isSSEmpty(StringStack* sp) {
    return sp->top == -1;
}

char* makeString(int n) {
    char* c;
    c = (char*)calloc(n, sizeof(char));
    return c;
}

void addChar(char* c, char s) {
    int i = strlen(c);
    c[i] = s;
    c[++i] = '\0';
}

void addToString(char* a, char* b) {
    int i = strlen(a);

    int j = 0;
    while (b[j] != '\0') {
        a[i] = b[j];
        ++i;
        ++j;
    }
    a[i] = '\0';
}

void printStringStack(StringStack* sp) {
    if (sp->top < 0) {
        return;
    }
    printf("[ ");
    for (int i = 0;i <= sp->top;i++) {
        printf("%s ", (sp->arr)[i]);
    }
    printf("]");
}

// int
// main()
// {
//     StringStack* sp;
//     sp = stringStackInitialize();

//     char* c;
//     c = makeString(10);
//     c[0] = 'h';
//     c[1] = 'i';
//     c[2] = '\0';
//     addChar(c, 'i');
//     char* a;
//     a = makeString(10);
//     a = "hola";
//     addToString(c, a);
//     printf("%s", c);

//     spush(sp, c);
//     printf("\npeek: %s", spop(sp));

//     return 0;
// }

