#include<stdio.h>
#define N 10
int main()
{
    int m, p, t, n;
    int i, j, k;
    int A[N][N] = {0}, B[N][N] = {0}, C[N][N] = {0};
    printf("Please input the number of rows & columns of A:\n");
    scanf("%d%d", m, p);
    printf("Please input the number of rows & columns of B:\n");
    scanf("%d%d", t, n);
    if (p != t)
    {
        printf("Can't be calculated!\n");
        return 0;
    }
    for ( i = 0; i < m; i++)
    {
        for (j = 0; j < n; j++)
        {
            C[i][j] += A[i][j] * B[j][i];
        }
    }
    
}