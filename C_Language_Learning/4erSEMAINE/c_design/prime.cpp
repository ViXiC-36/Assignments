#include<stdio.h>
int main()
{
    int i,k;
    i=2;
    scanf("%d",&k);
    while(i<k)
    {
        if(k%i==0)
        {
          printf("%d is not a prime number\n",k);
          return 0;
        }
        else
        {
          i++;
        }
    }
    printf("%d is a prime number\n",k);
    return 0;
}


