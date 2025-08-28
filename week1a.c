#include <stdio.h>
int main()
{
    int t;
    printf("enter the number of test cases: ");
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
        int k;
        printf("enter the number of times the array to be rotated: ");
        scanf("%d", &k);
        k = k % n; // Devansh Belwal
        int temp;
        int j;
        while (k--)
        {
            temp = arr[0];
            for (j = 0; j < n; j++)
            {
                arr[j - 1] = arr[j];
            }
            arr[j - 1] = temp;
        }
        printf("the rotated array is below\n");
        for (int i = 0; i < n; i++)
        {
            printf("%d", arr[i]);
            printf(" ");
        }
        printf("\n");
    }
    return 0;
}
