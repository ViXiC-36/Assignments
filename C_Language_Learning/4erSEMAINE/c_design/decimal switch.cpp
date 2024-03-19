#include<stdio.h>
int main(void)
{
	 double k;
	 int data[32];
	 
	 int j;
	 scanf("%lf",&k);
     if(k<0)
     {
     	k=-k;
	    printf("-");
	 }
	 int kZ,i;
	 kZ=k;
	 if(kZ==0)
	 {
	 	printf("0");
	 }
	 double lil=k-kZ;
	 i=0;
	 while(kZ>0)
	 {
	 	j=kZ%2;
	 	kZ=kZ/2;
	 	data[i]=j;
	 	i++;
	 }
	 int m;
	 for(m=i-1;m>=0;m--)
	 {
	 	printf("%d",data[m]);
	 }
	 if(lil==0)
	 {
	 	return 0;
	 }
	 
	 printf(".");
	 int times=0;
	 while(lil!=1)
	 {
	 	
	 	lil=lil*2;
	 	if(lil>1)
	 	{
	 		printf("1");
	 		lil-=1;
	 		times++;
		}
		else if(lil<1)
		{
			printf("0");
			times++;			
		}
	 	if(times>=20)
	 	{
	 		break;
		}
		
	 }
	 if(times<20)
	 {
	 	printf("1");
	 }
	 
	 return 0;

}