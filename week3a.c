#include <stdio.h>
#define MAX 100

void Push(int stack[], int *top, int value)
{
    if (*top == MAX - 1)
    {
        printf("Stack Overflow\n");
    }
    else
    {
        stack[++(*top)] = value;
        printf("%d pushed to stack\n", value);
    }
}

int Pop(int stack[], int *top)
{
    if (*top == -1)
    {
        printf("Stack Underflow\n");
        return -1;
    }
    else
    {
        return stack[(*top)--];
    }
}

int IsEmpty(int top)
{
    return top == -1;
}

int Size(int top)
{
    return top + 1;
}

void Print(int stack[], int top)
{
    if (IsEmpty(top))
    {
        printf("Stack is empty\n");
    }
    else
    {
        printf("Stack contents (top to bottom): ");
        for (int i = top; i >= 0; i--)
        {
            printf("%d ", stack[i]);
        }
        printf("\n");
    }
}

int main()
{
    int stack[MAX];
    int top = -1;
    int choice, value;

    while (1)
    {
        printf("\nChoose operation:\n");
        printf("1. Push\n2. Pop\n3. Size\n4. IsEmpty\n5. Print\n6. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter value to push: ");
            scanf("%d", &value);
            Push(stack, &top, value);
            break;
        case 2:
            value = Pop(stack, &top);
            if (value != -1)
                printf("Popped: %d\n", value);
            break;
        case 3:
            printf("Stack size: %d\n", Size(top));
            break;
        case 4:
            printf(IsEmpty(top) ? "Stack is empty\n" : "Stack is not empty\n");
            break;
        case 5:
            Print(stack, top);
            break;
        case 6:
            printf("Exiting...\n");
            return 0;
        default:
            printf("Invalid choice\n");
        }
    }
}