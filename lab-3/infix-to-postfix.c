#include <stdio.h>
#include <string.h>
#include "operatorUtil.c"
#include "stack-char.c"

char* infixToPostfix(char s[]) {
    CharStack* arr;
    arr = stackInitialize();

    char* res = (char*)malloc(1000 * sizeof(int));;
    int k = 0;

    for (int i = 0;i < strlen(s);i++) {

        if (s[i] == ' ') {
            continue;
        }

        if (s[i] >= '0' && s[i] <= '9') {
            res[k++] = s[i];
            continue;
        }

        // in case we have -2 + 3 or +2 +3 or -(3)
        if ((i - 1 < 0 || s[i - 1] == '(') && (s[i] == '+' || s[i] == '-')) {
            res[k++] = '0';

        }

        if (isOperator(s[i]) == 1) {
            // condition is if current operator order is <= previous operator then we pop else we push
            int prev = -1;
            if (isEmpty(arr) == 0 && isOperator((char)peek(arr))) {
                prev = operatorOrder((char)peek(arr));
            }

            int curr = operatorOrder(s[i]);

            if (curr <= prev && prev != -1) {

                while (curr <= prev || isEmpty(arr) != 1 || (char)peek(arr) != '(') {
                    char c = (char)pop(arr);
                    res[k++] = c;
                    if (isEmpty(arr) == 0) {
                        prev = operatorOrder((char)peek(arr));
                    }
                    else {
                        break;
                    }
                }
            }
            push(arr, (char)s[i]);
        }
        else if ((char)s[i] == '(') {
            push(arr, '(');
        }
        else if ((char)s[i] == ')') {
            while ((char)peek(arr) != '(') {
                char c = (char)pop(arr);
                res[k++] = c;
            }
            pop(arr);
        }
        else {
            error("Invalid character");
            break;
        }
    }
    while (isEmpty(arr) != 1) {
        res[k++] = (char)pop(arr);
    }
    res[k++] = '\0';
    return res;
}

int main() {
    char str[] = "0-1*(-2)";

    printf("\nInfix expression is: %s", str);

    char* res = infixToPostfix(str);
    printf("\nConversion to Postfix is: %s", res);

}