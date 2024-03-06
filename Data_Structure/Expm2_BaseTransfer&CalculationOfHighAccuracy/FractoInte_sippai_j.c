#include <stdio.h>
#include <string.h>
#define maxn 210
#define precision 200

typedef struct frac
{
    int a;          // 分子
    int b;          // 分母，这两个都是正数
    int isNegative; // 是否是负数,1是0否
} Frac;

typedef struct HighAccuracyNum
{
    int Integer;       // 整数部分
    int Decimal[maxn]; // 小数部分，Decimal[0]是十分位，Decimal[1]是百分位
    int base;          // 进制
    int isNegative;
} Number;

void init(Number *InitNum)
{ // 初始化清空
    InitNum->Integer = 0;
    memset(InitNum->Decimal, 0, sizeof(InitNum->Decimal));
    InitNum->base = 0;
    InitNum->isNegative = 0;
}

Number FractoNumber(Frac origin)
{
    Number result;
    init(&result);
    result.base = 10;
    result.isNegative = origin.isNegative;
    result.Integer = origin.a / origin.b; // 求出整数部分
    origin.a %= origin.b;
    for (int i = 0; i < precision; i++)
    {
        origin.a *= 10; // 模拟竖式除法
        result.Decimal[i] = origin.a / origin.b;
        origin.a %= origin.b;
    }
    origin.a *= 10;
    if (origin.a / origin.b >= 5)
    {
        result.Decimal[precision - 1]++;
    } // 最后一位四舍五入
    return result;
}

char *Add(char *a_original, char *b_original, int aIsNegative) // a and b are in char form!!!
{
    /*delete the end mark(0) in the strings*/
    int i, j, k;
    // for (i = 0; i < 220; i++)
    //     printf ("%d", a_original[i]);
    for (i = 0; (*(a_original + i) != 0) && (i < 220); i++)
        continue;
    a_original[i] = '0';
    for (i = 0; (b_original[i] != 0) && (i < 220); i++)
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
    char result[220];
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
    char *p = result;
    return p;
}

char *Sub(char *a_original, char *b_original, int aIsNegative, int bIsNegative) // a and b are in char form!!!
{
    /*delete the end mark(0) in the strings*/
    int i, j;
    for (i = 0; (*(a_original + i) != 0) && (i < 220); i++)
        continue;
    a_original[i] = '0';
    for (i = 0; (b_original[i] != 0) && (i < 220); i++)
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
    char result[220];
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
    char *p = result;
    return p;
}

char *Mul(char *a_original, char *b_original, int AreNegative)
{
    /*delete the end mark(0) in the strings*/
    int i, j, k;
    for (i = 0; (*(a_original + i) != 0) && (i < 220); i++)
        continue;
    a_original[i] = '0';
    for (i = 0; (b_original[i] != 0) && (i < 220); i++)
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
    char product[220];                                             // a formal string to save the result
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
    char *p = product;
    return p;
}

