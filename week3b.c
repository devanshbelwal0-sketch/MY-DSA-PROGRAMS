#include <stdio.h>
#include <string.h>

#define MAX 100

int main()
{
    int T;
    printf("enter the number of test cases: ");
    scanf("%d", &T);

    while (T--)
    {
        char exp[MAX];
        printf("enter the expression: ");
        scanf("%s", exp);

        char stack[MAX];
        int top = -1;
        int balanced = 1;

        for (int i = 0; exp[i] != '\0'; i++)
        {
            char ch = exp[i];
            if (ch == '(' || ch == '{' || ch == '[')
            {
                if (top < MAX - 1)
                {
                    stack[++top] = ch;
                }
            }
            else if (ch == ')' || ch == '}' || ch == ']')
            {
                if (top == -1)
                {
                    balanced = 0;
                    break;
                }
                char open = stack[top--];
                if ((ch == ')' && open != '(') ||
                    (ch == '}' && open != '{') ||
                    (ch == ']' && open != '['))
                {
                    balanced = 0;
                    break;
                }
            }
        }

        if (top != -1)
            balanced = 0;

        if (balanced)
            printf("Balanced\n");
        else
            printf("Unbalanced\n");
    }
    return 0;
}