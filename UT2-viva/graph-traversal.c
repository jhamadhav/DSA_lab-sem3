#include <stdio.h>
#include <stdlib.h>

int edges[1000][1000];
int nodes[1000];

void edgePrint(int n) {
    printf("\n\n  | ");
    for (int i = 0;i < n;++i) {
        printf("%d ", i);
    }
    printf("\n--|");
    for (int i = 0;i < n;++i) {
        printf("--");
    }
    for (int i = 0;i < n;i++) {
        printf("\n%d | ", i);
        for (int j = 0;j < n;++j) {
            printf("%d ", edges[i][j]);
        }
    }
    printf("\n");
}

int q[1000], s = 0, e = 0;
void pushQ(int n) {
    q[e++] = n;
}
int popQ() {
    return q[s++];
}
int isEmptyQ() {
    return ((s >= e) ? 1 : 0);
}
void bfsPrint(int n, int start) {
    pushQ(start);
    int count = 0;

    int visited[n];
    for (int i = 0;i < n;++i) {
        visited[i] = 0;
    }
    visited[start] = 1;

    while (isEmptyQ() != 1) {
        int node = popQ();
        printf("%d ", nodes[node]);

        for (int i = 0;i < n;i++) {
            if (edges[node][i] == 1 && visited[i] == 0) {
                pushQ(i);
                visited[i] = 1;
            }
        }
    }

}

int stack[1000], se = -1;
void pushS(int n) {
    stack[++se] = n;
}
int popS() {
    return stack[se--];
}
int topS() {
    return stack[se];
}
int isEmptyS() {
    return ((se < 0) ? 1 : 0);
}

void dfsPrint(int n, int start) {
    pushS(start);
    int count = 0;

    int visited[n];
    for (int i = 0;i < n;++i) {
        visited[i] = 0;
    }
    visited[start] = 1;
    printf("%d ", nodes[start]);

    while (isEmptyS() != 1) {
        int node = topS();

        int flag = 0;
        for (int i = 0;i < n;i++) {
            if (edges[node][i] == 1 && visited[i] == 0) {
                pushS(i);
                visited[i] = 1;
                printf("%d ", nodes[i]);
                flag = 1;
                break;
            }
        }
        if (flag == 0) {
            popS();
        }
    }

}

int main(void) {

    // #ifndef ONLINE_JUDGE
    //     freopen("input.txt", "r", stdin);
    // #endif

    printf("\n\n:::::Graph Traversal:::::\n\n");

    int n = 0;
    printf("Enter number of nodes: ");
    scanf("%d", &n);

    printf("\nEnter node values:\n");
    for (int i = 0;i < n;++i) {
        printf("Value of node %d: ", i);
        scanf("%d", &nodes[i]);
    }

    // put all edges as 0
    for (int i = 0;i < n;i++) {
        for (int j = 0;j < n;++j) {
            edges[i][j] = 0;
        }
    }

    int e = 0;
    printf("\nEnter number of edges: ");
    scanf("%d", &e);

    if (e < n - 1) {
        printf("\n\nERROR: Edges should be >= %d\n\n", n - 1);
        return 0;
    }

    printf("\nEnter edges in following format: from to \n(e.g.: 2 4)\n");
    for (int i = 0;i < e;i++) {
        int a, b;
        printf("Edge: ");
        scanf("%d", &a);
        scanf("%d", &b);
        edges[a][b] = 1;
        edges[b][a] = 1;
    }

    printf("\n\nEdge matrix: ");
    edgePrint(n);

    printf("\nBFS traversal: ");
    bfsPrint(n, 2);

    printf("\n\nDFS traversal: ");
    dfsPrint(n, 2);

    printf("\n\n");
    return 0;
}