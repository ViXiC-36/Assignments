#include <stdio.h>
// 1~i-2不在杆上，i-1在杆上，i可装上或取下
#define N 12
char stat[N] = {};
int stathx[N / 4] = {};

int count = 0;
void down(int n);

void on(int n)
{
	if (n > 1)
		on(n - 1); // i-1装在杆上
	if (n > 2)
		down(n - 2); // i-2从杆上卸下

	// printf("%d: U\n",n);		//输出装上
	stat[N - n] = '0';
	count++;
	printf("%s\n", stat);

	// for (int i = 0; i < N / 4; i++)
	// {
	// 	int exp = 1;
	// 	for (int j = 0; j < 4; j++, exp *= 2)
	// 	{
	// 		stathx[i] += (stat[i * 4 + j] - '0') * exp;
	// 	}
	// 	printf("%d", stathx[i]);
	// }
	// printf("->");

	if (n > 2)
		on(n - 2); // i-2装在杆上
}

void down(int n)
{
	if (n > 2)
		down(n - 2); // i-2从杆上卸下
	// printf("%d: D\n",n);		//输出卸下
	stat[N - n] = '1';
	count++;
	printf("%s\n", stat);

	// for (int i = 0; i < N / 4; i++)
	// {
	// 	int exp = 1;
	// 	for (int j = 0; j < 4; j++, exp *= 2)
	// 	{
	// 		stathx[i] += (stat[i * 4 + j] - '0') * exp;
	// 	}
	// 	printf("%d", stathx[i]);
	// }
	// printf("->");

	if (n > 2)
		on(n - 2); // i-2装上杆上
	if (n > 1)
		down(n - 1); // i-1从杆上卸下
}

int main()
{
	for (int i = 0; i < N; i++)
	{
		stat[i] = '0';
	}
	for (int i = 0; i < N / 4; i++)
		stathx[i] = 0;

	// cin>>a[0]>>a[1];
	int n = 4;
	down(n);

	printf("[%d]", count);
	return 0;
}
