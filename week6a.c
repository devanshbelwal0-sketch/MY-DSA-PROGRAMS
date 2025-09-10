#include <stdio.h>
#define MAX 100

int queue[MAX];
int front = 0, rear = -1, size = 0;

void EnQueue(int x)
{
    queue[++rear] = x;
    size++;
}

int DeQueue()
{
    if (size == 0)
        return -1;
    int val = queue[front++];
    size--;
    return val;
}

void push(int x)
{
    EnQueue(x);
    for (int i = 0; i < size - 1; i++)
    {
        int temp = DeQueue();
        EnQueue(temp);
    }
    front = rear - size + 1;
    printf("%d pushed\n", x);
}

void pop()
{
    if (size == 0)
    {
        printf("Stack Underflow\n");
        return;
    }
    int val = DeQueue();
    printf("%d popped\n", val);
}

void top()
{
    if (size == 0)
    {
        printf("Stack is empty\n");
    }
    else
    {
        printf("Top element: %d\n", queue[front]);
    }
}

void isEmpty()
{
    if (size == 0)
        printf("Stack is empty\n");
    else
        printf("Stack is not empty\n");
}

void display()
{
    if (size == 0)
    {
        printf("Stack is empty\n");
        return;
    }
    printf("Stack elements: ");
    for (int i = front; i <= rear; i++)
    {
        printf("%d ", queue[i]);
    }
    printf("\n");
}

int main()
{
    int choice, x;
    while (1)
    {
        printf("\n1.Push\n2.Pop\n3.Top\n4.IsEmpty\n5.Display\n6.Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter element to push: ");
            scanf("%d", &x);
            push(x);
            break;
        case 2:
            pop();
            break;
        case 3:
            top();
            break;
        case 4:
            isEmpty();
            break;
        case 5:
            display();
            break;
        case 6:
            return 0;
        default:
            printf("Invalid choice\n");
        }
    }
}