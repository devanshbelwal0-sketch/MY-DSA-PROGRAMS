// // WITHOUT RECURSION

// #include <stdio.h>
// #include <string.h>

// #define MAX 100

// int main()
// {
//     char str[MAX], stack[MAX];
//     int top = -1, i, len;
//     printf("enter the element to be pushed: ");
//     scanf("%s", str);
//     len = strlen(str);

//     for (i = 0; i < len; i++)
//     {
//         stack[++top] = str[i];
//     }

//     for (i = 0; i < len; i++)
//     {
//         str[i] = stack[top--];
//     }

//     str[len] = '\0';
//     printf("%s\n", str);

//     return 0;
// }

// WITH RECURSION

// WITHOUT RECURSION

#include <stdio.h>
#include <string.h>

#define MAX 100

char stack[MAX];
int top = -1;

void push(char ch) {
    stack[++top] = ch;
}

char pop() {
    return stack[top--];
}

void fillStack(char *str, int i) {
    if (str[i] == '\0') return;
    push(str[i]);
    fillStack(str, i + 1);
}

void writeBack(char *str, int i) {
    if (top < 0) {
        str[i] = '\0';
        return;
    }
    str[i] = pop();
    writeBack(str, i + 1);
}

int main() {
    char str[MAX];
    printf("enter the element to be pushed: ");
    scanf("%s", str);

    fillStack(str, 0);
    writeBack(str, 0);

    printf("%s\n", str);
    return 0;
}
