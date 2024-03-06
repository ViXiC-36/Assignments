#include <stdio.h>
#include <stdlib.h>
#include <time.h>
/*Based on random algorithm LARGELY,
go to the better sol. immediately once found
AKA climbing*/

// 采用堆分配存储的方式实现
int *solution; // 每列一个皇后，solution[col]=row,表示第col列的皇后在row行
int len;       // 皇后数量，len*len的棋盘
int generation = 0;
int times = 0;

clock_t start, finish;

// 函数声明
void initSolution();
void restart();
void swap(int, int);
int traverseNeighbors();
int evaluate();

int main()
{
    // long seed = 820; // 随机数种子，如果这个数不改变，那么每次算法运行的结果都是一样的，即使用rand()函数
    srand((unsigned int)time(0)); // generate random numbers based on the time

    printf("Enter the number of Queens: ");
    scanf("%d", &len); // 键盘读入棋盘的大小
    // len = 8; // 棋盘大小
    if (len < 4)
    {
        printf("No solution!");
        return 0;
    }

    start = clock();
    solution = (int *)malloc(sizeof(int) * len);
    if (!solution)
        return 0; // 分配空间失败

    initSolution(); // 初始化一个棋盘布局

    int flag;
    while ((flag = traverseNeighbors()) != 0)
    {
        // for (int k = 0; k < len; k++)
        //     printf("-%d-", solution[k]);
        if (flag < 0)
            restart();
    }
    finish = clock();

    printf("\nSolution: ");
    for (int i = 0; i < len; i++)
        printf("%d,", solution[i] + 1);
    // getchar();
    free(solution);
    printf("\nTime cost: %.3f s", (double)(finish - start) / CLOCKS_PER_SEC);
    return 0;
}

/***  将棋盘的第i列和第j列交换  ***/
void swap(int i, int j)
{
    if (i != j)
    {
        solution[i] = solution[i] + solution[j];
        solution[j] = solution[i] - solution[j];
        solution[i] = solution[i] - solution[j];
    }
    // for (int k = 0; k < len; k++)
    //     printf("-%d-", solution[k]);
}

/***  初始化一个棋盘布局,将邻居数组准备好  ***/
void initSolution()
{
    // 随机给初始布局或给定某个初始布局
    for (int i = 0; i < len; ++i)
        solution[i] = i; // place all the queens on the main diag.
    // for (int k = 0; k < len; k++)
    //     printf("-%d-", solution[k]);
    for (int i = 0; i < 2 * len; ++i) // 对棋盘进行2*len次随机交换
        swap(rand() % len, rand() % len);
    //     for (int k = 0; k < len; k++)//mondai ga aru !!!!_j
    //         printf("-%d-", solution[k]);
    printf("Initialization completed.\n");
}

/***  计算棋盘的评价函数（棋盘的价值: value=可相互攻击到的皇后对数）
 ***  当皇后相互攻击不到时，目标函数的值value==0
 ***   solution[i]==solution[j], (solution[i]-solution[j])/(i-j)==1或-1时（C语言实现会有bug），两个皇后彼此能攻击到，value++
 ***  棋盘编码方式能保证不会出现 solution[i]==solution[j]，故该条件可以不用判断
 ***  思考：该函数的时间性能是否能提高？
 ***/
int evaluate()
{
    int value = 0;
    int i, j;
    // horizontal (no need for considering the vertical lines)
    // for (i = 0; i < len; i++)
    // 	for (j = i + 1; j < len; j++)
    // 		if (solution[i] == solution[j])
    // 			value++;
    // diag.
    for (i = 0; i < len; i++)
        for (j = i + 1; j < len; j++)
        {
            if (i == j)
                continue;
            if ((solution[i] - i) == (solution[j] - j))
                value++;
            if ((i + solution[i]) == (j + solution[j]))
                value++;
        }
    // printf ("[%2d]", value);
    return value;
}

/***  检查当前解（棋盘）的邻居棋盘（交换solution[i]和solution[j],i和j随机选择，共有n(n-1)/2种不同的可能）
 ***  保留冲突最小的棋盘，将它视为新的解（best found策略）
 ***  若返回-1,表示没有找到更好的邻居，需要重启 restart() ,返回0表示找到所求的解，
 ***  返回大于0的值表示需要更新当前解solution后要继续遍历新解的邻居
 ***/
int traverseNeighbors()
{
    int min_value = evaluate();     // 当前棋盘的所有邻居的最小评价函数值
    int min_col = -1, min_row = -1; // 上述对应的邻居
    int tempvalue;
    int i, j;
    // 遍历邻居，评估每个邻居冲突皇后对的个数，找到最小冲突对数的邻居
    //  todo
    int bdr = 222 / len + 1;

    if (min_value <= bdr) // in case the length is not so big
    {
        for (i = 0; i < len; i++)
            for (j = i + 1; j < len; j++)
            {
                swap(i, j);
                tempvalue = evaluate();
                if (tempvalue < min_value)
                {
                    min_value = tempvalue;
                    min_col = i;
                    min_row = j;
                    swap(i, j);
                    goto koko;
                }
                swap(i, j);
            }
    }

    else
        while (1)
        {
            i = rand() % len;
            j = rand() % len;
            swap(i, j);
            tempvalue = evaluate();
            swap(i, j);
            if (tempvalue < min_value)
            {
                min_value = tempvalue;
                min_col = i;
                min_row = j;
                // swap(i, j);
                break;
            }
        }
koko:
    if (min_col == -1)
    { // 如果遍历了所有的邻居节点，也找不到更好的移动方式，那么就需要重新启动算法，初始棋局改变一下
        generation++;
        printf("\nAttempt %d failed!\n", generation);
        return -1;
    }
    times++;
    // printf("%d swaps completed->", times);
    printf("[%d]", min_value);
    swap(min_col, min_row); // 找到更好的移动方式，那么就以这个邻居进行下一次爬山
    return min_value;
}

/***  当遍历完所有邻居，也没有找到更好的邻居
 ***  那么随机重置solution，然后再用爬山法搜索
 ***  随机重启：邻居是邻域内的“微小”的扰动，增加扰动范围，比如随机交换times=20次
 ***/
void restart()
{
    int times = 4; // 随机交换解的次数，扰动大小,设置times>1即可
    for (int i = 0; i < times; ++i)
        swap(rand() % len, rand() % len);
    puts("Restart!");
}
