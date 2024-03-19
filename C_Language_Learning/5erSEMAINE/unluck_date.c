#include<stdio.h>
int main()
{
    int i,k,year,NYD,sum,date;//NYD presents "new year's day"
    int common[12]={31,28,31,30,31,30,31,31,30,31,30,31};
    int leap[12]={31,29,31,20,31,30,31,31,30,31,30,31};
    k=0,sum=13,date=(13-NYD)+7*k;
    scanf("%d %d",&year,&NYD);
    /*if((year%4==0&&year%100!=0)||year%400==0)//leap year
    {
        while(date<=366)
        {
            for(i=0;i<12;i++)
            {
                printf("%d\n",sum);
                if((date==sum)
                {
                    //printf("%d\n",i);
                    i++;
                }
                else
                {
                    i++;  
                }
                sum=sum+leap[i];
            }
            k++;
        }
    }
    else*/
    {
        while(date<=365)
        {
            
            for(i=0;i<12;i++)
            {
                if(date==sum)
                {
                    printf("%d\n",i+1);
                }
                sum+=common[i];
            }
            sum=13;
            k++;
        }
    }

}