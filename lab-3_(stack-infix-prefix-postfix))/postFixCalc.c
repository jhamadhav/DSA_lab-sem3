#include <stdio.h>
#include <string.h>
#include "operatorUtil.c"
#include "stack.c"

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

    char str[] = "02-3+";

    printf("\nPostfix expression: %s", str);

    printf("\nEvaluation is: %f", calcPostFix(str));
    return 0;
}