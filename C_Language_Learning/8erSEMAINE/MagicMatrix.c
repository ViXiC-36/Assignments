#include <stdio.h>
int main()
{
    int n, i, j, count = 0, c;
    scanf("%d", &n);
    int M[100][100] = {{0, 0}};

    M[0][(n - 1) / 2] = 1;
    i = 0;
    j = (n - 1) / 2;
    for (c = 2; c <= n * n; c++)
    {
        i -= 1;
        j += 1;
        if (i < 0)
            i += n;
        if (i >= n)
            i -= n;
        if (j < 0)
            j += n;
        if (j >= n)
            j -= n;
        if (M[i][j] == 0)
        {
            M[i][j] = c;
        }
        else
        {
            i += 2;
            j -= 1;
            if (i < 0)
                i += n;
            if (i >= n)
                i -= n;
            if (j < 0)
                j += n;
            if (j >= n)
                j -= n;
            M[i][j] = c;
        }
    }
    for (i = 0; i < n; i++) // output
    {
        for (j = 0; j < n; j++)
        {
            printf("%5d", M[i][j]);
            count++;
            if (count == n)
            {
                printf("\n");
                count = 0;
            }
        }
    }
}