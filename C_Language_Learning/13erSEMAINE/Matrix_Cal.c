#include <stdio.h>
#define N 3
float Det(float M[N][N])
{
    float det;
    det = M[0][0] * (M[1][1] * M[2][2] - M[1][2] * M[2][1]) - M[0][1] * (M[1][0] * M[2][2] - M[1][2] * M[2][0]) + M[0][2] * (M[1][0] * M[2][1] - M[1][1] * M[2][0]);
    return det;
}
float Astar(float M[3][3], int i, int j)
{
    float A_ij = M[(i + 1) % 3][(j + 1) % 3] * M[(i + 2) % 3][(j + 2) % 3] - M[(i + 1) % 3][(j + 2) % 3] * M[(i + 2) % 3][(j + 1) % 3];
    return A_ij;
}
int main()
{
    int i, j;
    float M[N][N] = {0}, MT[3][3] = {0};
    // float(*p)[N] = M;
    for (i = 0; i < N; i++)
    {
        for (j = 0; j < N; j++)
        {
            scanf("%f", &M[i][j]);
        }
    }
    // printf("%f", Det(M));
    /*determinant*/
    float det = Det(M);
    if (!det)
    {
        printf("0");
        return 0;
    }
    /*Transposition*/
    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 3; j++)
        {
            MT[i][j] = M[j][i];
        }
    }
    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 3; j++)
        {
            printf("%.2f ", MT[i][j] + Astar(MT, i, j) / det);
        }
        printf("\n");
    }
}