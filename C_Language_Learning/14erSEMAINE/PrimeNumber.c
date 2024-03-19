#include <stdio.h>
#include <math.h>
int IsPrime(long long n)
{
    long long i, flag = 0, j;
    j = sqrt(n);
    for (i = 2; i < j; i++)
        if (n % i == 0)
        {
            flag = 1;
            printf("Not a prime number.\n");
            break;
        }
    for (i = 2; i < j; i++)
    {
        if (n % i == 0)
            printf("It can be divided by %lld into %lld\n", i, n / i);
        else
            continue;
    }
    if (flag == 1)
        return 0;
    printf("Yes, it's prime.\n");
    return 1;
}
int main()
{
    long long i, j = 0, x;
    printf("Input a number and I will tell you if it's prime or not.\n");
    scanf("%lld", &x);
    for (i = x; i < x + 1; i++)
    {
        if (IsPrime(i) == 1)
        {
            j++;
            // printf("%6d", i);
            // if ((j != 0) && (j % 5 == 0))
            //     printf("\n");
        }
    }
    return 0;
}