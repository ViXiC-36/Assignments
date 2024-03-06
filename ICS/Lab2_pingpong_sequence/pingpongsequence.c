#include<stdio.h>
int main ()
{
    int res = 3;
    int sign = 1;
    printf(" 1    3 | ");
    for (int i = 2; i < 40; i++)
    {
        res = 2 * res;
        (sign) ? (res += 2) : (res -= 2);
        res %= 4096;
        printf("%2d %4d | ", i, res);
        if (i % 10 == 0)
            printf("\n");
        if ((res % 8 == 0) || (res % 10 == 8))
            sign = !sign;
    }
    return 0;
}