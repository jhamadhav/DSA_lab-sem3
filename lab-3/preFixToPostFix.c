#include <stdio.h>
#include <stdlib.h>
#include "operatorUtil.c"
#include "string-stack.c"

char* PreFixTopostFix(char* s) {
    StringStack* sp;
    sp = stringStackInitialize();

    for (int i = strlen(s) - 1;i >= 0;i--) {
        printf("%c\t", s[i]);
        if (isOperator(s[i]) == 0) {
            char* temp;
            temp = makeString(4);
            temp[0] = s[i];
            spush(sp, temp);

            printStringStack(sp);
            printf("\n");
            continue;
        }

        char* fs;
        fs = makeString(1000);
        char* ss;
        ss = makeString(1000);

        fs = spop(sp);
        ss = spop(sp);

        addToString(fs, ss);
        addChar(fs, s[i]);

        spush(sp, fs);
        printStringStack(sp);
        printf("\n");
    }

    return spop(sp);
}

int main() {
    char* inp;
    inp = makeString(1000);
    inp = "+-A/BC-/AKL";
    printf("\nPostfix is: %s", inp);
    printf("\n\nRead\tStack\n");
    printf("\nPrefix is: %s\n\n", PreFixTopostFix(inp));
    return 0;
}