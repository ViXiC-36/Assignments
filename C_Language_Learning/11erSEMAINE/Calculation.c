#include <stdio.h>
#include <math.h>
int main()
{
    int i, j, k, res, n, e = 0, flag = 0; // flag for the number of cal.;
    char input[100], fml[100];            // fml := abbr. for formula;
    for (i = 0; i < 100; i++)
    {
        fml[i] = 0;
    }
    gets(input);
    n = strlen(input);
    for (i = n - 1, j = 0; i >= 0; i--) // i for input, j for fml, k for temp;
    {
        if (input[i] >= '0' && input[i] <= '9')
        {
            for (k = 0; input[i] >= '0' && input[i] <= '9'; k++, i--)
            {
                e = pow(10, k);
                fml[j] += input[i] * e;
            }
            j++;
        }
        if (input[i] == '+')
        {
            fml[j] = '+';
            j++;
            flag++;
        }
        if (input[i] == '-')
        {
            fml[j] = '-';
            j++;
            flag++;
        }
        if (input[i] == '*')
        {
            fml[j] = '*';
            j++;
            flag++;
        }
        if (input[i] == '/')
        {
            fml[j] = '/';
            j++;
            flag++;
        }
        if (input[i] == '(')
        {
            fml[j] = '(';
            j++;
        }
        if (input[i] == ')')
        {
            fml[j] = ')';
            j++;
        }
    }
    n = j;
}