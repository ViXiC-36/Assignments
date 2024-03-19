#include <stdio.h>
#include <math.h>
long factorial(int n)
{
    int i;
    long product = 1;
    for (i = 1; i < n + 1; i++)
    {
        product *= i;
    }
    return product;
}
int main()
{
    int m;
    scanf("%d", &m);
    m = factorial(m);
    printf("%d ", m);
    return 0;
    // int i, n, product;
    // product = 1;
    // scanf("%d", &n);
    // factorial(n);
    // printf("%l", "factorial(n)");

    // double k=3;
    // double i,j;
    // i=(4/(8*k+1)-2/(8*k+4)-1/(8*k+5)-1/(8*k+6));
    // j=i/pow(16,k);
    // printf("%lf",j);
    // int u, v;
    // scanf("%d %d",&u, &v );
    // printf("%5d %5d",u,v);
}