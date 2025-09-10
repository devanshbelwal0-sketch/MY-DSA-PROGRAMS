#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX 100

int stack[MAX];
int top = -1;

void push(int x)
{
    if (top == MAX - 1)
    {
        printf("Stack overflow\n");
        exit(1);
    }
    stack[++top] = x;
}

int pop()
{
    if (top == -1)
    {
        printf("Stack underflow\n");
        exit(1);
    }
    return stack[top--];
}

int evaluatePostfix(char *exp)
{
    int i = 0;

    while (exp[i] != '\0')
    {
        if (isspace(exp[i]))
        {
            i++;
            continue;
        }
        if (exp[i] == '(' || exp[i] == ')')
        {
            i++;
            continue;
        }
        if (isdigit(exp[i]) || (exp[i] == '-' && isdigit(exp[i + 1])))
        {
            int num = 0, sign = 1;
            if (exp[i] == '-')
            {
                sign = -1;
                i++;
            }

            // Build the number
            while (isdigit(exp[i]))
            {
                num = num * 10 + (exp[i] - '0');
                i++;
            }

            push(sign * num);
        }
        else
        {

            int val2 = pop();
            int val1 = pop();

            switch (exp[i])
            {
            case '+':
                push(val1 + val2);
                break;
            case '-':
                push(val1 - val2);
                break;
            case '*':
                push(val1 * val2);
                break;
            case '/':
                push(val1 / val2);
                break;
            case '^':
            {
                int res = 1;
                for (int j = 0; j < val2; j++)
                    res *= val1;
                push(res);
                break;
            }
            default:
                printf("Invalid operator: %c\n", exp[i]);
                exit(1);
            }
            i++;
        }
    }
    return pop();
}

int main()
{
    printf("enter the number of test cases: ");
    int t;
    scanf("%d", &t);
    while (t--)
    {
        while (getchar() != '\n');
        top = -1; // Reset stack for next test case
        char exp[200];

        printf("Enter a postfix expression \n");
        scanf("%[^\n]s", exp);

        int result = evaluatePostfix(exp);
        printf("Result = %d\n", result);
    }
    return 0;
}
