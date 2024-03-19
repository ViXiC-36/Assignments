#include <stdio.h>
int *weekday(int n)
{
    char *days[] = {"Mon.", "Tue.", "Wed.", "Thur.", "Fri.", "Sat.", "Sun."};
    if ((n < 1) || (n > 7))
        return NULL;
    return days[n - 1];
}
int main()
{
    int num;
    scanf("%d", &num);
    printf("%s\n", weekday(num));
    return 0;
}