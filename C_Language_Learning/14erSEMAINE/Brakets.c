#include <stdio.h>
#include <string.h>
int main()
{
    int i, l = 0, r = 0, n, pos_l = 0, pos_r = 0;
    char str[100];
    scanf("%s", str);
    n = strlen(str);
    for (i = 0; i < n; i++)
    {
        if (str[i] == '(')
        {
            l++;
            pos_l = i;
        }
        if (str[i] == ')')
        {
            r++;
            pos_r = i;
        }
    }
    if (l != r)
    {
        printf("0");
        return 0;
    }
    if (pos_l < pos_r)
    {
        printf("1");
        return 0;
    }
    else
    {
        printf("0");
        return 0;
    }
}