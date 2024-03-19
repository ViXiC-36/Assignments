#include <stdio.h>
#include <math.h>
int LENGTH(int x)
{
    int i = 0, inte = 9;
    while (inte != 0)
    {
        i += 1;
        inte = x / (pow(10, i));
    }
    return i;
}
int PosNum(int x, int pos) // number of a particular position;
{
    int y;
    y = pow(10, pos);
    return (x % y / pow(10, pos - 1));
}
int main()
{
    long p, q, r, dec_p = 0, dec_q = 0, dec_r = 0;
    int i, j, max, e, B = 2, length_p, length_q, length_r; // e means exponent;
    int c[21] = {0};
    scanf("%ld %ld %ld", &p, &q, &r);
    length_p = LENGTH(p);
    length_q = LENGTH(q);
    length_r = LENGTH(r);

    for (i = 0, j = 1; j < length_p + 1; i++, j++)
    {
        c[i] = PosNum(p, j);
    }
    for (j = 1; j < length_q + 1; i++, j++)
    {
        c[i] = PosNum(q, j);
    }
    for (j = 1; j < length_r + 1; i++, j++)
    {
        c[i] = PosNum(r, j);
    }
    max = c[0];
    for (j = 0; j < 20; j++)
    {
        if (max < c[j + 1])
        {
            max = c[j + 1];
        }
    }
    // The greatest positioon number obtained;
    for (B = max + 1; B <= 16; B++)
    {
        dec_p = 0, dec_q = 0, dec_r = 0;
        for (i = 0, j = 0; j < length_p; j++, i++)
        {
            e = pow(B, j);
            dec_p += c[i] * e;
        }
        for (j = 0; j < length_q; j++, i++)
        {
            e = pow(B, j);
            dec_q += c[i] * e;
        }
        for (j = 0; j < length_r; j++, i++)
        {
            e = pow(B, j);
            dec_r += c[i] * e;
        }
        if (dec_p * dec_q == dec_r)
        {
            printf("%d", B);
            break;
        }
    }
    if (B > 16)
        printf("0");
}