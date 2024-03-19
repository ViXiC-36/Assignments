#include <stdio.h>
#include <string.h>
char str[100] = {0};
int Cal(int a, int opr, int b)
{
    int r = 1;
    switch (opr)
    {
    case ADD:
        r = a + b;
        break;
    case SUB:
        r = a - b;
        break;
    case MUL:
        r = a * b;
        break;
    case DIV:
        r = a / b;
        break;
    }
    return r;
}
int f()
{
    printf();
    f();
    printf(" ");
    f();
    printf();
}
int main()
{

    gets(str);
    f()

    // for (int i = 0; i < n; i++)
    // {
    //     if((str[i] <= '0') || (str[i >= '9']))
    //     {
    //         f();
    //     }
    // }
}