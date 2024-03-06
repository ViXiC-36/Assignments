#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define precision 200
#define max_length_parameter 50

char *Add(char *a_original, char *b_original, int aIsNegative) // a and b are in char form!!!
{
    /*delete the end mark(0) in the strings and fill 0s in the rest*/
    int i, j, k;
    for (i = 0; (*(a_original + i) != 0) && (i < 219); i++)
        continue;
    a_original[i] = '0';
    for (i = 0; (b_original[i] != 0) && (i < 219); i++)
        continue;
    b_original[i] = '0';
    /*Find the location odf the dot & Align the two numbers*/
    int a_loc_of_dot, b_loc_of_dot;
    int a_unaligned[220] = {0}, b_unaligned[220] = {0};

    for (i = 0; i < 220; i++)
        a_unaligned[i] = a_original[i] - '0'; // copy the number string without changing its contents
    for (i = 0; i < 220; i++)
        b_unaligned[i] = b_original[i] - '0'; // copy the number string without changing its contents

    for (i = 0; (i < 219) && (a_unaligned[i] != -3); i++)
        continue;
    a_unaligned[i] = 0;
    for (i = 0; (i < 219) && (b_unaligned[i] != -3); i++)
        continue;
    b_unaligned[i] = 0; // delete the '-'

    for (i = 0, a_loc_of_dot = 0; a_unaligned[i] != -2; i++) // the ASCII value of '.' is 46, '.' - '0' = -2
        a_loc_of_dot++;                                      // the dot is at the (a_loc_of_dot)th digit's right
    for (i = 0, b_loc_of_dot = 0; b_unaligned[i] != -2; i++)
        b_loc_of_dot++; // the dot is at the (b_loc_of_dot)th digit's right
    for (i = a_loc_of_dot; i - a_loc_of_dot < precision; i++)
        a_unaligned[i] = a_unaligned[i + 1];
    for (i = b_loc_of_dot; i - b_loc_of_dot < precision; i++)
        b_unaligned[i] = b_unaligned[i + 1];
    int loc_dot = a_loc_of_dot > b_loc_of_dot ? a_loc_of_dot : b_loc_of_dot;
    int a[220] = {0}, b[220] = {0};
    for (i = 0; i <= loc_dot - a_loc_of_dot; i++) // place one more digit position at the very first for possible carry
        a[i] = 0;                                 // make two numbers align
    for (j = 0; i <= precision + loc_dot; i++, j++)
        a[i] = a_unaligned[j];
    for (i = 0; i <= loc_dot - b_loc_of_dot; i++) // place one more digit position at the very first for possible carry
        b[i] = 0;                                 // make two numbers align
    for (j = 0; i <= precision + loc_dot; i++, j++)
        b[i] = b_unaligned[j];

    /*Operate Addition*/
    int sum[220] = {0};
    for (i = 0; i < precision + loc_dot + 1; i++)
        sum[i] = a[i] + b[i];
    for (i = precision + loc_dot; i > 0; i--) // process the carries
        if (sum[i] >= 10)
        {
            sum[i] %= 10;
            sum[i - 1] += 1;
        }

    /*save & output*/
    char *result = (char *)malloc(220 * sizeof(char));
    j = 0;
    // this whole function is to calculate the sum of the absolute values of the 2 numbers
    if (aIsNegative == 1)
    {
        result[0] = '-'; // print the negative sign
        j++;
    }
    for (i = 0; i < 5; i++)
        if (sum[i] != 0)
            break;
    // The prepared first digit has not been used
    for (k = j; i <= loc_dot + j; i++, k++) // j for result[]
        result[k] = sum[i] + '0';
    result[k] = '.';
    for (k++; i - loc_dot - j <= precision; i++, k++)
        result[k] = sum[i] + '0';
    // now the standard form is saved in the result[]

    for (i = 0, j = 0; j <= precision; i++, j++)
    {
        if (result[i] == '.')
            j = 0;
        printf("%c", result[i]);
    }
    printf("\n");
    char *p = result;
    return p;
}

