#include <stdio.h>
#include <string.h>
int main()
{
    int i, offset = 0, n = 0, k, ll, l; // ll for str, l for s;
    char str[1000], s[1000];
    scanf("%s", str);
    scanf("%s", s);
    ll = strlen(str);
    l = strlen(s);
    /*Ajust the *s*/
    for (i = 0; i < l; i++)
    {
        s[ll - i - 1] = s[l - i - 1];
    }
    /*Proofreading & Shifts*/
    while (n < l)
    {
        if (offset > ll - l)
        {
            printf("%s", str);
            return 0;
        }
        n = 0;
        for (i = 0; i < l; i++)
        {
            if (s[ll - i - 1 - offset] == str[ll - i - 1 - offset])
            {
                n++;
            }
            else
            {
                for (k = 0; k < l; k++)
                {
                    s[ll - offset - l + k - 1] = s[ll - offset - l + k];
                }
                offset++;
                break;
            }
        }
    }
    /*Elimination*/
    for (i = 0; i < l; i++)
    {
        str[ll - offset - 1 - i] = ' ';
    }
    /*Output*/
    for (i = 0; i < ll; i++)
    {
        if (str[i] != ' ')
        {
            printf("%c", str[i]);
        }
    }
    return 0;
}