#include <stdio.h>
int C(int m, int n)
{
    int up = 1, low = 1, i;
    for (i = 1; i <= n; i++)
    {
        up *= m;
        low *= i;
        m--;
    }
    return up / low;
}
int main()
{
    int n, i, j;
    scanf("%d", &n);
    for (i = 0; i < n ; i++)
    {
        printf("  ");
    }
    printf("   1\n");
    for (i = 1; i < n + 1; i++) //(i+1)th row
    {
        for (j = 1; j <= n - i; j++) // print the spaces;
        {
            printf("  "); // two spaces each time;
        }
        for (j = 0; j < i + 1; j++)
        {
            printf("%4d", C(i, j));
        }
        printf("\n");
    }
    return 0;
}