#include <stdio.h>
#define MAX 100

int stack[MAX];
int top = -1;

void push(int x)
{
    if (top == MAX - 1)
    {
        printf("Stack Overflow\n");
        return;
    }
    stack[++top] = x;
}

int pop()
{
    if (top == -1)
    {
        return -1;
    }
    return stack[top--];
}

void EnQueue(int x)
{
    push(x);
    printf("%d enqueued\n", x);
}

int DeQueue()
{
    if (top == -1)
    {
        printf("Queue Underflow\n");
        return -1;
    }

    int x = pop();

    if (top == -1)
    {
        return x;
    }
    else
    {
        int item = DeQueue();
        push(x);
        return item;
    }
}

void Display()
{
    if (top == -1)
    {
        printf("Queue is empty\n");
        return;
    }
    printf("Queue elements: ");
    for (int i = 0; i <= top; i++)
    {
        printf("%d ", stack[i]);
    }
    printf("\n");
}

void IsEmpty()
{
    if (top == -1)
        printf("Queue is empty\n");
    else
        printf("Queue is not empty\n");
}

int main()
{
    int choice, x;
    while (1)
    {
        printf("\n1. EnQueue\n2. DeQueue\n3. Display\n4. IsEmpty\n5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter element to enqueue: ");
            scanf("%d", &x);
            EnQueue(x);
            break;

        case 2:
            x = DeQueue();
            if (x != -1)
                printf("%d dequeued\n", x);
            break;

        case 3:
            Display();
            break;

        case 4:
            IsEmpty();
            break;

        case 5:
            return 0;

        default:
            printf("Invalid choice\n");
        }
    }
}