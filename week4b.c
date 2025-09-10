#include <stdio.h>
#include <stdlib.h>
#define MAX 5
int stack[MAX];
int top1 = -1;
int top2 = MAX;
void push1(int value)
{
    if (top1 == MAX - 1)
    {
        printf("Stack Overflow\n");
    }
    else
    {
        stack[++(top1)] = value;
        printf("%d pushed to stack\n", value);
    }
}
void push2(int value)
{
    if (top2 < top1 - 1)
    {
        printf("Stack Overflow\n");
    }
    else
    {
        stack[--(top2)] = value;
        printf("%d pushed to stack\n", value);
    }
}

int pop1()
{
    if (top1 == -1)
    {
        printf("Stack Underflow\n");
        return -1;
    }
    else
    {
        return stack[(top1)--];
    }
}
int pop2()
{
    if (top2 == MAX)
    {
        printf("Stack Underflow\n");
        return -1;
    }
    else
    {
        return stack[(top2)++];
    }
}
void display1()
{
    if (top1 == -1)
        printf("Stack 1 is empty\n");
    else
    {
        printf("Stack 1: ");
        for (int i = top1; i >= 0; i--)
            printf("%d ", stack[i]);
        printf("\n");
    }
}

void display2()
{
    if (top2 == MAX)
        printf("Stack 2 is empty\n");
    else
    {
        printf("Stack 2: ");
        for (int i = top2; i < MAX; i++)
            printf("%d ", stack[i]);
        printf("\n");
    }
}

int main()
{
    int choice;
    int value;
    while (1)
    {
        printf("\nChoose operation:\n");
        printf("1. Push in stack 1\n2. Pop in stack 1\n3. Push in stack 2\n4. Pop in stack 2\n5. Display of stack 1\n6. Display of stack 2\n7. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);
        switch (choice)
        {

        case 1:
            printf("enter the value to push: ");
            scanf("%d",&value);
            push1(value);
            break;

        case 2:
            pop1();
            break;

        case 3:
            printf("enter the value to push: ");
            scanf("%d",&value);
            push2(value);
            break;

        case 4:
            pop2();
            break;

        case 5:
             display1();
             break;
        case 6:
             display2();
             break;
        case 7:
            exit(0);

        default:
            printf("Invalid choice\n");
        }
    }
    return 0;
}
