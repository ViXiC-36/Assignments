#include<stdio.h>
int main()
{
    double n,abs;
    scanf("%lf",&n);
    if(n<0)
    {
        abs=-n;
    }
    else
    {
        abs=n;
    }
    printf("%lf",abs);
    return 0;
}