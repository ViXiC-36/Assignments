#include <stdio.h>
int main()
{
    int ajustment;
    struct time
    {
        int h;
        int m;
        int s;
    } t0;
    scanf("%d %d %d", &t0.h, &t0.m, &t0.s);
    scanf("%d", &ajustment);
    t0.s += ajustment;
    while ((t0.s < 0) || (t0.s >= 60))
    {
        if (t0.s < 0)
        {
            t0.s += 60;
            t0.m -= 1;
            if (t0.m < 0)
            {
                t0.m += 60;
                t0.h -= 1;
                if (t0.h < 0)
                {
                    t0.h += 24;
                }
            }
        }
        else if (t0.s >= 60)
        {
            t0.s -= 60;
            t0.m += 1;
            if (t0.m >= 60)
            {
                t0.m -= 60;
                t0.h += 1;
                if (t0.h >= 24)
                {
                    t0.h -= 24;
                }
            }
        }
    }
    printf("%d %d %d", t0.h, t0.m, t0.s);
}