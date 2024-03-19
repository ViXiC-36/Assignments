#include <stdio.h>
#include <string.h>
int main()
{
    int i, j, n;
    char str[1000];
    char *p0 = NULL; // initialization;
    gets(str);
    n = strlen(str);
    for (p0 = str, i = 0, j = 0; i < n; i++) // obtain the address;
    {
        if ((str[i] >= 'a') && (str[i] <= 'z'))
        {
            *(p0 + j) = str[i];
            // printf("%c\n", *(p0 + j));
            j++;
        }
        if ((str[i] >= 'A') && (str[i] <= 'Z'))
        {
            *(p0 + j) = str[i] - 'A' + 'a';
            // printf("%c\n", *(p0 + j));
            j++;
        }
    }
    n = j;
    for (i = 0; i < (n + 1) / 2; i++)
    {
        if (*(p0 + i) != *(p0 + n - 1 - i))
        {
            printf("0");
            return 0;
        }
    }
    printf("1");
    return 0;
}