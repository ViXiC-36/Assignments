#include <stdio.h>
#include <math.h>
int main()
{
    double e, i, j;
    j = 100;
    double k = 0;
    scanf("%lf", &e);

    for (k = 0; j >= e; k = k + 1)
    {
        i = (4 / (8 * k + 1) - 2 / (8 * k + 4) - 1 / (8 * k + 5) - 1 / (8 * 6));
        j = i / pow(16, k);
    }
    printf("%lf\n", k);
    printf("%lf", j);
}
