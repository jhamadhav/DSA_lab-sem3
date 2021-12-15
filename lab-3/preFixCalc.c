#include <stdio.h>
#include <string.h>
#include "operatorUtil.c"
#include "stack.c"

double calcPreFix(char s[]) {
    Stack* arr;
    arr = stackInitialize();

    for (int i = strlen(s) - 1;i >= 0;i--) {

        if (isOperator(s[i]) == 1) {
            double ft = pop(arr);
            double st = pop(arr);

            push(arr, getAns(ft, st, s[i]));
        }
        else {
            push(arr, s[i] - '0');
        }
    }
    return peek(arr);
}

int main() {

    char str[] = "+2*34";

    printf("\nPrefix expression: %s", str);

    printf("\nEvaluation is: %f \n\n", calcPreFix(str));
    return 0;
}