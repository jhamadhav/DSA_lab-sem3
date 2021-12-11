#include <stdio.h>
#include <string.h>
#include <math.h>
#include "stack.c"

int isOperator(char c) {
    switch (c)
    {
    case '+':
    case '-':
    case '/':
    case '*':
    case '^':
        return 1;

    default:
        return 0;
    }
}

double getAns(double ft, double st, char c) {
    switch (c)
    {
    case '+':
        return ft + st;
    case '-':
        return ft - st;
    case '/':
        return ft / st;
    case '*':
        return ft * st;
    case '^':
        return pow(ft, st);

    default:
        error("Invalid operator");
        return 0;
    }
}

double calcPostFix(char s[]) {
    Stack* arr;
    arr = stackInitialize();

    for (int i = 0;i < strlen(s);i++) {

        if (isOperator(s[i]) == 1) {
            double st = pop(arr);
            double ft = pop(arr);

            push(arr, getAns(ft, st, s[i]));
        }
        else {
            push(arr, s[i] - '0');
        }
    }
    return peek(arr);
}

int main() {

    char str[1000];

    printf("\nEnter postfix expression: ");
    scanf("%s", str);

    printf("evaluation is: %f", calcPostFix(str));
    return 0;
}