#include <stdio.h>
#include <stdlib.h>

void calculate(char *s, int Start, int *Halt, int *result, char opcode)
{
    int result1 = 0, Halt1 = 0, result2 = 0, Halt2 = 0;
    if (s[Start] == '+' || s[Start] == '-' || s[Start] == '*' || s[Start] == '/')
        calculate(s, Start + 1, &Halt1, &result1, s[Start]);

    else if (s[Start] >= '0' && s[Start] <= '9')
    {
        result1 = s[Start] - '0';
        Halt1 = Start;
    }
    else
    {
        perror("INVALID INPUT");
        exit(1);
    }

    if (s[Halt1 + 1] == '+' || s[Halt1 + 1] == '-' || s[Halt1 + 1] == '*' || s[Halt1 + 1] == '/')
        calculate(s, Halt1 + 2, &Halt2, &result2, s[Halt1 + 1]);

    else if (s[Halt1 + 1] >= '0' && s[Halt1 + 1] <= '9')
    {
        result2 = s[Halt1 + 1] - '0';
        Halt2 = Halt1 + 1;
    }
    else
    {
        perror("INVALID INPUT");
        exit(1);
    }

    switch (opcode)
    {
    case '+':
        *result = result1 + result2;
        break;
    case '-':
        *result = result1 - result2;
        break;
    case '*':
        *result = result1 * result2;
        break;
    case '/':
        *result = result1 / result2;
        break;
    default:
        perror("INVALID INPUT");
        exit(1);
    }
}
int main()
{
    char s[100];
    int result = 0, Halt = 0;
    scanf("%s", s);
    calculate(s, 1, &Halt, &result, s[0]);
    printf("%d", result);
    return 0;
}
