#include <stdio.h>
int main()
{
    char fml[100] = {0};
    int i = 0;
    scanf("%s", fml);
    while (i < 100)
    {
        if (fml[i] == '!')
        {
            if (((fml[i + 1] >= '0') && (fml[i + 1] <= '9')) || (fml[i + 1] == '!'))
            {
                i += 1;
            }
            else if ((fml[i + 1]) == '=')
            {
                if (i == 0)
                {
                    printf("0");
                    break;
                }
                else if ((fml[i - 1]) >= '0' && fml[i - 1] <= '9')
                {
                    i += 1;
                }
                else
                {
                    printf("0");
                    break;
                }
            }
        }
        else if ((fml[i] == '>') || (fml[i] == '<'))
        {
            if (i == 0)
            {
                printf("0");
                break;
            }
            else if ((fml[i + 1] == '!') || (fml[i] == '=') || (fml[i] == '0' || '9' || '8' || '7' || '6' || '5' || '4' || '3' || '2' || '1'))
            {
                i += 1;
            }
            else
            {
                printf("0");
                break;
            }
        }
        else if ((fml[i] >= '0') && (fml[i] <= '9'))
        {
            i += 1;
        }
        else if (fml[i] == '&')
        {
            if (fml[i + 1] == '&')
            {
                i += 2;
            }
            else if ((i == 0) || (fml[i + 2] == '|' || '&' || '\0'))
            {
                printf("0");
                break;
            }
            else
            {
                printf("0");
                break;
            }
        }
        else if (fml[i] == '|')
        {
            if (fml[i + 1] == '|')
            {
                i += 2;
            }
            else if ((i == 0) || (fml[i + 2] == '|' || '&' || '\0'))
            {
                printf("0");
                break;
            }
            else
            {
                printf("0");
                break;
            }
        }
        else if ((fml[i] == '+') || (fml[i] == '-') || (fml[i] == '*') || (fml[i] == '/'))
        {
            if (i == 0)
            {
                printf("0");
                break;
            }
            else if ((fml[i + 1] == '!') || (fml[i + 1] >= '0' && fml[i + 1] <= '9'))
            {
                i += 1;
            }
            else
            {
                printf("0");
                break;
            }
        }
        else if (fml[i] == '=')
        {
            if (i == 0)
            {
                printf("0");
                break;
            }
            else if ((fml[i - 1] == '<') || (fml[i] == '>') || (fml[i] == '=') || (fml[i] == '!'))
            {
                if ((fml[i + 1] == '!') || (fml[i] == '0' || '9' || '8' || '7' || '6' || '5' || '4' || '3' || '2' || '1'))
                {
                    i += 1;
                }
                else
                {
                    printf("0");
                    break;
                }
            }
            else if (fml[i + 1] == '=')
            {
                i += 2;
            }
            else
            {
                printf("0");
                break;
            }
        }
        else if (fml[i] == 0)
        {
            printf("1");
            break;
        }
    } // printf("%c",formula[i]);
    return 0;
}