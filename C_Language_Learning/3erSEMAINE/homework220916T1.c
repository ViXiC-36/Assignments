#include <stdio.h>
int main()
{
    int row, i, j, k;
    scanf("%d", &row);

    if (row > 0 && row < 10)

        for (i = 1; i < row + 1; i++)
        {
            for (j = row - i + 1; j > 1; j = j - 1)
            {
                printf(" ");
            }

            for (j = i - 1; j > 0; j = j - 1)
            {
                printf("%d ", i);
            }

            printf("%d\n", i);
        }

    if (row > 0 && row < 10)

        for (i = row - 1; i > 0; i = i - 1)
        {
            for (k = row - i + 1; k > 1; k = k - 1)
            {
                printf(" ");
            }
            for (k = 0; k < i - 1; k++)
            {
                printf("%d ", i);
            }
            printf("%d\n", i);
        }
    else
        printf("N/A");
}