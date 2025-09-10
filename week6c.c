#include <stdio.h>
#define MAX 5

void Create(int *front, int *rear)
{
    *front = -1;
    *rear = -1;
    printf("Queue created\n");
}

int IsEmpty(int front, int rear)
{
    return (front == -1 && rear == -1);
}

void EnQueue(int queue[], int *front, int *rear, int value)
{
    if ((*rear + 1) % MAX == *front)
    {
        printf("Queue is full\n");
        return;
    }
    if (*rear == -1 && *front == -1)
    {
        *rear = *front = 0;
    }
    else
    {
        *rear = (*rear + 1) % MAX;
    }
    queue[*rear] = value;
    printf("%d enqueued\n", value);
}

void DeQueue(int queue[], int *front, int *rear)
{
    if (IsEmpty(*front, *rear))
    {
        printf("Queue is empty\n");
        return;
    }
    printf("%d dequeued\n", queue[*front]);
    if (*front == *rear)
    {
        *front = *rear = -1;
    }
    else
    {
        *front = (*front + 1) % MAX;
    }
}

void Front(int queue[], int front, int rear)
{
    if (IsEmpty(front, rear))
    {
        printf("Queue is empty\n");
    }
    else
    {
        printf("Front element: %d\n", queue[front]);
    }
}

void Rear(int queue[], int front, int rear)
{
    if (IsEmpty(front, rear))
    {
        printf("Queue is empty\n");
    }
    else
    {
        printf("Rear element: %d\n", queue[rear]);
    }
}

void Display(int queue[], int front, int rear)
{
    if (IsEmpty(front, rear))
    {
        printf("Queue is empty\n");
        return;
    }
    printf("Queue elements: ");
    int temp = front;
    while (temp != rear)
    {
        printf("%d ", queue[temp]);
        temp = (temp + 1) % MAX;
    }
    printf("%d\n", queue[temp]);
}

int main()
{
    int value, choice;
    int queue[MAX];
    int front = -1, rear = -1;

    while (1)
    {
        printf("\nChoose operation:\n");
        printf("1. Create\n2. EnQueue\n3. DeQueue\n4. Display\n5. IsEmpty\n6. Front\n7. Rear\n8. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            Create(&front, &rear);
            break;
        case 2:
            printf("Enter value to enqueue: ");
            scanf("%d", &value);
            EnQueue(queue, &front, &rear, value);
            break;
        case 3:
            DeQueue(queue, &front, &rear);
            break;
        case 4:
            Display(queue, front, rear);
            break;
        case 5:
            if (IsEmpty(front, rear))
                printf("Queue is empty\n");
            else
                printf("Queue is not empty\n");
            break;
        case 6:
            Front(queue, front, rear);
            break;
        case 7:
            Rear(queue, front, rear);
            break;
        case 8:
            printf("Exiting...\n");
            return 0;
        default:
            printf("Invalid choice, enter from 1 to 8\n");
        }
    }

    return 0;
}