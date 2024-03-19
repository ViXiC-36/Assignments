#include<stdio.h>
#include<math.h>
int main()
{
    double e,i,j;
    j=100;
    int k=0;
    scanf("%lf",&e);
    
    for(k=1;j>=e;k=k+1)
    {
        i=(4.0/(8*k+1)-2.0/(8*k+4)-1.0/(8*k+5)-1.0/(8*k+6));
        j=i/pow(16,k);
    }    
    printf("%d",k-1);
}


