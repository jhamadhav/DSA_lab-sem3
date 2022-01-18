#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct TreeNode {
    int val;
    struct TreeNode* left;
    struct TreeNode* right;
};

void addNode(struct TreeNode** root, int num) {
    struct TreeNode* node;
    node = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    node->val = num;
    node->left = NULL;
    node->right = NULL;

    if (*root == NULL) {
        *root = node;
        return;
    }

    struct TreeNode* temp = *root;
    while (temp != NULL) {
        if (temp->val == num) {
            break;
        }if (temp->val < num) {
            if (temp->right != NULL) {
                temp = temp->right;
            }
            else {
                temp->right = node;
                break;
            }
        }
        else {
            if (temp->left != NULL) {
                temp = temp->left;
            }
            else {
                temp->left = node;
                break;
            }
        }
    }
}

int max(int a, int b) {
    return (a > b) ? a : b;
}

int height(struct TreeNode* node, int level) {
    if (node == NULL) return level;
    return max(height(node->left, level + 1), height(node->right, level + 1));
}

void print2dArray(int m, int n, int arr[m][n]) {
    printf("\n");
    for (int i = 0;i < m;i++) {
        printf("\t");
        for (int j = 0;j < n;j++) {
            if (arr[i][j] == 0) {
                printf("  ");
                continue;
            }
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

void preOrderPrint(struct TreeNode* node, int start, int end, int level, int m, int n, int arr[m][n]) {
    if (node == NULL) return;

    int mid = start + (end - start) / 2;
    arr[level][mid] = node->val;

    preOrderPrint(node->left, start, mid, level + 1, m, n, arr);
    preOrderPrint(node->right, mid + 1, end, level + 1, m, n, arr);
}

void printTree(struct TreeNode* root) {
    int h = height(root, 0);
    int n = pow(2, h) - 1;
    printf("Height: %d\n", h);
    printf("nodes: %d\n", n);

    int arr[h][n];
    for (int i = 0;i < h;i++) {
        for (int j = 0;j < n;j++) {
            arr[i][j] = 0;
        }
    }
    preOrderPrint(root, 0, n, 0, h, n, arr);

    print2dArray(h, n, arr);
}

int main() {
    struct TreeNode** root = (struct TreeNode**)malloc(sizeof(struct TreeNode*));
    *root = NULL;

    addNode(root, 50);
    addNode(root, 2);
    addNode(root, 52);
    addNode(root, 1);
    addNode(root, 3);
    addNode(root, 55);

    printTree(*root);
    return 0;
}