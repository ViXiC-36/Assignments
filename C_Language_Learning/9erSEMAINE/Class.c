#include<stdio.h>
float average(float array[], int n)
{
    int i;
    float aver, sum = array[0];
    for (i = 1; i < n; i++)
    {
        sum += array[i];
    }
    aver = sum / n;
    return aver;
}
int main()
{
    float score_1[10] = {12 ,34, 432, 2, 53, 532, 32, 5, 3, 222};
    printf("aver...%5.6lf\n", average(score_1, 10));
}