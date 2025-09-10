#include <stdio.h>
#define MAX 100

int queue[MAX];
int front, rear, size;

void Create()
{
    front = 0;
    rear = -1;
    size = 0;
}

void EnQueue(int k)
{
    if (rear == MAX - 1)
    {
        printf("Queue Overflow\n");
    }
    else
    {
        queue[++rear] = k;
        size++;
        printf("%d enqueued.\n", k);
    }
}

void DeQueue()
{
    if (size == 0)
    {
        printf("Queue Underflow\n");
    }
    else
    {
        printf("%d dequeued.\n", queue[front++]);
        size--;
    }
}

void IsEmpty()
{
    if (size == 0)
        printf("Queue is empty.\n");
    else
        printf("Queue is not empty.\n");
}

void Size()
{
    printf("Queue size: %d\n", size);
}

void Display()
{
    if (size == 0)
    {
        printf("Queue is empty.\n");
    }
    else
    {
        printf("Queue elements: ");
        for (int i = front; i <= rear; i++)
        {
            printf("%d ", queue[i]);
        }
        printf("\n");
    }
}

int main()
{
    int choice, k;

    while (1)
    {
        printf("\n1. Create\n2. EnQueue\n3. DeQueue\n4. IsEmpty\n5. Size\n6. Display\n7. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            Create();
            printf("Queue created.\n");
            break;

        case 2:
            printf("Enter element to enqueue: ");
            scanf("%d", &k);
            EnQueue(k);
            break;

        case 3:
            DeQueue();
            break;

        case 4:
            IsEmpty();
            break;

        case 5:
            Size();
            break;

        case 6:
            Display();
            break;

        case 7:
            return 0;

        default:
            printf("Invalid choice.\n");
        }
    }

    return 0;
}