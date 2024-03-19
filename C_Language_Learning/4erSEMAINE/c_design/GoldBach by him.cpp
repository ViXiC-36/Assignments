#include<stdio.h>
int main()
{
    int k;
    int prime(int);   //The 1st int for output and the 2nd for input.
    scanf("%d",&k);
    int i=2;
    while(i<k)
    {
       int j=k-i;
       if(i>j)
       {
	     break;
	   }
	   if((prime(i)==1)&&(prime(j)==1))
	   {
	     printf("%d=%d+%d\n",k,i,j);
	     i++;
	   }
	   else
	   {
	   	 i++;
	   }	
	}
	return 0;
}
int prime(int m)
{
    int i;
    i=2;
    while(i<m)
    {
        if(m%i==0)
        {
          return 0;
        }
        else
        {
          i++;
        }
    }
    return 1;
}