#include <stdio.h>
int main()
{
    char c, i;
    // for (i = 0; i < 5; i++)
    // {
    //     c=getchar();
    //     putchar(c-'a'+'A');
    // }
    // return 0;
    scanf("%c", &c);
    if (c == '+' || '-' || '*' || '/')
        printf("okay");
    return 0;
}