#include <stdio.h>
#define MAX 100

int main() {
    int queue[MAX], stack[MAX];
    int front = 0, rear = -1, size = 0;
    int top = -1;
    int n, i;
    printf("Enter number of elements to enqueue: ");
    scanf("%d", &n);
    for (i = 0; i < n; i++) {
        int val;
        scanf("%d", &val);
        queue[++rear] = val;
        size++;
    }

    while (size > 0) {
        stack[++top] = queue[front++];
        size--;
    }

    front = 0;
    rear = -1;
    while (top >= 0) {
        queue[++rear] = stack[top--];
    }

    for (i = front; i <= rear; i++) {
        printf("%d ", queue[i]);
    }
    printf("\n");

    return 0;
}