#include <stdio.h>
void swap(int *x, int *y)
{
    int t;
    t = *x;
    *x = *y;
    *y = t;
}
int main()
{
    int a = 3, b = 5;
    swap(&a, &b);
    printf("%d %d", a, b);
    return 0;
}

