#include<stdio.h>
#include <stdlib.h>
int front = -1;
int rear = -1;
int* ptr;
int max = 5;
void enque();
void show();
void deque();
void main()
{
    int case1;
    ptr = (int*)calloc(max, sizeof(int));

    while (1)
    {
        printf("1.Enqueue Operation\n");
        printf("2.Dequeue Operation\n");
        printf("3.Display the Queue\n");
        printf("4.Exit\n");
        printf("Enter your choice of operations : ");
        scanf("%d", &case1);
        switch (case1)
        {
        case 1:
            enque();
            break;
        case 2:
            deque();
            break;
        case 3:
            show();
            break;

        }
    }

}
void enque() {
    int sit;
    if (rear == max - 1) {
        printf("*****overFLOW*****\n");
    }
    else if (front == -1 && rear == -1)
    {
        front = 0;
        rear = 0;
        printf("Enter the person you want to sit : ");
        scanf("%d", &sit);
        ptr[rear] = sit;
    }
    else {
        rear = rear + 1;
        printf("Enter the person you want to sit : ");
        scanf("%d", &sit);
        ptr[rear] = sit;
    }

}
void show() {
    for (int i = 0; i <= rear; i++)
    {
        printf("%d ", ptr[i]);
    }
    printf("\n");

}
void deque() {
    if ((front == -1 && rear == -1) || front > rear)
    {
        printf("****Underflow****\n");
    }
    else {
        ptr[front] = 0;
        front = front + 1;
    }

}