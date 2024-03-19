#include <stdio.h>
int main()
{
    int n, a, k;
    scanf("%d", &n);
    if (n % 2 == 1)
    {
        a = n * n - n + 1;
        k = n;
    }
    else
    {
        k = 2;
        a = ((n * n * n) / 2) - 1;
    }
    printf("%d %d", a, k);
    return 0;
}