char *Sub(char *a_original, char *b_original, int aIsNegative, int bIsNegative) // a and b are in char form!!!
{
    /*delete the end mark(0) in the strings and fill 0s in the rest*/
    int i, j;
    for (i = 0; (*(a_original + i) != 0) && (i < 219); i++)
        continue;
    a_original[i] = '0';
    for (i = 0; (b_original[i] != 0) && (i < 219); i++)
        continue;
    b_original[i] = '0';
    /*Find the location odf the dot & Align the two numbers*/
    int a_loc_of_dot, b_loc_of_dot;
    int a_unaligned[220] = {0}, b_unaligned[220] = {0};

    for (i = 0; i < 220; i++)
        a_unaligned[i] = a_original[i] - '0'; // copy the number string without changing its contents
    for (i = 0; i < 220; i++)
        b_unaligned[i] = b_original[i] - '0'; // copy the number string without changing its contents

    for (i = 0; (i < 219) && (a_unaligned[i] != -3); i++)
        continue;
    a_unaligned[i] = 0;
    for (i = 0; (i < 219) && (b_unaligned[i] != -3); i++)
        continue;
    b_unaligned[i] = 0; // delete the '-'

    for (i = 0, a_loc_of_dot = 0; a_unaligned[i] != -2; i++) // the ASCII value of '.' is 46, '.' - '0' = -2
        a_loc_of_dot++;                                      // the dot is at the (a_loc_of_dot)th digit's right
    for (i = 0, b_loc_of_dot = 0; b_unaligned[i] != -2; i++)
        b_loc_of_dot++; // the dot is at the (b_loc_of_dot)th digit's right
    for (i = a_loc_of_dot; i - a_loc_of_dot < precision; i++)
        a_unaligned[i] = a_unaligned[i + 1];
    for (i = b_loc_of_dot; i - b_loc_of_dot < precision; i++)
        b_unaligned[i] = b_unaligned[i + 1];
    int loc_dot = a_loc_of_dot > b_loc_of_dot ? a_loc_of_dot : b_loc_of_dot;
    int a[220] = {0}, b[220] = {0};
    for (i = 0; i < loc_dot - a_loc_of_dot; i++)
        a[i] = 0; // make two numbers align
    for (j = 0; i < precision + loc_dot; i++, j++)
        a[i] = a_unaligned[j];
    for (i = 0; i < loc_dot - b_loc_of_dot; i++)
        b[i] = 0; // make two numbers align
    for (j = 0; i < precision + loc_dot; i++, j++)
        b[i] = b_unaligned[j];

    /*Find the greater number as the subtrahend*/
    int subtrahend[220] = {0}, minuend[220] = {0}; // subtrahend - minuend = difference
    int digit_difference = 0;
    int INVERTOR = 0; // invertor means fan3xiang4qi4_c
    i = 0;
    while ((digit_difference == 0) && (i < precision + loc_dot))
    {
        digit_difference = a[i] - b[i];
        i++;
    }
    if (i == precision + loc_dot) // th etwo numbers are exactly the same!!
    {
        printf("0");
        return NULL;
    }
    if (digit_difference > 0)
        for (i = 0; i < precision; i++)
        {
            subtrahend[i] = a[i];
            minuend[i] = b[i];
        }
    else
        for (INVERTOR++, i = 0; i < precision; i++) // invertor turns to 1 when abs(b) > abs(a)
        {
            subtrahend[i] = b[i];
            minuend[i] = a[i];
        }

    /*Operate the subtraction*/
    int difference[220] = {0};
    for (i = 0; i < precision + loc_dot; i++) // sabusutorakuto mashou_j!
        difference[i] = subtrahend[i] - minuend[i];
    for (i = 219; i > 0; i--)
        if (difference[i] < 0) // compensate the carries
        {
            difference[i] += 10;
            difference[i - 1] -= 1;
        }

    /*Save & Output*/
    char *result = (char *)malloc(220 * sizeof(char));
    j = 0;
    // this whole function is to calculate the difference of the absolute values of the 2 numbers
    if ((aIsNegative == 0) && (bIsNegative == 0)) // a - b kara_j
        if (INVERTOR == 1)                        // e.g a = +1, b = +2
        {
            result[0] = '-';
            j++;
        }
    if ((aIsNegative == 1) && (bIsNegative == 1)) // a-b kara_j
        if (INVERTOR == 0)                        // e.g a = -5, b = -2
        {
            result[0] = '-';
            j++;
        }
    if ((aIsNegative == 0) && (bIsNegative == 1)) // a+b kara_j
        if (INVERTOR == 1)                        // e.g a = +2, b = -5
        {
            result[0] = '-';
            j++;
        }
    if ((aIsNegative == 1) && (bIsNegative == 0)) // a+b kara_j
        if (INVERTOR == 0)                        // e.g a = -6, b = +2
        {
            result[0] = '-';
            j++;
        }

    for (i = j; i < loc_dot + j; i++)
        result[i] = difference[i - j] + '0'; // save the integer part
    result[i] = '.';                         // save the dot
    for (i++; i - loc_dot - j - 1 < precision; i++)
        result[i] = difference[i - 1 - j] + '0'; // save the decimal part, the dot takes one more room

    if ((result[0] == '0') && (result[1] != '.')) // tiny adjustment in case of '09.8268329'//fan3li4_c:0.77
        for (i = 0; i < 219; i++)
            result[i] = result[i + 1];
    else if ((result[0] == '-') && (result[1] == '0') && (result[2] != '.')) // tiny adjustment in case of '-09.9374878'//fan3li4_c:-0.77
        for (i = 1; i < 219; i++)
            result[i] = result[i + 1];

    for (i = 0, j = 0; j <= precision; i++, j++)
    {
        if (result[i] == '.')
            j = 0;
        printf("%c", result[i]);
    }
    printf("\n");
    char *p = result;
    return p;
}

