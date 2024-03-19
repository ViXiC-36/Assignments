#include <stdio.h>
#include <math.h>
int PosNum(int x, int pos) // number of a particular position;
{
    int y;
    y = pow(10, pos);
    return (x % y / pow(10, pos - 1));
}
int main()
{
    char num[60] = {0};
    int a[60] = {0}, number[60] = {0};
    scanf("%s", num);
    // printf("%d", num[0] - 48);
    int length, i = 0, j, k, e = 1;
    // e is the number of satisfied products;
    while (i <= 60)
    {
        if (num[i + 1] == 0 && num[i + 2] == 0)
        {
            i += 1;
            break;
        }
        else
            i += 1;
    }
    length = i;
    // printf("%d", length);
    for (i = 0; i < length; i++)
    {
        number[i] = num[i] - '0';
    }
    int ones = 0, tens = 0, tmp;
    for (j = 2; j <= length; j++) // multipled by j;
    {
        for (i = length - 1; i >= 0; i--)
        {
            a[i] = number[i];
            a[i] = a[i] * j + tens;
            tens = a[i] / 10; 
            ones = PosNum(a[i], 1);
            a[i] = ones;
        }
        // Proofreading;
        int l = 0;
        for (i = 1; i < length; i++) // times of movement;
        {
            tmp = a[0];
            for (k = 0; k < length - 1; k++)
            {
                a[k] = a[k + 1];
            }
            a[length - 1] = tmp;   // movement done;
            if (a[0] == number[0]) // proofreading;
            {
                l += 1;
                for (k = 1; k < length; k++)
                {
                    if (a[k] == number[k])
                    {
                        l += 1;
                    }
                    else
                    {
                        l = 0;
                        break;
                    }
                }
            }
            if (l == length)
            {
                e += 1;
                break;
            }
            else
            {
                l = 0;
            }
        }
        if (i == length)
        {
            printf("0");
            break;
        }
    }
    if (e == length)
        printf("1");
    return 0;
}