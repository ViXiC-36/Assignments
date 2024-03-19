#include<stdio.h>
int main()
{
    char s[10000] = {'1'}, ss[10000];
    int i, j, n, e = 1;// e represents the times of repeatition;
    scanf("%d", &n);
    if(n == 0)
    {
        printf("1");
        return 0;
    }
    while(n > 0)
    {
        /*Reproduce the next*/
        for (i = 0, j = 0; s[i] != 0 ; i++)
        {
            if(s[i] == s[i + 1])
            {
                e++;
            }
            else
            {
                ss[j] = e + '0';
                ss[j + 1] = s[i];
                j += 2;
                e = 1;
            }
        }
        ss[j] = 0;
        /*Update*/
        for(i = 0; ss[i] != 0; i++)
        {
            s[i] = ss[i];
        }
        s[i] = 0;
        n--;
    }
    printf("%s", s);
    return 0;
}