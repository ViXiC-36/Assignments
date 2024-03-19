#include <stdio.h>
int main()
{
    int i, year, NYD, sum, date, insurance; // NYD presents "new year's day"
    int common[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int leap[12] = {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    sum = 13;
    insurance = 0;
    scanf("%d %d", &year, &NYD);
    date = (13 - NYD);
    if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0) // leap year
    {
        while (date < 360)
        {
            for (i = 0; i < 12; i++)
            {
                if (date == sum)
                {
                    printf("%d\n", i + 1);
                    insurance += 1;
                }
                sum = sum + leap[i];
            }
            sum = 13;
            date += 7;
        }
    }
    else
    {
        while (date <= 361) // common year
        {
            for (i = 0; i < 12; i++)
            {
                if (date == sum)
                {
                    printf("%d\n", i + 1);
                    insurance += 1;
                }
                sum += common[i];
            }
            sum = 13;
            date += 7;
        }
    }
    if (insurance == 0)
    {
        printf("Luck");
    }
    return 0;
}