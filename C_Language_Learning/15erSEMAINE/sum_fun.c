#include<stdio.h>
int sumsuru (int *a)
{
    int i, n;
    for (i = 0, n = 0; i < 10; i++)
    {
        n += *(a + i);
    }
    return n;
}
int main ()
{
    int p[10];
    int i;
    for (i = 0; i < 10; i++)
    {
        scanf("%d", &p[i]);
    }
    int sum = 0;
    sum = sumsuru(p);
    printf("%d", sum);
    return 0;
}