#include<stdio.h>
int main()
{
	int a, b, c, d, e, result;
	scanf("%d %d %d %d %d %d",&a,&b,&c,&d,&e,&result);

/*Part 1*/
	if ((((a + b) + c) + d) + e == result)
		printf("+ + + +");
	else if ((((a + b) + c) + d) - e == result)
		printf("+ + + -");
	else if ((((a + b) + c) + d) * e == result)
		printf("+ + + *");
	else if ((((a + b) + c) + d) / e == result)
		printf("+ + + /");
	
	else if ((((a + b) + c) - d) + e == result)
		printf("+ + - +");
	else if ((((a + b) + c) - d) - e == result)
		printf("+ + - -");
	else if ((((a + b) + c) - d) * e == result)
		printf("+ + - *");
	else if ((((a + b) + c) - d) / e == result)
		printf("+ + - /");
	
	else if ((((a + b) + c) * d) + e == result)
		printf("+ + * +");
	else if ((((a + b) + c) * d) - e == result)
		printf("+ + * -");
	else if ((((a + b) + c) * d) * e == result)
		printf("+ + * *");
	else if ((((a + b) + c) * d) / e == result)
		printf("+ + * /");
	
	else if ((((a + b) + c) / d) + e == result)
		printf("+ + / +");
	else if ((((a + b) + c) / d) - e == result)
		printf("+ + / -");
	else if ((((a + b) + c) / d) * e == result)
		printf("+ + / *");
	else if ((((a + b) + c) / d) / e == result)
		printf("+ + / /");
	
	else if ((((a + b) - c) + d) + e == result)
		printf("+ - + +");
	else if ((((a + b) - c) + d) - e == result)
		printf("+ - + -");
	else if ((((a + b) - c) + d) * e == result)
		printf("+ - + *");
	else if ((((a + b) - c) + d) / e == result)
		printf("+ - + /");
	
	else if ((((a + b) - c) - d) + e == result)
		printf("+ - - +");
	else if ((((a + b) - c) - d) - e == result)
		printf("+ - - -");
	else if ((((a + b) - c) - d) * e == result)
		printf("+ - - *");
	else if ((((a + b) - c) - d) / e == result)
		printf("+ - - /");
	
	else if ((((a + b) - c) * d) + e == result)
		printf("+ - * +");
	else if ((((a + b) - c) * d) - e == result)
		printf("+ - * -");
	else if ((((a + b) - c) * d) * e == result)
		printf("+ - * *");
	else if ((((a + b) - c) * d) / e == result)
		printf("+ - * /");
	
	else if ((((a + b) - c) / d) + e == result)
		printf("+ - / +");
	else if ((((a + b) - c) / d) - e == result)
		printf("+ - / -");
	else if ((((a + b) - c) / d) * e == result)
		printf("+ - / *");
	else if ((((a + b) - c) / d) / e == result)
		printf("+ - / /");
	
	else if ((((a + b) * c) + d) + e == result)
		printf("+ * + +");
	else if ((((a + b) * c) + d) - e == result)
		printf("+ * + -");
	else if ((((a + b) * c) + d) * e == result)
		printf("+ * + *");
	else if ((((a + b) * c) + d) / e == result)
		printf("+ * + /");
	
	else if ((((a + b) * c) - d) + e == result)
		printf("+ * - +");
	else if ((((a + b) * c) - d) - e == result)
		printf("+ * - -");
	else if ((((a + b) * c) - d) * e == result)
		printf("+ * - *");
	else if ((((a + b) * c) - d) / e == result)
		printf("+ * - /");
	
	else if ((((a + b) * c) * d) + e == result)
		printf("+ * * +");
	else if ((((a + b) * c) * d) - e == result)
		printf("+ * * -");
	else if ((((a + b) * c) * d) * e == result)
		printf("+ * * *");
	else if ((((a + b) * c) * d) / e == result)
		printf("+ * * /");
	
	else if ((((a + b) * c) / d) + e == result)
		printf("+ * / +");
	else if ((((a + b) * c) / d) - e == result)
		printf("+ * / -");
	else if ((((a + b) * c) / d) * e == result)
		printf("+ * / *");
	else if ((((a + b) * c) / d) / e == result)
		printf("+ * / /");
	
	else if ((((a + b) / c) + d) + e == result)
		printf("+ / + +");
	else if ((((a + b) / c) + d) - e == result)
		printf("+ / + -");
	else if ((((a + b) / c) + d) * e == result)
		printf("+ / + *");
	else if ((((a + b) / c) + d) / e == result)
		printf("+ / + /");
	
	else if ((((a + b) / c) - d) + e == result)
		printf("+ / - +");
	else if ((((a + b) / c) - d) - e == result)
		printf("+ / - -");
	else if ((((a + b) / c) - d) * e == result)
		printf("+ / - *");
	else if ((((a + b) / c) - d) / e == result)
		printf("+ / - /");
	
	else if ((((a + b) / c) * d) + e == result)
		printf("+ / * +");
	else if ((((a + b) / c) * d) - e == result)
		printf("+ / * -");
	else if ((((a + b) / c) * d) * e == result)
		printf("+ / * *");
	else if ((((a + b) / c) * d) / e == result)
		printf("+ / * /");
	
	else if ((((a + b) / c) / d) + e == result)
		printf("+ / / +");
	else if ((((a + b) / c) / d) - e == result)
		printf("+ / / -");
	else if ((((a + b) / c) / d) * e == result)
		printf("+ / / *");
	else if ((((a + b) / c) / d) / e == result)
		printf("+ / / /");

/*Part 2*/	
	else if ((((a - b) + c) + d) + e == result)
		printf("- + + +");
	else if ((((a - b) + c) + d) - e == result)
		printf("- + + -");
	else if ((((a - b) + c) + d) * e == result)
		printf("- + + *");
	else if ((((a - b) + c) + d) / e == result)
		printf("- + + /");
	
	else if ((((a - b) + c) - d) + e == result)
		printf("- + - +");
	else if ((((a - b) + c) - d) - e == result)
		printf("- + - -");
	else if ((((a - b) + c) - d) * e == result)
		printf("- + - *");
	else if ((((a - b) + c) - d) / e == result)
		printf("- + - /");
	
	else if ((((a - b) + c) * d) + e == result)
		printf("- + * +");
	else if ((((a - b) + c) * d) - e == result)
		printf("- + * -");
	else if ((((a - b) + c) * d) * e == result)
		printf("- + * *");
	else if ((((a - b) + c) * d) / e == result)
		printf("- + * /");
	
	else if ((((a - b) + c) / d) + e == result)
		printf("- + / +");
	else if ((((a - b) + c) / d) - e == result)
		printf("- + / -");
	else if ((((a - b) + c) / d) * e == result)
		printf("- + / *");
	else if ((((a - b) + c) / d) / e == result)
		printf("- + / /");
	
	else if ((((a - b) - c) + d) + e == result)
		printf("- - + +");
	else if ((((a - b) - c) + d) - e == result)
		printf("- - + -");
	else if ((((a - b) - c) + d) * e == result)
		printf("- - + *");
	else if ((((a - b) - c) + d) / e == result)
		printf("- - + /");
	
	else if ((((a - b) - c) - d) + e == result)
		printf("- - - +");
	else if ((((a - b) - c) - d) - e == result)
		printf("- - - -");
	else if ((((a - b) - c) - d) * e == result)
		printf("- - - *");
	else if ((((a - b) - c) - d) / e == result)
		printf("- - - /");
	
	else if ((((a - b) - c) * d) + e == result)
		printf("- - * +");
	else if ((((a - b) - c) * d) - e == result)
		printf("- - * -");
	else if ((((a - b) - c) * d) * e == result)
		printf("- - * *");
	else if ((((a - b) - c) * d) / e == result)
		printf("- - * /");
	
	else if ((((a - b) - c) / d) + e == result)
		printf("- - / +");
	else if ((((a - b) - c) / d) - e == result)
		printf("- - / -");
	else if ((((a - b) - c) / d) * e == result)
		printf("- - / *");
	else if ((((a - b) - c) / d) / e == result)
		printf("- - / /");
	
	else if ((((a - b) * c) / d) + e == result)
		printf("- * / +");
	else if ((((a - b) * c) / d) - e == result)
		printf("- * / -");
	else if ((((a - b) * c) / d) * e == result)
		printf("- * / *");
	else if ((((a - b) * c) / d) / e == result)
		printf("- * / /");
	
	else if ((((a - b) * c) + d) + e == result)
		printf("- * + +");
	else if ((((a - b) * c) + d) - e == result)
		printf("- * + -");
	else if ((((a - b) * c) + d) * e == result)
		printf("- * + *");
	else if ((((a - b) * c) + d) / e == result)
		printf("- * + /");
	
	else if ((((a - b) * c) - d) + e == result)
		printf("- * - +");
	else if ((((a - b) * c) - d) - e == result)
		printf("- * - -");
	else if ((((a - b) * c) - d) * e == result)
		printf("- * - *");
	else if ((((a - b) * c) - d) / e == result)
		printf("- * - /");
	
	else if ((((a - b) * c) * d) + e == result)
		printf("- * * +");
	else if ((((a - b) * c) * d) - e == result)
		printf("- * * -");
	else if ((((a - b) * c) * d) * e == result)
		printf("- * * *");
	else if ((((a - b) * c) * d) / e == result)
		printf("- * * /");
	
	else if ((((a - b) * c) / d) + e == result)
		printf("- * / +");
	else if ((((a - b) * c) / d) - e == result)
		printf("- * / -");
	else if ((((a - b) * c) / d) * e == result)
		printf("- * / *");
	else if ((((a - b) * c) / d) / e == result)
		printf("- * / /");
	
	else if ((((a - b) / c) / d) + e == result)
		printf("- / / +");
	else if ((((a - b) / c) / d) - e == result)
		printf("- / / -");
	else if ((((a - b) / c) / d) * e == result)
		printf("- / / *");
	else if ((((a - b) / c) / d) / e == result)
		printf("- / / /");
	
	else if ((((a - b) / c) + d) + e == result)
		printf("- / + +");
	else if ((((a - b) / c) + d) - e == result)
		printf("- / + -");
	else if ((((a - b) / c) + d) * e == result)
		printf("- / + *");
	else if ((((a - b) / c) + d) / e == result)
		printf("- / + /");
	
	else if ((((a - b) / c) - d) + e == result)
		printf("- / - +");
	else if ((((a - b) / c) - d) - e == result)
		printf("- / - -");
	else if ((((a - b) / c) - d) * e == result)
		printf("- / - *");
	else if ((((a - b) / c) - d) / e == result)
		printf("- / - /");
	
	else if ((((a - b) / c) * d) + e == result)
		printf("- / * +");
	else if ((((a - b) / c) * d) - e == result)
		printf("- / * -");
	else if ((((a - b) / c) * d) * e == result)
		printf("- / * *");
	else if ((((a - b) / c) * d) / e == result)
		printf("- / * /");
	
	else if ((((a - b) / c) / d) + e == result)
		printf("- / / +");
	else if ((((a - b) / c) / d) - e == result)
		printf("- / / -");
	else if ((((a - b) / c) / d) * e == result)
		printf("- / / *");
	else if ((((a - b) / c) / d) / e == result)
		printf("- / / /");

/*Part 3*/	
	else if ((((a * b) + c) + d) + e == result)
		printf("* + + +");
	else if ((((a * b) + c) + d) - e == result)
		printf("* + + -");
	else if ((((a * b) + c) + d) * e == result)
		printf("* + + *");
	else if ((((a * b) + c) + d) / e == result)
		printf("* + + /");
	
	else if ((((a * b) + c) - d) + e == result)
		printf("* + - +");
	else if ((((a * b) + c) - d) - e == result)
		printf("* + - -");
	else if ((((a * b) + c) - d) * e == result)
		printf("* + - *");
	else if ((((a * b) + c) - d) / e == result)
		printf("* + - /");
	
	else if ((((a * b) + c) * d) + e == result)
		printf("* + * +");
	else if ((((a * b) + c) * d) - e == result)
		printf("* + * -");
	else if ((((a * b) + c) * d) * e == result)
		printf("* + * *");
	else if ((((a * b) + c) * d) / e == result)
		printf("* + * /");
	
	else if ((((a * b) + c) / d) + e == result)
		printf("* + / +");
	else if ((((a * b) + c) / d) - e == result)
		printf("* + / -");
	else if ((((a * b) + c) / d) * e == result)
		printf("* + / *");
	else if ((((a * b) + c) / d) / e == result)
		printf("* + / /");
	
	else if ((((a * b) - c) + d) + e == result)
		printf("* - + +");
	else if ((((a * b) - c) + d) - e == result)
		printf("* - + -");
	else if ((((a * b) - c) + d) * e == result)
		printf("* - + *");
	else if ((((a * b) - c) + d) / e == result)
		printf("* - + /");
	
	else if ((((a * b) - c) - d) + e == result)
		printf("* - - +");
	else if ((((a * b) - c) - d) - e == result)
		printf("* - - -");
	else if ((((a * b) - c) - d) * e == result)
		printf("* - - *");
	else if ((((a * b) - c) - d) / e == result)
		printf("* - - /");
	
	else if ((((a * b) - c) * d) + e == result)
		printf("* - * +");
	else if ((((a * b) - c) * d) - e == result)
		printf("* - * -");
	else if ((((a * b) - c) * d) * e == result)
		printf("* - * *");
	else if ((((a * b) - c) * d) / e == result)
		printf("* - * /");
	
	else if ((((a * b) - c) / d) + e == result)
		printf("* - / +");
	else if ((((a * b) - c) / d) - e == result)
		printf("* - / -");
	else if ((((a * b) - c) / d) * e == result)
		printf("* - / *");
	else if ((((a * b) - c) / d) / e == result)
		printf("* - / /");
	
	else if ((((a * b) * c) / d) + e == result)
		printf("* * / +");
	else if ((((a * b) * c) / d) - e == result)
		printf("* * / -");
	else if ((((a * b) * c) / d) * e == result)
		printf("* * / *");
	else if ((((a * b) * c) / d) / e == result)
		printf("* * / /");
	
	else if ((((a * b) * c) + d) + e == result)
		printf("* * + +");
	else if ((((a * b) * c) + d) - e == result)
		printf("* * + -");
	else if ((((a * b) * c) + d) * e == result)
		printf("* * + *");
	else if ((((a * b) * c) + d) / e == result)
		printf("* * + /");
	
	else if ((((a * b) * c) - d) + e == result)
		printf("* * - +");
	else if ((((a * b) * c) - d) - e == result)
		printf("* * - -");
	else if ((((a * b) * c) - d) * e == result)
		printf("* * - *");
	else if ((((a * b) * c) - d) / e == result)
		printf("* * - /");
	
	else if ((((a * b) * c) * d) + e == result)
		printf("* * * +");
	else if ((((a * b) * c) * d) - e == result)
		printf("* * * -");
	else if ((((a * b) * c) * d) * e == result)
		printf("* * * *");
	else if ((((a * b) * c) * d) / e == result)
		printf("* * * /");
	
	else if ((((a * b) * c) / d) + e == result)
		printf("* * / +");
	else if ((((a * b) * c) / d) - e == result)
		printf("* * / -");
	else if ((((a * b) * c) / d) * e == result)
		printf("* * / *");
	else if ((((a * b) * c) / d) / e == result)
		printf("* * / /");
	
	else if ((((a * b) / c) / d) + e == result)
		printf("* / / +");
	else if ((((a * b) / c) / d) - e == result)
		printf("* / / -");
	else if ((((a * b) / c) / d) * e == result)
		printf("* / / *");
	else if ((((a * b) / c) / d) / e == result)
		printf("* / / /");
	
	else if ((((a * b) / c) + d) + e == result)
		printf("* / + +");
	else if ((((a * b) / c) + d) - e == result)
		printf("* / + -");
	else if ((((a * b) / c) + d) * e == result)
		printf("* / + *");
	else if ((((a * b) / c) + d) / e == result)
		printf("* / + /");
	
	else if ((((a * b) / c) - d) + e == result)
		printf("* / - +");
	else if ((((a * b) / c) - d) - e == result)
		printf("* / - -");
	else if ((((a * b) / c) - d) * e == result)
		printf("* / - *");
	else if ((((a * b) / c) - d) / e == result)
		printf("* / - /");
	
	else if ((((a * b) / c) * d) + e == result)
		printf("* / * +");
	else if ((((a * b) / c) * d) - e == result)
		printf("* / * -");
	else if ((((a * b) / c) * d) * e == result)
		printf("* / * *");
	else if ((((a * b) / c) * d) / e == result)
		printf("* / * /");
	
	else if ((((a * b) / c) / d) + e == result)
		printf("* / / +");
	else if ((((a * b) / c) / d) - e == result)
		printf("* / / -");
	else if ((((a * b) / c) / d) * e == result)
		printf("* / / *");
	else if ((((a * b) / c) / d) / e == result)
		printf("* / / /");

/*Part 4*/	
	else if ((((a / b) + c) + d) + e == result)
		printf("/ + + +");
	else if ((((a / b) + c) + d) - e == result)
		printf("/ + + -");
	else if ((((a / b) + c) + d) * e == result)
		printf("/ + + *");
	else if ((((a / b) + c) + d) / e == result)
		printf("/ + + /");
	
	else if ((((a / b) + c) - d) + e == result)
		printf("/ + - +");
	else if ((((a / b) + c) - d) - e == result)
		printf("/ + - -");
	else if ((((a / b) + c) - d) * e == result)
		printf("/ + - *");
	else if ((((a / b) + c) - d) / e == result)
		printf("/ + - /");
	
	else if ((((a / b) + c) * d) + e == result)
		printf("/ + * +");
	else if ((((a / b) + c) * d) - e == result)
		printf("/ + * -");
	else if ((((a / b) + c) * d) * e == result)
		printf("/ + * *");
	else if ((((a / b) + c) * d) / e == result)
		printf("/ + * /");
	
	else if ((((a / b) + c) / d) + e == result)
		printf("/ + / +");
	else if ((((a / b) + c) / d) - e == result)
		printf("/ + / -");
	else if ((((a / b) + c) / d) * e == result)
		printf("/ + / *");
	else if ((((a / b) + c) / d) / e == result)
		printf("/ + / /");
	
	else if ((((a / b) - c) + d) + e == result)
		printf("/ - + +");
	else if ((((a / b) - c) + d) - e == result)
		printf("/ - + -");
	else if ((((a / b) - c) + d) * e == result)
		printf("/ - + *");
	else if ((((a / b) - c) + d) / e == result)
		printf("/ - + /");
	
	else if ((((a / b) - c) - d) + e == result)
		printf("/ - - +");
	else if ((((a / b) - c) - d) - e == result)
		printf("/ - - -");
	else if ((((a / b) - c) - d) * e == result)
		printf("/ - - *");
	else if ((((a / b) - c) - d) / e == result)
		printf("/ - - /");
	
	else if ((((a / b) - c) * d) + e == result)
		printf("/ - * +");
	else if ((((a / b) - c) * d) - e == result)
		printf("/ - * -");
	else if ((((a / b) - c) * d) * e == result)
		printf("/ - * *");
	else if ((((a / b) - c) * d) / e == result)
		printf("/ - * /");
	
	else if ((((a / b) - c) / d) + e == result)
		printf("/ - / +");
	else if ((((a / b) - c) / d) - e == result)
		printf("/ - / -");
	else if ((((a / b) - c) / d) * e == result)
		printf("/ - / *");
	else if ((((a / b) - c) / d) / e == result)
		printf("/ - / /");
	
	else if ((((a / b) * c) / d) + e == result)
		printf("/ * / +");
	else if ((((a / b) * c) / d) - e == result)
		printf("/ * / -");
	else if ((((a / b) * c) / d) * e == result)
	printf("/ * / *");
	else if ((((a / b) * c) / d) / e == result)
		printf("/ * / /");
	
	else if ((((a / b) * c) + d) + e == result)
		printf("/ * + +");
	else if ((((a / b) * c) + d) - e == result)
		printf("/ * + -");
	else if ((((a / b) * c) + d) * e == result)
		printf("/ * + *");
	else if ((((a / b) * c) + d) / e == result)
		printf("/ * + /");
	
	else if ((((a / b) * c) - d) + e == result)
		printf("/ * - +");
	else if ((((a / b) * c) - d) - e == result)
		printf("/ * - -");
	else if ((((a / b) * c) - d) * e == result)
		printf("/ * - *");
	else if ((((a / b) * c) - d) / e == result)
		printf("/ * - /");
	
	else if ((((a / b) * c) * d) + e == result)
		printf("/ * * +");
	else if ((((a / b) * c) * d) - e == result)
		printf("/ * * -");
	else if ((((a / b) * c) * d) * e == result)
		printf("/ * * *");
	else if ((((a / b) * c) * d) / e == result)
		printf("/ * * /");
	
	else if ((((a / b) * c) / d) + e == result)
		printf("/ * / +");
	else if ((((a / b) * c) / d) - e == result)
		printf("/ * / -");
	else if ((((a / b) * c) / d) * e == result)
		printf("/ * / *");
	else if ((((a / b) * c) / d) / e == result)
		printf("/ * / /");
	
	else if ((((a / b) / c) / d) + e == result)
		printf("/ / / +");
	else if ((((a / b) / c) / d) - e == result)
		printf("/ / / -");
	else if ((((a / b) / c) / d) * e == result)
		printf("/ / / *");
	else if ((((a / b) / c) / d) / e == result)
		printf("/ / / /");

/*Part 5*/	
	else printf("No solution");
	return 0;
}