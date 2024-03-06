#include<stdio.h>

int main ()
{
    int a = 1;
    int b = 2;
    int c = 3;
    a == 3 ? b : b |= 1;
    printf("%d%d%d", a, b, c);
}