#include <stdio.h>
#include <stdlib.h>
#include "operatorUtil.c"
#include "string-stack.c"

char* postFixToPreFix(char* s) {
    StringStack* sp;
    sp = stringStackInitialize();

    for (int i = 0;i < strlen(s);i++) {
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

        ss = spop(sp);
        fs = spop(sp);

        char* ans;
        ans = makeString(1000);
        ans[0] = s[i];
        addToString(ans, fs);
        addToString(ans, ss);

        spush(sp, ans);

        printStringStack(sp);
        printf("\n");
    }

    return spop(sp);
}

int main() {
    char* inp;
    inp = makeString(1000);
    inp = "ABC/-AK/L-+";
    printf("\nPostfix is: %s", inp);
    printf("\n\nRead\tStack\n");
    printf("\nPrefix is: %s\n\n", postFixToPreFix(inp));
    return 0;
}