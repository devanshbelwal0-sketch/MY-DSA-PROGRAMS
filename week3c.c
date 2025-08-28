#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX 100
int stack[MAX];
int top=-1;
void push( int value)
{
    if (top == MAX - 1)
    {
        printf("Stack Overflow\n");
    }
    else
    {
        stack[++(top)] = value;
        printf("%d pushed to stack\n", value);
    }
}

int pop()
{
    if (top == -1)
    {
        printf("Stack Underflow\n");
        return -1;
    }
    else
    {
        return stack[(top)--];
    }
}
int peek()
{
    if (top == -1)
        return -1;
    return stack[top];
}

int main()
{
    char str[MAX];
    printf("enter the paranthesis string: ");
    scanf("%s", str);
    int n = strlen(str);
    int maxlen=0;
    push(-1);
    for (int i = 0; i < n; i++)
    {
        if (str[i] == '(')
        {
            push(i);
        }
        else
        {
            pop();
        }
        if (top == -1)
        {
            push(i);
        }
        else
        {
            int length = i - peek();
            if (length > maxlen)
                maxlen=length;
        }
    }
    printf("the maximum lenth of the valid paranthesis is %d", maxlen);
    return 0;
}
