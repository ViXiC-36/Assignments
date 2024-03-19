#include <stdio.h>
int main()
{
    int i, j;
    for (i = 1; i <= 256; i++)
    {
        for (j = 1; j <= 128; j++)
            printf("%4d", i / 2 + 1);
        j = 1;
        printf("\n");
    }
    return 0;
}