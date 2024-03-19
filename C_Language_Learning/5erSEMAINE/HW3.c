// 1
//  #include <stdio.h>
//  //ak=n^3-k(k-1)
//  int main(){
//      int n, k, temp, mod;
//      scanf("%d", &n);
//      n = n * n * n;
//      for (k = 2; ; k++){
//          temp = k * (k - 1);
//          mod = n - temp;
//          if (mod % k == 0 && (mod / k) % 2 == 1){
//              break;
//          }
//      }
//      printf("%d %d", mod / k, k);
//      return 0;
//  }

// 2
#include <stdio.h>

int main()
{
    int a[5], b[5], res;
    int i, j;
    for (i = 0; i < 5; i++)
    {
        scanf("%d", &a[i]);
    }
    scanf("%d", &res);

    int optr_all, tmp, optr[4];
    int flag = 0;
    for (optr_all = 0; optr_all < 256; optr_all++)
    {
        // or a 4-layer for loop
        tmp = optr_all;
        for (i = 0; i < 4; i++)
        {
            optr[i] = tmp % 4;
            tmp = tmp / 4;
        }

        switch (optr[0])
        {
        case 0:
            b[1] = a[0] + a[1];
            break;
        case 1:
            b[1] = a[0] - a[1];
            break;
        case 2:
            b[1] = a[0] * a[1];
            break;
        case 3:
            b[1] = a[0] / a[1];
            break;
        }
        for (i = 1; i < 4; i++)
        {
            switch (optr[i])
            {
            case 0:
                b[i + 1] = b[i] + a[i + 1];
                break;
            case 1:
                b[i + 1] = b[i] - a[i + 1];
                break;
            case 2:
                b[i + 1] = b[i] * a[i + 1];
                break;
            case 3:
                b[i + 1] = b[i] / a[i + 1];
                break;
            }
        }

        if (b[4] == res)
        {
            flag = 1;
            for (i = 0; i < 4; i++)
            {
                switch (optr[i])
                {
                case 0:
                    printf("+ ");
                    break;
                case 1:
                    printf("- ");
                    break;
                case 2:
                    printf("* ");
                    break;
                case 3:
                    printf("/ ");
                    break;
                }
            }
            printf("\n");
        }
    }
    if (flag == 0)
        printf("No solution");
    return 0;
}

// 3
//  #include <stdio.h>

// int main() {
// 	int year, day;
// 	int weekdays[13][32];
// 	int isLuckyYear = 1;
// 	scanf("%d %d", &year, &day);
// 	for (int i = 1; i <= 12; i++) {
// 		int month_days = 30;
// 		if (i == 1 || i == 3 || i == 5 || i == 7 || i == 8 || i == 10 || i == 12) {
// 			month_days = 31;
// 		}
// 		else if (i == 2) {
// 			if (((year % 4 == 0) && (year % 100 != 0)) || (year % 400 == 0)) {
// 				month_days = 29;
// 			}
// 			else {
// 				month_days = 28;
// 			}
// 		}
// 		for (int j = 1; j <= month_days; j++) {
// 			weekdays[i][j] = day;
// 			day = (day + 1) % 7;
// 		}
// 	}
// 	for (int i = 1; i <= 12; i++) {
// 		if (weekdays[i][13] == 5) {
// 			printf("%d\n", i);
// 			isLuckyYear = 0;
// 		}
// 	}
// 	if (isLuckyYear) {
// 		printf("Luck\n");
// 	}
// 	return 0;
// }