char *Mul(char *a_original, char *b_original, int AreNegative)
{
    /*delete the end mark(0) in the strings and fill 0s in the rest*/
    int i, j, k;
    for (i = 0; (*(a_original + i) != 0) && (i < 219); i++)
        continue;
    a_original[i] = '0';
    for (i = 0; (b_original[i] != 0) && (i < 219); i++)
        continue;
    b_original[i] = '0';

    /*Save the 2 numbers in reverse order(align the last digit) & find the dot's location*/
    int a_counter[220] = {0}, b_counter[220] = {0};
    for (j = 0, i = 219; i >= 0; i--, j++)
        a_counter[j] = a_original[i] - '0';
    for (j = 0, i = 219; i >= 0; i--, j++)
        b_counter[j] = b_original[i] - '0'; // save the number in reverse order

    for (i = 219; (i > 0) && (a_counter[i] != -3); i--)
        continue;
    a_counter[i] = 0;
    for (i = 219; (i > 0) && (b_counter[i] != -3); i--)
        continue;
    b_counter[i] = 0; // delete the '-'

    int a_loc_of_dot, b_loc_of_dot;
    for (i = 0, a_loc_of_dot = 0; a_counter[i] != -2; i++) // the ASCII value of '.' is 46, '.' - '0' = -2
        a_loc_of_dot++;                                    // the dot is at the (a_loc_of_dot)th digit's right
    for (i = 0, b_loc_of_dot = 0; b_counter[i] != -2; i++)
        b_loc_of_dot++;                            // the dot is at the (b_loc_of_dot)th digit's right
    int loc_dot = a_loc_of_dot + b_loc_of_dot + 1; // this is the absolute location of the dot
    // delete the dot after locating it
    for (i = a_loc_of_dot; i > 0; i--)
        a_counter[i] = a_counter[i - 1];
    for (i = b_loc_of_dot; i > 0; i--)
        b_counter[i] = b_counter[i - 1]; // now the dots are deleted

    /*Operate the multiplication*/
    int product_counter[440] = {0};
    for (i = 0; i < 220; i++)
        for (j = 0, k = i; j < 220; j++, k++)
            product_counter[k] += (a_counter[i] * b_counter[j]);
    for (i = 0; i < 440; i++) // process the carries
        if (product_counter[i] >= 10)
        {
            product_counter[i + 1] += product_counter[i] / 10;
            product_counter[i] %= 10;
        }

    // save the result into a char string
    char *product = (char *)malloc(220 * sizeof(char));            // a formal string to save the result
    for (i = 439; (product_counter[i] == 0) && (i > loc_dot); i--) // find where the result starts
        continue;

    if (i == loc_dot) // when the result appears to be like '0.012' '0.234'
    {
        product[0] = '0';
        product[1] = '.';
        for (j = 2; j < precision + 2; j++, i--)
            product[j] = product_counter[i] + '0'; // finish save the number
    }
    else // when the result appears to be like '33.23' '329.888'
    {
        for (j = 0; j < 220; j++, i--) // I don't give a fuckkkkkkkk
        {
            if (i == loc_dot)
            {
                product[j] = '.';
                break; // save the dot and break outta the loop
            }
            product[j] = product_counter[i] + '0';
        }
        for (k = j, j++; j < k + 201; j++, i--) // go on saving the rest part of the result
            product[j] = product_counter[i] + '0';
    }
    // now take the sign into consideration
    if (AreNegative % 2 == 1)
    {
        for (i = 219; i > 0; i--)
            product[i] = product[i - 1];
        product[0] = '-';
    } // koko made_j the product[] is the standard form

    /*output*/
    for (i = 0, j = 0; j <= precision; i++, j++)
    {
        if (product[i] == '.')
            j = 0;
        printf("%c", product[i]);
    }
    printf("\n");
    char *p = product;
    return p;
}

