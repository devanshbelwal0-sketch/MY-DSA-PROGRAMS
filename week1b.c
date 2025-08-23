#include <stdio.h>
#include<stdlib.h>
#include <limits.h>
int main()
{
    int t;
    printf("enter the number test cases: ");
    scanf("%d", &t);
    while (t--)
    {
        int n;
        printf("enter the number of elements to be inserted: ");
        scanf("%d", &n);
        int arr[n];
        printf("enter the elements: ");
        for (int i = 0; i < n; i++)
        {
            scanf("%d", &arr[i]);
        }
        int a, b;
        printf("enter the first key numbers to find the minimum distance : "); // Devansh Belwal
        scanf("%d %d",&a,&b);
        int x = -1, y = -1;
        int res = INT_MAX;
        for (int i = 0; i < n; i++)
        {
            if (a == arr[i])
            {
                x = i;
            }
        }
        for (int i = 0; i < n; i++)
        {
            if (b == arr[i])
            {
                y = i;
            }
        }
        if (x != -1 && y != -1) // Devansh Belwal
        {
            if (abs(x - y) < res)
            {
                res = abs(x - y);
            }
        }
        printf("%d", res);
        printf("\n");
    }
    return 0;
}