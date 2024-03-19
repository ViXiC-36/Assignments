#include <stdio.h>
#include <stdlib.h>
int main()
{
    int n, sign, j, i, med;
    int *a;
    scanf("%d", &n);
    a = (int *)malloc(n * sizeof(int));
    scanf("%d", &sign);
    for (i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }

    switch (sign)
    { // selection sort
    case 1:
        for (i = 0; i < n - 1; i++)
        {
            for (j = i + 1; j < n; j++)
            {
                if (a[i] >= a[j])
                {
                    med = a[i];
                    a[i] = a[j];
                    a[j] = med;
                }
            }
        }
        for (i = 0; i < n; i++)
        {
            printf("%d ", a[i]);
        };
        break;
    case 0:
        for (i = 0; i < n - 1; i++)
        {
            for (j = i + 1; j < n; j++)
            {
                if (a[i] >= a[j])
                {
                    med = a[i];
                    a[i] = a[j];
                    a[j] = med;
                }
            }
        }
        for (i = n - 1; i > -1; i--)
        {
            printf("%d ", a[i]);
        };
        break;
    }
    printf("\n");

    switch (sign)
    { // bubble sort
    case 0:
        for (i = 0; i < n; i++)
        {
            for (j = 0; j < n - 1 - i; j++)
            {
                if (a[j] > a[j + 1])
                {
                    med = a[j];
                    a[j] = a[j + 1];
                    a[j + 1] = med;
                }
            }
            printf("%d ", a[n - i - 1]);
        };
        break;
    case 1:
        for (i = 0; i < n; i++)
        {
            for (j = 0; j < n - 1 - i; j++)
            {
                if (a[j] > a[j + 1])
                {
                    med = a[j];
                    a[j] = a[j + 1];
                    a[j + 1] = med;
                }
            }
        }
        for (i = 0; i < n; i++)
        {
            printf("%d ", a[i]);
        };
        break;
    }
    printf("\n");

    for (i = 0; i < n - 1; i++) // insertion sort
    {
        for (j = i + 1; j > 1; j--)
        {
            if (a[j] <= a[j - 1])
            {
                med = a[j - 1];
                a[j - 1] = a[j];
                a[j] = med;
            }
        }
    }
    switch (sign)
    {
    case 1:
        for (i = 0; i < n; i++)
        {
            printf("%d ", a[i]);
        };
        break;
    case 0:
        for (i = n - 1; i > -1; i--)
        {
            printf("%d ", a[i]);
        };
        break;
    }
    return 0;
}
