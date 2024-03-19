#include <stdio.h>
int main()
{
    int hour, minute, second, day, month, year, i;
    long xs, xd, xy, leap_year_number;
    long mh = 0, mmin = 0, ms = 0, md = 1, mm = 1, my = 0;
    long year_to_day, month_to_day = 0;
    int plain_year[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int leap_year[12] = {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    scanf("%d:%d:%d", &hour, &minute, &second);
    scanf("%d.%d.%d", &day, &month, &year);
    //To transform the days;
    xy = year - 2000;
    leap_year_number = (xy / 4) - ((xy / 100) - (xy / 400));
    year_to_day = xy * 365 + leap_year_number;
    if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0)
    {
        for (i = 0; i < month - 1; i++)
        {
            month_to_day += leap_year[i];
        }
        month_to_day += day - 1;
    }
    else
    {
        for (i = 0; i < month - 1; i++)
        {
            month_to_day += plain_year[i];
        }
        month_to_day += day - 1;
    }
    xd = year_to_day + month_to_day;
    while (xd > 0)
    {
        xd -= 1;
        mh += 8;
        mmin += 64;
        if (mmin >= 100)
        {
            mmin -= 100;
            mh += 1;
        }
        if (mh >= 10)
        {
            mh -= 10;
            md += 1;
        }
        if (md >= 100)
        {
            md -= 100;
            mm += 1;
        }
        if (mm >= 10)
        {
            mm -= 10;
            my += 1;
        }
    }
    //To transform the seconds;
    xs = hour * 3600 + minute * 60 + second;
    while (xs >= 100)
    {
        xs -= 100;
        mmin += 1;
        if (mmin >= 100)
        {
            mmin -= 100;
            mh += 1;
        }
        if (mh >= 10)
        {
            mh -= 10;
            md += 1;
        }
        if (md >= 100)
        {
            md -= 100;
            mm += 1;
        }
        if (mm >= 10)
        {
            mm -= 10;
            my += 1;
        }
    }
    printf("%ld:%ld:%ld %ld.%ld.%ld", mh, mmin, ms, md, mm, my);
    return 0;
}