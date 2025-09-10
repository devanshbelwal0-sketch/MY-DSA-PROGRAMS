#include <stdio.h>
#define MAX 100

int deque[MAX];
int front = -1, rear = -1;

void insertFront(int x)
{
    if ((front == 0 && rear == MAX - 1) || (front == rear + 1))
    {
        printf("Deque is full\n");
        return;
    }
    if (front == -1)
    {
        front = rear = 0;
    }
    else if (front == 0)
    {
        front = MAX - 1;
    }
    else
    {
        front--;
    }
    deque[front] = x;
}

void insertEnd(int x)
{
    if ((front == 0 && rear == MAX - 1) || (front == rear + 1))
    {
        printf("Deque is full\n");
        return;
    }
    if (front == -1)
    {
        front = rear = 0;
    }
    else if (rear == MAX - 1)
    {
        rear = 0;
    }
    else
    {
        rear++;
    }
    deque[rear] = x;
}

void deleteFront()
{
    if (front == -1)
    {
        printf("Deque is empty\n");
        return;
    }
    printf("%d deleted from front\n", deque[front]);
    if (front == rear)
    {
        front = rear = -1;
    }
    else if (front == MAX - 1)
    {
        front = 0;
    }
    else
    {
        front++;
    }
}

void deleteEnd()
{
    if (front == -1)
    {
        printf("Deque is empty\n");
        return;
    }
    printf("%d deleted from end\n", deque[rear]);
    if (front == rear)
    {
        front = rear = -1;
    }
    else if (rear == 0)
    {
        rear = MAX - 1;
    }
    else
    {
        rear--;
    }
}

void isEmpty()
{
    if (front == -1)
        printf("Deque is empty\n");
    else
        printf("Deque is not empty\n");
}

void isFull()
{
    if ((front == 0 && rear == MAX - 1) || (front == rear + 1))
        printf("Deque is full\n");
    else
        printf("Deque is not full\n");
}

void printFront()
{
    if (front == -1)
    {
        printf("Deque is empty\n");
        return;
    }
    printf("Deque from front: ");
    int i = front;
    while (1)
    {
        printf("%d ", deque[i]);
        if (i == rear)
            break;
        i = (i + 1) % MAX;
    }
    printf("\n");
}

void printEnd()
{
    if (front == -1)
    {
        printf("Deque is empty\n");
        return;
    }
    printf("Deque from end: ");
    int i = rear;
    while (1)
    {
        printf("%d ", deque[i]);
        if (i == front)
            break;
        i = (i - 1 + MAX) % MAX;
    }
    printf("\n");
}

int main()
{
    int choice, x;
    while (1)
    {
        printf("\n1.Insert Front\n2.Insert End\n3.Delete Front\n4.Delete End\n5.Is Empty\n6.Is Full\n7.Print Front\n8.Print End\n9.Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter element to insert at front: ");
            scanf("%d", &x);
            insertFront(x);
            break;

        case 2:
            printf("Enter element to insert at end: ");
            scanf("%d", &x);
            insertEnd(x);
            break;

        case 3:
            deleteFront();
            break;

        case 4:
            deleteEnd();
            break;

        case 5:
            isEmpty();
            break;

        case 6:
            isFull();
            break;

        case 7:
            printFront();
            break;

        case 8:
            printEnd();
            break;

        case 9:
            printf("Exiting...\n");
            return 0;

        default:
            printf("Invalid choice\n");
        }
    }
}