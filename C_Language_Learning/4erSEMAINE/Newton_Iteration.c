#include<stdio.h>
#include<math.h>
int main()
{
    float a3,a2,a1,a0,e,x,low,high,delta;
    int i;
    delta=1;
    scanf("%f %f %f %f",&a3,&a2,&a1,&a0);
    scanf("%f",&e);
    scanf("%f",&x);
    for(i=0;delta>e;i++)
    {
        delta=(a3*x*x*x+a2*x*x+a1*x+a0)/(3*a3*x*x+2*a2*x+a1);
        if(delta<0)
        {
            delta=-delta;
        }
        x=x-delta;
    }
    printf("%f\n",x);
    printf("%d",i);
    return 0;
}