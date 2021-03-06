#include <stdio.h>
#include <stdlib.h>

typedef struct LinkedNode {
    int val;
    struct LinkedNode* next;
};
struct LinkedNode* head = NULL;
struct LinkedNode* tail = NULL;

int searchElem(int n) {
    struct LinkedNode* temp;
    temp = head;
    while (temp != NULL) {
        if (temp->val == n) {
            return 1;
        }
        temp = temp->next;
    }
    return 0;
}

void add(int num) {
    struct LinkedNode* node;
    node = (struct LinkedNode*)malloc(sizeof(struct LinkedNode));
    node->val = num;
    node->next = head;
    if (head == NULL) {
        tail = node;
    }
    head = node;
}

void addToEnd(int num) {
    if (head == NULL || tail == NULL) {
        add(num);
        return;
    }
    struct LinkedNode* node;
    node = (struct LinkedNode*)malloc(sizeof(struct LinkedNode));
    node->val = num;
    node->next = NULL;
    tail->next = node;
    tail = node;
}

void searchAdd(int s, int n, int order) {
    struct LinkedNode* temp;
    temp = head;

    //     order = 1 (after) 0 (before)
    if (temp != NULL && temp->val == s) {
        struct LinkedNode* node;
        node = (struct LinkedNode*)malloc(sizeof(struct LinkedNode));
        node->val = n;

        if (order == 1) {
            node->next = temp->next;
            temp->next = node;
        }
        else {
            node->next = head;
            head = node;
        }
        return;
    }

    while (temp != NULL) {
        if (temp->next->val == s) {
            struct LinkedNode* node;
            node = (struct LinkedNode*)malloc(sizeof(struct LinkedNode));
            node->val = n;

            if (order == 1) {
                temp = temp->next;
            }
            node->next = temp->next;
            temp->next = node;
            if (node->next == NULL) {
                tail = node;
            }
            return;
        }
        temp = temp->next;
    }
}

void printLinkedList() {
    struct LinkedNode* temp;
    temp = head;

    printf("\n[ ");
    while (temp != NULL) {
        printf("%d ", temp->val);
        temp = temp->next;
    }
    printf("]");
}

void deleteElem(int n) {
    if (searchElem(n) == 1) {
        struct LinkedNode* temp;
        temp = head;

        if (temp->val == n) {
            head = head->next;
            return;
        }

        while (temp != NULL) {
            if (temp->next->val == n) {
                if (temp->next == tail) {
                    tail = temp;
                }
                temp->next = temp->next->next;
                return;
            }
            temp = temp->next;
        }
    }
}

void pop() {
    struct LinkedNode* temp;
    temp = head;

    if (temp != NULL) {
        head = head->next;
    }
}

void reverseList() {
    if (head == NULL || tail == NULL) return;

    struct LinkedNode* prev = NULL, * curr = NULL;

    while (head != NULL) {
        prev = curr;
        curr = head;
        head = head->next;
        curr->next = prev;
    }
    head = curr;
}

int main() {

    int choice = 0;
    do {
        printf("\n0. Enter 0 to exit!");
        printf("\n1. Add element at the start of the list.");
        printf("\n2. Add element at the end of the list.");
        printf("\n3. Search for element.");
        printf("\n4. Search and add after.");
        printf("\n5. Search and add before.");
        printf("\n6. Display the list.");
        printf("\n7. Pop the head element.");
        printf("\n8. Pop the tail element.");
        printf("\n9. Search and delete.");
        printf("\n10. Reverse the list.");

        printf("\nYour choice: ");
        scanf("%d", &choice);

        int inp, src;
        switch (choice) {
        case 0:
            printf("\n\nExit...!\n\n");
            break;
        case 1:
            printf("\n\nEnter element to add at start: ");
            scanf("%d", &inp);
            add(inp);
            printf("\nElement added!!\n");
            break;
        case 2:
            printf("\n\nEnter element to add at end: ");
            scanf("%d", &inp);
            addToEnd(inp);
            printf("\nElement added!!\n");
            break;
        case 3:
            printf("\n\nEnter element to search: ");
            scanf("%d", &inp);
            printf("\nIs element %d present: %d\n", inp, searchElem(inp));
            break;
        case 4:
            printf("\n\nEnter element to search and add after: ");
            scanf("%d", &src);
            printf("\n\nEnter element to add: ");
            scanf("%d", &inp);
            searchAdd(src, inp, 1);
            printf("\n");
            break;
        case 5:
            printf("\n\nEnter element to search and add before: ");
            scanf("%d", &src);
            printf("\n\nEnter element to add: ");
            scanf("%d", &inp);
            searchAdd(src, inp, 0);
            printf("\n");
            break;
        case 6:
            printf("\n");
            printLinkedList();
            printf("\n");
            break;
        case 7:
            pop();
            printf("\n\nElement popped!!\n");
            break;
        case 8:
            deleteElem(tail->val);
            printf("\n\nElement popped!!\n");
            break;
        case 9:
            printf("\n\nEnter element to delete: ");
            scanf("%d", &inp);
            deleteElem(inp);
            printf("\n");
            break;
        case 10:
            reverseList();
            printf("\n");
            break;
        default:
            printf("\nERROR: Invalid choice!!!");
            break;
        }
    } while (choice != 0);

    return 0;
}