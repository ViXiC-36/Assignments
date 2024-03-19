#include <stdio.h>
#include <stdlib.h>

#define bool char
#define true 1
#define false 0

#define MaxSize 1000

typedef int ElemType;

// 定义栈的结构
typedef struct SqStack
{
    ElemType data[MaxSize];
    int top;
} SqStack;

// 栈的初始化
bool InitStack(SqStack *S)
{
    S->top = -1;
    return true;
}

// 栈判空
bool Empty(SqStack S)
{
    if (S.top == -1)
        return true;
    else
        return false;
}

// 压栈
bool Push(SqStack *S, ElemType e)
{
    // 判断栈满的情况
    if (S->top == MaxSize - 1)
        return false;
    S->data[++S->top] = e;
    return true;
}

// 出栈
bool Pop(SqStack *S, ElemType *e)
{
    if (S->top == -1)
        return false;
    *e = S->data[S->top--];
    return true;
}

// 便利测试用
bool Print(SqStack S)
{
    for (int i = 0; i < S.top + 1; i++)
    {
        printf("%d ", S.data[i]);
    }
    return true;
}
/*中缀转后缀函数*/
void Change(SqStack *S,ElemType str[])
{
	int i=0;
	ElemType e;
	InitStack(S);
	while(str[i]!='\0')
	{
		while(isdigit(str[i])) 
		{/*过滤数字字符，直接输出，直到下一位不是数字字符打印空格跳出循环 */
			printf("%c",str[i++]);
			if(!isdigit(str[i]))
			{
				printf(" ");
			}
		}
		/*加减运算符优先级最低，如果栈顶元素为空则直接入栈，否则将栈中存储
		的运算符全部弹栈，如果遇到左括号则停止，将弹出的左括号从新压栈，因为左
		括号要和又括号匹配时弹出，这个后面单独讨论。弹出后将优先级低的运算符压入栈中*/
		if(str[i]=='+'||str[i]=='-')
		{
			if(!StackLength(S))
			{
				Push(S,str[i]);
			}
			else
			{
				do
				{
					Pop(S,&e);
					if(e=='(')
					{
						Push(S,e);
					}
					else
					{
						printf("%c ",e);
					}
				}while( StackLength(S) && e != '(' );
				
				Push(S,str[i]);
			}
		}
		/*当遇到右括号是，把括号里剩余的运算符弹出，直到匹配到左括号为止
		左括号只弹出不打印（右括号也不压栈）*/
		else if(str[i]==')')
		{
			Pop(S,&e);
			while(e!='(')
			{
				printf("%c ",e);
				Pop(S,&e);
			}
		}
		/*乘、除、左括号都是优先级高的，直接压栈*/
		else if(str[i]=='*'||str[i]=='/'||str[i]=='(')
		{
			Push(S,str[i]);
		}
		
		else if(str[i]=='\0')
		{
			break;
		}
		
		else
		{
			printf("\n输入格式错误！\n");
			return ;
		}
		i++;
	}
	/*最后把栈中剩余的运算符依次弹栈打印*/
	while(StackLength(S))
	{
		Pop(S,&e);
		printf("%c ",e);
	}
}



int main()
{
    // 定义和初始化栈
    SqStack S1, S2;
    InitStack(&S1);
    InitStack(&S2);
    int answer;

    // 输入字符串
    char str[1000];
    gets(str);

    char c = str[0];
    int i = 0;
    for (i = 0; str[i] != '\0'; i++)
    {
        c = str[i];
        int x, t;
        // printf("%d ",c);
        // 如果是数字，压入栈中
        if (str[i] <= '9' && str[i] >= '0')
        {
            t = 0;
            while (str[i] <= '9' && str[i] >= '0')
            {
                x = str[i] - 48;
                t = t * 10 + x;
                i++;
            }

            Push(&S1, t);
            i--;
        }
        // 如果是空格，跳过
        else if (c == ' ')
            continue;
        // 如果是运算符，进行计算操作
        else if (c == '+' || c == '-' || c == '*' || c == '/')
        {

            int m, p;
            Pop(&S1, &m);
            Pop(&S1, &p);

            if (c == '+')
            {
                answer = p + m;
            }
            else if (c == '-')
            {
                answer = p - m;
            }
            else if (c == '*')
            {
                answer = p * m;
            }
            else if (c == '/')
            {
                answer = p / m;
            }
            Push(&S1, answer);
        }
    }

    printf("%d", answer);

    return 0;
}
