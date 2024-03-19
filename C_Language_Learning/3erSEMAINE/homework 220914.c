#include <stdio.h>
int main()
{
    double r1;
    double r2;
    double r3;
    double height;
    double phi, C, s, S, V, volume;

    phi = 3.14000;

    scanf("%lf", &r1);
    scanf("%lf", &r2);
    scanf("%lf", &r3);
    scanf("%lf", &height);

    C = 2 * phi * r1;
    printf("%.5f\n", C);
    s = phi * r1 * r1;
    printf("%.5f\n", s);

    S = 4 * phi * r2 * r2;
    printf("%.5f\n", S);
    V = 4 * phi * r2 * r2 * r2 / 3;
    printf("%.5f\n", V);

    volume = phi * r3 * r3 * height;
    printf("%.5f\n", volume);
}