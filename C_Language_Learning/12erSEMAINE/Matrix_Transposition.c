#include <stdio.h>
int main()/*Matrix Transportation*/
{
    int m, n, i, j, k;
    scanf("%d %d", &m, &n);/*define the size of the matrix*/
    int m0[100][100] = {0}, mT[10000] = {0};/*Prepare an oversized array*/
    for (i = 0; i < m; i++)
    {
        for (j = 0; j < n; j++)
        {
            scanf("%d", &m0[i][j]);
        }
    }/*input*/
    int *p = mT;/*create a pointer and assign it to an address*/
    for (j = 0, k = 0; j < n; j++)
    {
        for (i = 0; i < m; i++)
        {
            *(p + k) = m0[i][j];/*p is a 1 D array*/
            k++;
        }
    }
    for (i = 0; i < m * n; i++)
    {
        if (i % m == 0)
            printf("\n");
        printf("%d ", *(p + i));
    }
    return 0;
}