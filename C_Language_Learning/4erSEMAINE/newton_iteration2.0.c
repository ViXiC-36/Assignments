#include <stdio.h>
#include <math.h>
int main()
{
    float a3, a2, a1, a0, e, x, low, high, delta, mid, x1;
    float fl, fh, fm;
    int i = 0;
    int c1 = 0;
    delta = 1;
    scanf("%f %f %f %f", &a3, &a2, &a1, &a0);
    scanf("%f", &e);
    scanf("%f", &x);             // newton_iteration
    scanf("%f %f", &low, &high); // dichotomy
    while (fabs(delta) >= e)
    {
        delta = (a3 * x * x * x + a2 * x * x + a1 * x + a0) / (3 * a3 * x * x + 2 * a2 * x + a1);
        x -= delta;
        i++;
    }
    printf("%f\n", x);
    printf("%d\n", i);

    while ((high - low) >= e)
    {
        mid = (low + high) / 2;
        fl = a3 * low * low * low + a2 * low * low + a1 * low + a0;
        fm = a3 * mid * mid * mid + a2 * mid * mid + a1 * mid + a0;
        fh = a3 * high * high * high + a2 * high * high + a1 * high + a0;
        c1++;
        if (fm * fl < 0)
        {
            high = mid;
            x1 = high;
        }
        else if (fm * fh < 0)
        {
            low = mid;
            x1 = high;
        }
        else
        {
            x1 = high;
            c1++;
            break;
        }
    }
    printf("%f\n", x1);
    printf("%d", c1);
    return 0;
}