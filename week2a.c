#include <stdio.h>
int main()
{
    int n;
    printf("ENTER N..\n");
    scanf("%d", &n);
    int mat[n][n];
    printf("ENTER ELEMENTS\n");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {

            scanf("%d", &mat[i][j]);
        }
    }
    int num;
    int flag = 0;
    printf("ENTER AN NUMBER...\n");
    scanf("%d", &num);
    int i = 0, j = n - 1;
    while (i < n && j > 0)
    {

        if (num == mat[i][j])
        {
            printf("PRESENT\n");
            break;
        }
        if (mat[i][j] > num)
        {
            j--;
        }
        else
        {
            i++;
        }
    }
    if (num != mat[i][j])
    {
        printf("NOT PRESENT\n");
    }
    return 0;
}
