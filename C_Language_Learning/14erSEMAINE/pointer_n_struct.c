#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main ()
{
    struct student
    {
        long lnum;
        char stuname[20];
        char stugender;
        float score;
    };
    struct student stu1;
    struct student *ps;
    stu1.lnum = 22111599;
    strcpy(stu1.stuname, "Vicky Yang");
    stu1.stugender = 'N';
    stu1.score = 78.5;

    ps = &stu1;

    printf("%s\nNo.%ld\n%c\n%.2f\n", ps->stuname, ps->lnum, ps->stugender, ps->score);
    printf("%s\nNo.%ld\n%c\n%.2f\n", (*ps).stuname, (*ps).lnum, (*ps).stugender, (*ps).score);
}