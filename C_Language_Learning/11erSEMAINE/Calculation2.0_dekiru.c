#include <stdio.h>
#include <math.h>
#include <string.h>
#define ADD 2100000001
#define SUB 2100000002
#define MUL 2100000003
#define DIV 2100000004
#define LHB 2100000006
#define RHB 2100000007
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
int main()
{
    int i, j, k, n, e = 0; // flag = 0 // flag for the number of cal.;
    char input[100];
    int fml0[100] = {0}, fml[100] = {0}; // fml := formula;
    gets(input);
    n = strlen(input);
    /*Format the formula*/
    for (i = n - 1, j = 0; i >= 0; i--) // i for input, j for fml, k for temp;
    {
        if (input[i] >= '0' && input[i] <= '9')
        {
            for (k = 0; input[i] >= '0' && input[i] <= '9'; k++, i--)
            {
                e = pow(10, k);
                fml0[j] += (input[i] - '0') * e;
            }
            j++;
        }
        if (input[i] == '+')
        {
            fml0[j] = ADD; // represents '+';
            j++;
            // flag++;
        }
        if (input[i] == '-')
        {
            // if (input[i - 1] == '(')
            // {
            //     fml[j - 1] = -(fml[j - 1]);
            // }
            // else if ((input[i - 1] == ' ') && (input[i - 2] == '('))
            // {
            //     fml[j - 1] = -(fml[j - 1]);
            // }
            // else
            // {
            fml0[j] = SUB;
            j++;
            // flag++;
            // }
        }
        if (input[i] == '*')
        {
            fml0[j] = MUL;
            j++;
            // flag++;
        }
        if (input[i] == '/')
        {
            fml0[j] = DIV;
            j++;
            // flag++;
        }
        if (input[i] == '(')
        {
            fml0[j] = LHB;
            j++;
        }
        if (input[i] == ')')
        {
            fml0[j] = RHB;
            j++;
        }
    }
    n = j;
    for (i = 0; i < n; i++) // ajust the order;
    {
        fml[i] = fml0[n - i - 1];
    }
    /*Turn into reverse polish notation*/
    int stack[100] = {0}, pfml[100] = {0};
    int num_of_brackets_pairs = 0;
    for (i = 0, j = 0, k = 0; j < n; j++) // fml-j, pfml-i, stack-k;
    {
        if (fml[j] == LHB) //(:push
        {
            stack[k] = LHB;
            k++;
            num_of_brackets_pairs++;
        }
        else if (fml[j] == RHB) //):pop till meeting'(' then eliminate both
        {
            while (stack[k - 1] != LHB)
            {
                pfml[i] = stack[k - 1];
                i++;
                k--;
            }
            k--;
        }
        else if ((fml[j] == ADD) || (fml[j] == SUB)) //+ & - : pop till meeting ( or END and push itself
        {
            while ((k > 0) && (stack[k - 1] != LHB))
            {
                pfml[i] = stack[k - 1]; // pop
                i++;
                k--;
            }
            stack[k] = fml[j]; // push itself
            k++;
        }
        else if ((fml[j] == MUL) || (fml[j] == DIV)) //* & / :
        {
            while ((k > 0) && (stack[k - 1] != LHB)) // till meeting ( or END
            {
                if ((stack[k - 1] == MUL) || (stack[k - 1] == DIV)) // pop when meeting * or /
                {
                    pfml[i] = stack[k - 1]; // pop
                    i++;
                    k--;
                }
                else
                {
                    break;
                }
            }
            stack[k] = fml[j]; // push itself
            k++;
        }
        else // numbers pop
        {
            pfml[i] = fml[j];
            i++;
        }
    }
    k--;
    while (k >= 0) // pop all the rests in the stack
    {
        pfml[i] = stack[k];
        i++;
        k--;
    }
    n -= (2 * num_of_brackets_pairs);
    /*Calculation*/
    for (i = 0, k = 0; i < n; i++)
    {
        if ((pfml[i] >= ADD) && (pfml[i] <= DIV))
        {
            stack[k - 2] = Cal(stack[k - 2], pfml[i], stack[k - 1]);
            // flag--;
            k--;
        }
        else
        {
            stack[k] = pfml[i];
            k++;
        }
    }
    printf("%d", stack[0]);
}