#include <stdio.h>
#include <math.h>

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
        printf("\nERROR: Invalid operator!!!\n");
        return 0;
    }
}

int operatorOrder(char c) {
    switch (c)
    {
    case '+':
    case '-':
        return 0;
    case '/':
    case '*':
        return 1;
    case '^':
        return 2;

    default:
        printf("\nERROR: Invalid operator here!!!\n", c);
        return -1;
    }
}

// int main() {
//     printf("\nIs + operator: %d", isOperator('+'));
//     printf("\nIs a operator: %d", isOperator('a'));
//     printf("\nSum of 3 + 4 : %f", getAns(3, 4, '+'));
//     printf("\nOrder of + : %d", operatorOrder('+'));
//     printf("\nOrder of - : %d", operatorOrder('-'));
//     printf("\nOrder of * : %d", operatorOrder('*'));
//     printf("\nOrder of / : %d", operatorOrder('/'));
// }