char *Item(char *Nthtemp, char *aaa, char *x, int *xIsNegative, int *parameterIsNegative, int power)
{
    Nthtemp = Mul(aaa, x, *(xIsNegative) + *(parameterIsNegative));

    for (int i = 1; i < power; i++) // multiply the input for 5 times
        Nthtemp = Mul(Nthtemp, x, i * *(xIsNegative) + *(parameterIsNegative));
    // int _3rdIsNegative = power * *(xIsNegative) + *(parameterIsNegative);
    return Nthtemp;
}

int main()
{
    char input[220];
    int i, j;
    for (i = 0; i < 220; i++)
        input[i] = '0';

    // printf("f(x) = 0.5*x^5+0.4*x^4-0.3*x^3-0.2*x^2+0.1*x\n");
    char notation[100]; // the notation of the function
    printf("Enter the notation of the function:\n");
    gets(notation);
    int notation_length = strlen(notation);

    printf("\nx = ");
    gets(input); // get x
    char *aaa = (char *)malloc(sizeof(char) * 220);
    char *bbb = (char *)malloc(sizeof(char) * 220);
    char *ccc = (char *)malloc(sizeof(char) * 220);
    char *ddd = (char *)malloc(sizeof(char) * 220);
    char *eee = (char *)malloc(sizeof(char) * 220);
    for (i = 0; i < 220; i++)
    {
        aaa[i] = '0';
        bbb[i] = '0';
        ccc[i] = '0';
        ddd[i] = '0';
        eee[i] = '0';
    }
    int xIsNegative = (input[0] == '-') ? 1 : 0;
    int parameterIsNegative[6] = {0, 0, 1, 1, 0, 0};

    char *temp; // for saving the temporary sum of the items
    temp = (char *)malloc(sizeof(char) * 220);
    for (i = 0; i < 220; i++)
        temp[i] = '0'; // init

    // clarify the signs of each item
    int nthIsNegative[6] = {0};
    for (i = 5; i >= 1; i--) // 5th kara 1st made
        nthIsNegative[i] = parameterIsNegative[i] + i * xIsNegative;

    char *a = (char *)malloc(max_length_parameter * sizeof(char));
    char *b = (char *)malloc(max_length_parameter * sizeof(char));
    char *c = (char *)malloc(max_length_parameter * sizeof(char));
    char *d = (char *)malloc(max_length_parameter * sizeof(char));
    char *e = (char *)malloc(max_length_parameter * sizeof(char));
    // read in the parameters
    i = 0;
    if (notation[i] == '+')
        i++;
    for (j = 0; (notation[i] != '*') && (i < notation_length); i++, j++) // j,  for every parameter, will be re-counted; i for notation
        a[j] = notation[i];                                              // read in a
    a[j] = '\0';
    for (; (notation[i] != '+') && (notation[i] != '-'); i++)
        continue;
    if (notation[i] == '+')
        i++;
    for (j = 0; (notation[i] != '*') && (i < notation_length); i++, j++) // j,  for every parameter, will be re-counted; i for notation
        b[j] = notation[i];                                              // read in b
    b[j] = '\0';
    for (; (notation[i] != '+') && (notation[i] != '-'); i++)
        continue;
    if (notation[i] == '+')
        i++;
    for (j = 0; (notation[i] != '*') && (i < notation_length); i++, j++) // j,  for every parameter, will be re-counted; i for notation
        c[j] = notation[i];                                              // read in b
    c[j] = '\0';
    for (; (notation[i] != '+') && (notation[i] != '-'); i++)
        continue;
    if (notation[i] == '+')
        i++;
    for (j = 0; (notation[i] != '*') && (i < notation_length); i++, j++) // j,  for every parameter, will be re-counted; i for notation
        d[j] = notation[i];                                              // read in b
    d[j] = '\0';
    for (; (notation[i] != '+') && (notation[i] != '-'); i++)
        continue;
    if (notation[i] == '+')
        i++;
    for (j = 0; (notation[i] != '*') && (i < notation_length); i++, j++) // j,  for every parameter, will be re-counted; i for notation
        e[j] = notation[i];                                              // read in b
    e[j] = '\0';
    // the above part can only work when none of the parameters are blank

    // copy the parameters
    for (i = 0; (i < 220) && (a[i] != 0); i++)
        aaa[i] = a[i];
    for (i = 0; (i < 220) && (b[i] != 0); i++)
        bbb[i] = b[i];
    for (i = 0; (i < 220) && (c[i] != 0); i++)
        ccc[i] = c[i];
    for (i = 0; (i < 220) && (d[i] != 0); i++)
        ddd[i] = d[i];
    for (i = 0; (i < 220) && (e[i] != 0); i++)
        eee[i] = e[i];

    char *_5thtemp = (char *)malloc(sizeof(char) * 220);
    for (i = 0; i < 220; i++)
        _5thtemp[i] = '0'; // init
    char *_4thtemp = (char *)malloc(sizeof(char) * 220);
    for (i = 0; i < 220; i++)
        _4thtemp[i] = '0'; // init
    char *_3rdtemp = (char *)malloc(sizeof(char) * 220);
    for (i = 0; i < 220; i++)
        _3rdtemp[i] = '0'; // init
    char *_2ndtemp = (char *)malloc(sizeof(char) * 220);
    for (i = 0; i < 220; i++)
        _2ndtemp[i] = '0'; // init
    char *_1sttemp = (char *)malloc(sizeof(char) * 220);
    for (i = 0; i < 220; i++)
        _1sttemp[i] = '0'; // init

    // 5th power
    _5thtemp = Item(temp, aaa, input, &xIsNegative, &parameterIsNegative[5], 5);
    // 4th power
    _4thtemp = Item(temp, bbb, input, &xIsNegative, &parameterIsNegative[4], 4);

    // 5rd power item + 4nd power item
    if ((nthIsNegative[5] + nthIsNegative[4]) % 2 == 0) // same sign keurigo_k sum of abs value
        _5thtemp = Add(_5thtemp, _4thtemp, nthIsNegative[5]);
    else                                                                        // different sign keurigo_k difference of the abs value
        _5thtemp = Sub(_5thtemp, _4thtemp, nthIsNegative[5], nthIsNegative[4]); // aquire the processible char string
    nthIsNegative[5] = (_5thtemp[0] == '-') ? 1 : 0;

    // 3rd power
    _3rdtemp = Item(temp, ccc, input, &xIsNegative, &parameterIsNegative[3], 3);

    // 5rd power item + 4nd power item + 3rd power item
    if ((nthIsNegative[5] + nthIsNegative[3]) % 2 == 0) // same sign keurigo_k sum of abs value
        _5thtemp = Add(_5thtemp, _3rdtemp, nthIsNegative[5]);
    else                                                                        // different sign keurigo_k difference of the abs value
        _5thtemp = Sub(_5thtemp, _3rdtemp, nthIsNegative[5], nthIsNegative[3]); // aquire the processible char string
    nthIsNegative[5] = (_5thtemp[0] == '-') ? 1 : 0;

    // 2nd power
    _2ndtemp = Item(temp, ddd, input, &xIsNegative, &parameterIsNegative[2], 2);

    // 5th + 4th +3rd +2nd
    if ((nthIsNegative[5] + nthIsNegative[2]) % 2 == 0) // same sign keurigo_k sum of abs value
        _5thtemp = Add(_5thtemp, _2ndtemp, nthIsNegative[5]);
    else                                                                        // different sign keurigo_k difference of the abs value
        _5thtemp = Sub(_5thtemp, _2ndtemp, nthIsNegative[5], nthIsNegative[2]); // aquire the processible char string
    nthIsNegative[5] = (_5thtemp[0] == '-') ? 1 : 0;

    // 1st power
    _1sttemp = Item(temp, eee, input, &xIsNegative, &parameterIsNegative[1], 1);

    // 5th + 4th 3rd + 2nd + 1st
    if ((nthIsNegative[5] + nthIsNegative[1]) % 2 == 0) // same sign keurigo_k sum of abs value
        _5thtemp = Add(_5thtemp, _1sttemp, nthIsNegative[5]);
    else                                                                        // different sign keurigo_k difference of the abs value
        _5thtemp = Sub(_5thtemp, _1sttemp, nthIsNegative[5], nthIsNegative[1]); // aquire the processible char string
    nthIsNegative[5] = (_5thtemp[0] == '-') ? 1 : 0;

    // plus
    return 0;
}