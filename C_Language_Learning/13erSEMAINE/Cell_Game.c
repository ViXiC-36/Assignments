#include <stdio.h>
int Count(char pl[42][42], int i, int j)
{
    int e = 0;
    if (pl[i + 1][j + 1] == '*')
        e++;
    if (pl[i + 1][j - 1] == '*')
        e++;
    if (pl[i - 1][j + 1] == '*')
        e++;
    if (pl[i - 1][j - 1] == '*')
        e++;
    if (pl[i][j + 1] == '*')
        e++;
    if (pl[i][j - 1] == '*')
        e++;
    if (pl[i + 1][j] == '*')
        e++;
    if (pl[i - 1][j] == '*')
        e++;
    return e;
}
int main()
{
    int i, j, n;
    char pl[42][42], pll[42][42]; // expand the edges;
    for (i = 0; i < 42; i++)
    {
        pl[0][i] = ' ';
        pl[i][0] = ' ';
        pl[41][i] = ' ';
        pl[i][41] = ' ';
    }
    for (i = 1; i < 41; i++)
    {
        for (j = 1; j < 41; j++)
        {
            scanf("%c", &pl[i][j]);
        }
        getchar();
        
    }
    scanf("%d", &n);
    while (n > 0)
    {
        for (i = 1; i < 41; i++)
        {
            for (j = 1; j < 41; j++)
            {
                if (pl[i][j] == '*')
                {
                    if ((Count(pl, i, j) == 2) || (Count(pl, i, j) == 3))
                        pll[i][j] = '*';
                    else
                        pll[i][j] = 'x';
                }
                if (pl[i][j] == 'x')
                {
                    if (Count(pl, i, j) == 3)
                        pll[i][j] = '*';
                    else
                        pll[i][j] = 'x';
                }
            }
        }
        n--;
        for (i = 1; i < 41; i++)
        {
            for (j = 1; j < 41; j++)
            {
                pl[i][j] = pll[i][j];
            }
        }
    }
    for (i = 1; i < 41; i++)
    {
        for (j = 1; j < 41; j++)
        {
            printf("%c", pl[i][j]);
        }
        printf("\n");
    }
    return 0;
}