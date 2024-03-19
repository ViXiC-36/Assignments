#include <stdio.h>
#include <stdlib.h>
int main()
{
    int n, i, j;
    float x, medw, medp, medv, vol; // x:residual, vol:packed,
    vol = 0;
    scanf("%d", &n);
    scanf("%f", &x);
    float weight[n], price[n], value[n];
    for (i = 0; i < n; i++)
    {
        scanf("%f %f", &weight[i], &price[i]);
        value[i] = price[i] / weight[i];
    }
    for (i = 0; i < n - 1; i++) // sort up
    {
        for (j = i + 1; j > 0; j--)
        {
            if (value[j - 1] >= value[j])
            {
                medv = value[j - 1];
                medp = price[j - 1];
                medw = weight[j - 1];
                value[j - 1] = value[j];
                price[j - 1] = price[j];
                weight[j - 1] = weight[j];
                value[j] = medv;
                price[j] = medp;
                weight[j] = medw;
            }
        }
    }
    for (i = n - 1; i > -1; i--)
    {
        if (x - weight[i] >= 0)
        {
            vol += price[i];
            x -= weight[i];
        }
        else
        {
            vol += (value[i] * x);
            x = 0;
            break;
        }
    }
    printf("%g", vol);
    return 0;
}