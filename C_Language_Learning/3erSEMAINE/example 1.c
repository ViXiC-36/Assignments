#include<stdio.h>
int main()
{
    float bmi, height;
    float  weight;

    scanf("%d",&weight);
    scanf("%f",&height);
    bmi=weight/height/height;
    printf("%f",bmi);
       }