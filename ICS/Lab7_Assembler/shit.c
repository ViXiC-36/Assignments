#include <stdio.h>

int main()
{
    char instruction[] = ".BLKW #-9\n";
    int labellength = 0;
    int value = 0;
    int digit = 0;
    char radix = instruction[6 + labellength];
    char data[7];
    for (int i = 0; instruction[7 + labellength + i] != 10; i++)
    {
        data[i] = instruction[i + 7 + labellength];
        data[i + 1] = 0;
    }
    for (int i = 0; data[i] != 0; i++)
        digit = i;
    if (radix == 'x')
    {
        int unit = 1;
        for (; (data[digit] != '-') && (digit >= 0); digit--, unit *= 16)
        {
            if (data[digit] <= '9')
                value += unit * (data[digit] - '0');
            if (data[digit] >= 'A')
                value += unit * (data[digit] - '7');
        }
        if (data[0] == '-')
            value = ~value + 1;
    }
    if (radix == '#')
    {
        int unit = 1;
        for (; (data[digit] != '-') && (digit >= 0); digit--, unit *= 10)
            value += unit * (data[digit] - '0');
        if (data[0] == '-')
            value = ~value + 1;
    }
}