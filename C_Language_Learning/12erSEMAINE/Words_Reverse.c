#include <stdio.h>
#include <string.h>
int main()
{
    int i, j, n, flag = 0;
    char str[100], strR[100];
    gets(str);
    n = strlen(str);
    char *p0 = str;
    /*flag := the number of spaces*/
    for (i = 0; i < n; i++)
    {
        if (*(p0 + i) == ' ')
            flag++;
    }
    /*Totally reverse*/
    char *p = strR;
    for (i = 0; i < n; i++)
    {
        *(p + i) = str[n - i - 1];
    }
    /*output*/
    for (i = 0; flag; i++)
    {
        if (*(p + i + 1) == ' ')
        {
            for (j = 0; (i - j >= 0) && (*(p + i - j) != ' '); j++)
            {
                printf("%c", *(p + i - j));
            }
            i += 1;
            printf(" ");
            flag--;
        }
    }
    for (i = 0; *(p + n - i - 1) != ' '; i++)
        printf("%c", *(p + n - i - 1));
    return 0;
}