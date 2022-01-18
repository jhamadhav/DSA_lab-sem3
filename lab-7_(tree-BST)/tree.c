#include <stdio.h>
#include <stdlib.h>

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

void preOrder(struct TreeNode* node) {
    if (node == NULL) return;
    printf("%d ", node->val);
    preOrder(node->left);
    preOrder(node->right);
}

void inOrder(struct TreeNode* node) {
    if (node == NULL) return;
    inOrder(node->left);
    printf("%d ", node->val);
    inOrder(node->right);
}

void postOrder(struct TreeNode* node) {
    if (node == NULL) return;
    postOrder(node->left);
    postOrder(node->right);
    printf("%d ", node->val);
}

int searchBST(struct TreeNode** root, int num) {
    struct TreeNode* temp = *root;
    while (temp != NULL) {
        if (temp->val == num) {
            return 1;
        }
        else if (temp->val < num) {
            temp = temp->right;
        }
        else {
            temp = temp->left;
        }
    }
    return 0;
}

void countNodes(struct TreeNode* node, int* num) {
    if (node == NULL) return;
    *num = *num + 1;
    countNodes(node->left, num);
    countNodes(node->right, num);
}

int countAllNodes(struct TreeNode** root) {
    int count = 0;
    countNodes(*root, &count);
    return count;
}

void countLeaf(struct TreeNode* node, int* num) {
    if (node == NULL) return;
    if (node->left == NULL && node->right == NULL) {
        *num = *num + 1;
        return;
    }
    countLeaf(node->left, num);
    countLeaf(node->right, num);
}

int countAllLeaf(struct TreeNode** root) {
    int count = 0;
    countLeaf(*root, &count);
    return count;
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

    if (root == NULL) return;

    int h = height(root, 0);
    int n = pow(2, h) - 1;
    // printf("Height: %d\n", h);
    // printf("nodes: %d\n", n);

    int arr[h][n];
    for (int i = 0;i < h;i++) {
        for (int j = 0;j < n;j++) {
            arr[i][j] = 0;
        }
    }
    preOrderPrint(root, 0, n, 0, h, n, arr);

    print2dArray(h, n, arr);
}

int main(void) {

    struct TreeNode** root = (struct TreeNode**)malloc(sizeof(struct TreeNode*));
    *root = NULL;

    int choice = 0;
    do {
        printf("\n0. Enter 0 to exit!");
        printf("\n1. Add node to tree.");
        printf("\n2. Show Pre-order traversal.");
        printf("\n3. Show In-order traversal.");
        printf("\n4. Show Post-order traversal.");
        printf("\n5. Count all nodes.");
        printf("\n6. Count leafs");
        printf("\n7. Search number in BST");
        printf("\n8. Print tree.");

        printf("\nYour choice: ");
        scanf("%d", &choice);

        int inp, src;
        switch (choice) {
        case 0:
            printf("\n\nExit...!\n\n");
            break;
        case 1:
            printf("\n\nEnter number to add: ");
            scanf("%d", &inp);
            addNode(root, inp);
            printf("\nNode added!!\n");
            break;
        case 2:
            printf("\n\nPre-order: ");
            preOrder(*root);
            printf("\n\n");
            break;
        case 3:
            printf("\n\nIN-order: ");
            inOrder(*root);
            printf("\n\n");
            break;
        case 4:
            printf("\n\nPost-order: ");
            postOrder(*root);
            printf("\n\n");
            break;
        case 5:
            printf("\n\nAll nodes count: %d\n", countAllNodes(root));
            break;
        case 6:
            printf("\n\nAll leaf nodes count: %d\n", countAllLeaf(root));
            break;
        case 7:
            printf("\n\nEnter number to search: ");
            scanf("%d", &inp);
            if (searchBST(root, inp) == 0) {
                printf("\nNumber doesn't exist!!");
            }
            else {
                printf("\nNumber does exists!!");
            }
            printf("\n\n");
            break;
        case 8:
            printf("\nHere's the tree: ");
            printTree(*root);
            break;
        default:
            printf("\nERROR: Invalid choice!!!");
            break;
        }
    } while (choice != 0);

    return 0;
}