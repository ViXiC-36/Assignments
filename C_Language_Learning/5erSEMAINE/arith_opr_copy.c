#include<stdio.h>
#include<math.h>
#include<time.h>
int main()
{
	char op[4]={'+', '-', '*', '/'};
	int calculate(int x,int y,int op);
	int s;    //定义运算后得到的结果
	switch(op)  //判断进行哪种运算
	{
	case 0:	
		s=x+y;
		
		break;
	case 1:
		s=x-y;
		
		break;
	case 2:
		s=x*y;
		
		break;
	case 3: 
		if(y!=0)
			s=x/y;
		
		break;
	}
	return s;  //返回得到的计算结果
}
 
	int cal(int a, int b, int c, int d, int e, int op1, int op2, int op3, int op4)
	{
			int result1, result2, result3, result4;
			result1=calculate(a,b,op1);
			result2=calculate(result1,c,op2);
			result3=calculate(result2,d,op3);
			result4=calculate(result3,e,op4);
			return result4;
	}
	int main()
{
 
int a, b, c, d, e, answer,op1, op2,op3,op4;
scanf("%d %d %d %d %d %d", &a, &b, &c, &d, &e, &answer);
	for(op1=0;op1<4;op1++)
		{
			for(op2=0;op2<4;op2++)
			{
				for(op3=0;op3<4;op3++)
				{
					for(op4=0;op4<4;op4++)
					{
						if(cal(a,b,c,d,e,op1,op2,op3,op4)==answer)
						{
							
							printf("%c %c %c %c", op[op1], op[op2], op[op3],op[op4]);
							
						}
						
					if(cal(a,b,c,d,e,op1,op2,op3,op4)==answer)
					break;	
					}
				if(cal(a,b,c,d,e,op1,op2,op3,op4)==answer)
				break;
				}
			if(cal(a,b,c,d,e,op1,op2,op3,op4)==answer)
			break;		
			}
		if(cal(a,b,c,d,e,op1,op2,op3,op4)==answer)
		break;
		} 
		if(cal(a,b,c,d,e,op1,op2,op3,op4)!=answer)
		printf("No solution");
	
	return 0;
}
