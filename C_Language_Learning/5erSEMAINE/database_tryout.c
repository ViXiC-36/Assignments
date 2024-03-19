#include<stdio.h>
int main()
{
    int data[12]={1,3,5,7,9,11,13,15,17,19,21,23};
    int i,sum;
    for(i=0;i<12;i++)
    {
        sum+=data[i];
        printf("%d ",data[i]);
        printf("%d \n",sum);
    }
    return 0;
}