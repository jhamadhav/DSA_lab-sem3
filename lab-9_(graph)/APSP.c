#include <stdio.h>
#include <stdlib.h>
#define MAXNUM 20000

int edges[1000][1000];

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
            if (edges[i][j] == MAXNUM) {
                printf("0 ");
                continue;
            }
            printf("%d ", edges[i][j]);
        }
    }
    printf("\n");
}

int min(int a, int b) {
    return (a < b) ? a : b;
}

void apsp(int n) {

    for (int i = 0;i < n;++i) {
        for (int j = 0;j < n;++j) {
            for (int k = 0;k < n;++k) {
                if (j == i || k == i || j == k) continue;
                edges[j][k] = min(edges[j][k], edges[j][i] + edges[i][k]);
            }
        }
    }
}

int main(void) {

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif

    printf("\n\n:::::All Pair Shortest Path:::::\n\n");

    int n = 0;
    printf("Enter number of nodes: ");
    scanf("%d", &n);

    // put all edges as 0
    for (int i = 0;i < n;i++) {
        for (int j = 0;j < n;++j) {
            edges[i][j] = MAXNUM;
        }
    }

    int e = 0;
    printf("\nEnter number of edges: ");
    scanf("%d", &e);

    if (e < n - 1) {
        printf("\n\nERROR: Edges should be >= %d\n\n", n - 1);
        return 0;
    }

    printf("\nEnter edges in following format: from to weight \n(e.g.: 2 4 3)\n");
    for (int i = 0;i < e;i++) {
        int a, b, c;
        printf("Edge: ");
        scanf("%d", &a);
        scanf("%d", &b);
        scanf("%d", &c);
        edges[a][b] = c;
        edges[b][a] = c;
    }

    printf("\n\nInitial edge matrix:");
    edgePrint(n);
    apsp(n);

    printf("\n\nAfter calculating all shortest paths:");
    edgePrint(n);

    printf("\n\n");
    return 0;
}