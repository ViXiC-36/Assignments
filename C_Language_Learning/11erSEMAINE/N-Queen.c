#include <stdio.h>
int sol = 0, n, k = 0;                    // sol is the number of solutions;
int col[9] = {9, 9, 9, 9, 9, 9, 9, 9, 9}; // col means column;
int answer[1000] = {0};                   // To store the final solutions;
int Inspect(int row, int c)               // input row & col[row];
{
    int i;
    for (i = 0; i < row; i++)
    {
        if (col[i] == c) // The i-th column;
            return 0;
        if (row - c == i - col[i]) // dialine UL-LR;
            return 0;
        if (row + c == i + col[i]) // dialine UR-LL;
            return 0;
    }
    return 1;
}
void Plce(int Q) // placing the Qth Queen in a single solution;
{
    int i, j;
    if (Q == n) // done with one single solution;
    {
        sol++;
        for (j = 0; j < n; j++, k++)
        {
            answer[k] = col[j];
        }
    }
    for (i = 0; i < n; i++)
    {
        if (Inspect(Q, i) == 1) // Q-th queen, i-th column;
        {
            col[Q] = i;
            Plce(Q + 1);
            col[Q] = 9;
            /*After n layers of computation,
            re-initialize and go back to the last row;*/
        }
    }
}
int main()
{
    int i, j;
    scanf("%d", &n);
    if (n <= 3)
    {
        printf("0\n");
        return 0;
    }
    Plce(0);
    printf("%d", sol);
    for (i = 0, j = 0; i < sol * n; i++, j++)
    {
        if (j % n == 0)
        {
            printf("\n");
        }
        printf("%d", answer[i] + 1);
    }
    return 0;
}