int main()
{
    char input[220];
    int i;

    /*Part 6*/
    /*Certain function*/
    printf("f(x) = 0.5*x^5+0.4*x^4-0.3*x^3-0.2*x^2+0.1*x\n");
    printf("x = ");
    gets(input); // get x
    int xIsNegative = (input[0] == '-') ? 1 : 0;

    Frac a = (Frac){3, 7, 0};
    Frac b = (Frac){1, 3, 1};
    Frac c = (Frac){0, 1, 0};
    Frac d = (Frac){4, 1, 0}; // the parameters unprocessed
    Number a_a = FractoNumber(a);
    Number b_b = FractoNumber(b);
    Number c_c = FractoNumber(c);
    Number d_d = FractoNumber(d); // the parameters processed

    char aaa[220], bbb[220], ccc[220], ddd[220]; // the parameters strings
    for (i = 0; i < 220; i++)                    // initialize the strings
    {
        aaa[i] = '0';
        bbb[i] = '0';
        ccc[i] = '0';
        ddd[i] = '0';
    }

    // save the parameters into the strings
    aaa[0] = a_a.Integer;
    bbb[0] = b_b.Integer;
    ccc[0] = c_c.Integer;
    ddd[0] = d_d.Integer;
    aaa[1] = '.';
    bbb[1] = '.';
    ccc[1] = '.';
    ddd[1] = '.';
    for (i = 0; i < 220; i++)
    {
        aaa[i + 2] = a_a.Decimal[i];
        bbb[i + 2] = b_b.Decimal[i];
        ccc[i + 2] = c_c.Decimal[i];
        ddd[i + 2] = d_d.Decimal[i];
    }
    // and the sign!
    if (a.isNegative == 1)
    {
        for (i = 219; i >= 0; i--)
            aaa[i] = aaa[i - 1];
        aaa[0] = '-';
    }
    if (b.isNegative == 1)
    {
        for (i = 219; i >= 0; i--)
            bbb[i] = bbb[i - 1];
        bbb[0] = '-';
    }
    if (c.isNegative == 1)
    {
        for (i = 219; i >= 0; i--)
            ccc[i] = ccc[i - 1];
        ccc[0] = '-';
    }
    if (d.isNegative == 1)
    {
        for (i = 219; i >= 0; i--)
            ddd[i] = ddd[i - 1];
        ddd[0] = '-';
    }

    // 3rd power items mul
    char *_3rdtemp; // why can't be given a value ????
    for (i = 0; i < 220; i++)
        _3rdtemp[i] = '0'; // init
    _3rdtemp = Mul(aaa, input, xIsNegative + a.isNegative);
    for (i = 1; i < 3; i++) // multiply the input for 3 times
        _3rdtemp = Mul(_3rdtemp, input, a.isNegative + i * xIsNegative);
    int _3rdIsNegative = a.isNegative + 3 * xIsNegative;
    // 2nd power items
    char *_2ndtemp;
    for (i = 0; i < 220; i++)
        _2ndtemp[i] = '0'; // init
    _2ndtemp = Mul(bbb, input, xIsNegative + b.isNegative);
    for (i = 1; i < 2; i++) // multiply the input for 3 times
        _2ndtemp = Mul(_2ndtemp, input, b.isNegative + i * xIsNegative);
    int _2ndIsNegative = b.isNegative + 2 * xIsNegative;
    // 1st power items
    char *_1sttemp;
    for (i = 0; i < 220; i++)
        _1sttemp[i] = '0'; // init
    _1sttemp = Mul(ccc, input, xIsNegative + c.isNegative);
    int _1stIsNegative = c.isNegative + 1 * xIsNegative;
    int _0thIsNegative = d.isNegative;
    // plus the 4 items
    // 3rd power item + 2nd power item
    if ((_3rdIsNegative + _2ndIsNegative) % 2 == 0) // same sign keurigo_k sum of abs value
        _3rdtemp = Add(_3rdtemp, _2ndtemp, _3rdIsNegative % 2);
    else                                                                    // different sign keurigo_k difference of the abs value
        _3rdtemp = Sub(_3rdtemp, _2ndtemp, _3rdIsNegative, _2ndIsNegative); // aquire the processible char string
    _3rdIsNegative = (_3rdtemp[0] = '-') ? 1 : 0;
    // ijou_j + 1st power item
    if ((_3rdIsNegative + _1stIsNegative) % 2 == 0) // same sign keurigo_k sum of abs value
        _3rdtemp = Add(_3rdtemp, _1sttemp, _3rdIsNegative % 2);
    else                                                                    // different sign keurigo_k difference of the abs value
        _3rdtemp = Sub(_3rdtemp, _1sttemp, _3rdIsNegative, _1stIsNegative); // aquire the processible char string
    _3rdIsNegative = (_3rdtemp[0] = '-') ? 1 : 0;
    // ijou_j + 0th power item
    if ((_3rdIsNegative + _0thIsNegative) % 2 == 0) // same sign keurigo_k sum of abs value
        _3rdtemp = Add(_3rdtemp, ddd, _3rdIsNegative % 2);
    else                                                               // different sign keurigo_k difference of the abs value
        _3rdtemp = Sub(_3rdtemp, ddd, _3rdIsNegative, _0thIsNegative); // aquire the processible char string
    _3rdIsNegative = (_3rdtemp[0] = '-') ? 1 : 0;
}
