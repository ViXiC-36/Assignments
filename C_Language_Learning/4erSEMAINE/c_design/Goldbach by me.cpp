#include<stdio.h>
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
int main(void)
{
	int k,i;
	i=2;
	scanf("%d",&k);
	while(i<k-1)
	{
		int j=k-i;
		if(j<i)
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