#include<stdio.h>
int main()
{
    int n, i, j, k = 0;
    char crypt[200], input[200];
    for(i = 0; i < 200; i++)
    {
        crypt[i] = ' ';
        input[i] = ' ';
    }
    int a[200] = {0};
    scanf("%d", &n);
    for(i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }
    scanf("%d", &k);
    while( k != -1)
    {
        gets(input);
        for(i = 0; i < k; i++)
        {
            crypt[a[i] - 1] = input[i];
        }
        puts(code);
        scanf("%d", &k);
    }

}