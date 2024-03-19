#include <stdio.h>
int main()
{
    int hour, minute, second, day, month, year, i;
    long xs, xd, xy, feb_29_number;
    long mh = 0, mmin = 0, ms = 0, md = 1, mm = 1, my = 0;
    long year_to_day, month_to_day = 0;
    int months[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    scanf("%d:%d:%d", &hour, &minute, &second);
    scanf("%d.%d.%d", &day, &month, &year);
    // To transform the days;
    xy = year - 2000;
    feb_29_number = (xy / 4) - (xy / 100) + (xy / 400);
    if ((year >= 2000) && (month >= 3)) // 2000 is a leap year;
        feb_29_number += 1;
    if ((year >= 2004) && (month <= 2)) // leap year but it's not March yet;
        feb_29_number -= 1;
    year_to_day = xy * 365 + feb_29_number;
    for (i = 0; i < month - 1; i++)
    {
        month_to_day += months[i];
    }
    month_to_day += day - 1;
    xd = year_to_day + month_to_day;
    while (xd > 0)
    {
        xd -= 1;
        md += 1;
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
    // To transform the seconds;
    xs = hour * 3600 + minute * 60 + second;
    xs = (xs * 1000) / 864;
    mh = xs / 10000;
    mmin = (xs % 10000) / 100;
    ms = xs % 100;
    printf("%ld:%ld:%ld %ld.%ld.%ld", mh, mmin, ms, md, mm, my);
    return 0;
}