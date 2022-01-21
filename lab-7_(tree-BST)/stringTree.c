#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct TreeNode {
    char val[1000];
    struct TreeNode* left;
    struct TreeNode* right;
};

void addNode(struct TreeNode** root, char* num) {
    struct TreeNode* node;
    node = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    strcpy(node->val, num);
    node->left = NULL;
    node->right = NULL;

    if (*root == NULL) {
        *root = node;
        return;
    }

    struct TreeNode* temp = *root;
    while (temp != NULL) {
        if (strcmp(temp->val, num) == 0) {
            break;
        }if (strcmp(temp->val, num) < 0) {
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
    printf("%s ", node->val);
    preOrder(node->left);
    preOrder(node->right);
}

void inOrder(struct TreeNode* node) {
    if (node == NULL) return;
    inOrder(node->left);
    printf("%s ", node->val);
    inOrder(node->right);
}

void postOrder(struct TreeNode* node) {
    if (node == NULL) return;
    postOrder(node->left);
    postOrder(node->right);
    printf("%s ", node->val);
}

int searchBST(struct TreeNode** root, char num[]) {
    struct TreeNode* temp = *root;
    while (temp != NULL) {
        if (strcmp(temp->val, num) == 0) {
            return 1;
        }
        else if (strcmp(temp->val, num) < 0) {
            temp = temp->right;
        }
        else {
            temp = temp->left;
        }
    }
    return 0;
}

int main(void) {

    struct TreeNode** root = (struct TreeNode**)malloc(sizeof(struct TreeNode*));
    *root = NULL;

    FILE* fptr = fopen("data.txt", "r");
    if (fptr == NULL)
    {
        printf("Cannot open file \n");
        return 0;
    }

    // Read contents from file
    int bufferLength = 255;
    char buffer[bufferLength];
    while (fgets(buffer, bufferLength, fptr)) {

        int len = strlen(buffer);
        if (buffer[len - 1] == '\n') {
            buffer[len - 1] = 0;
        }
        addNode(root, buffer);
    }
    fclose(fptr);

    printf("\npre-order: ");
    preOrder(*root);
    printf("\nin-order: ");
    inOrder(*root);
    printf("\npost-order: ");
    postOrder(*root);
    printf("\n");

    int e = 1;
    do {
        printf("\nEnter string to search for: ");

        char inp[1000];
        scanf("%s", inp);
        printf("Does %s exist: %s", inp, ((searchBST(root, inp) ? "YES" : "NO")));

        printf("\n\nEnter 0 to exit: ");
        scanf("%d", &e);

    } while (e != 0);
    printf("\n");

    return 0;
}