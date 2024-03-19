#include <stdio.h>
int ajustment(int x, int y, int n)
{
    if (x < 0)
        x += n;
    if (x >= n)
        x -= n;
    if (y < 0)
        y += n;
    if (y >= n)
        y -= n;
}//This is wrong.In C language,there is only ONE output of a function;
//for improvement,a struct is utilized.
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
        ajustment(i, j, n);
        if (M[i][j] == 0)
        {
            M[i][j] = c;
        }
        else
        {
            i += 2;
            j -= 1;
            ajustment(i, j, n);
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