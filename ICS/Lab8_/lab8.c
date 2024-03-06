#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define LENGTH 1
#define MAXLEN 12
#define STUDENT_ID_LAST_DIGIT 9

int lab1(int n)
{
    int IsEven = 1;
    IsEven = !(IsEven & n);
    if (IsEven)
        n = ~n + 1;
    int count = 0;
    for (int i = 0, testbit = 1; i < 16; i++, testbit = testbit << 1)
    {
        if (!(testbit & n))
            count++;
    }
    return (count + STUDENT_ID_LAST_DIGIT);
}

int lab2(int n)
{
    if (n == 1)
        return 3;
    int direction = 1;
    int f_n = 3;
    int testnum = 3;
    int flip = 0;
    for (int i = 1; i < n; i++, flip = 0)
    {
        f_n = 2 * f_n;
        if (direction)
            f_n += 2;
        else
            f_n -= 2;
        while (f_n > 4096)
            f_n -= 4096;
        // done updating the f_n
        testnum = f_n;
        while (testnum > 0)
            testnum -= 8;
        if (testnum == 0) // being the multiple of 8
            flip++;
        testnum = f_n - 8;
        while (testnum >= 1000)
            testnum -= 1000;
        while (testnum >= 100)
            testnum -= 100;
        while (testnum >= 10)
            testnum -= 10;
        if (testnum == 0) // last digit in decimal being 8
            flip++;
        if (flip > 0)
            direction = !direction;
    }
    return f_n;
}

int lab3(char *a, char *b)
{
    int diff = 999;
    int i = 0;
    do
    {
        diff = a[i] - b[i];
        i++;
        if (diff != 0)
            break;
    } while (a[i - 1] && b[i - 1]);
    return diff;
}

void Put_up(int, char **, int *);
void Remove(int, char **, int *);

void Put_up(int n, char **state, int *move)
{
    if (n > 1)
        Put_up(n - 1, state, move);
    // P(n - 1);
    if (n > 2)
        Remove(n - 2, state, move);
    // R(n - 2)
    state[*move][12 - n] = '0';
    (*move)++;
    //***
    for (int i = 0; i < 13; i++)
        state[*move][i] = state[(*move) - 1][i];
    //***
    // p(n)
    if (n > 2)
        Put_up(n - 2, state, move);
    // P(i - 2)
}

void Remove(int n, char **state, int *move)
{
    if (n > 2)
        Remove(n - 2, state, move);
    // R(n - 2)
    state[*move][12 - n] = '1';
    (*move)++;
    //***
    for (int i = 0; i < 13; i++)
        state[*move][i] = state[(*move) - 1][i];
    //***
    // r(n)
    if (n > 2)
        Put_up(n - 2, state, move);
    // P(n - 2)
    if (n > 1)
        Remove(n - 1, state, move);
    // R(n - 1)
}

int lab4(char **state, int n)
{
    int *move = (int *)malloc(sizeof(int));
    *move = 0;
    if (n == 0)
        return 0;
    for (int i = 0; i < 12; i++)
        state[0][i] = '0'; // first state
    state[0][12] = 0; // ending signal
    Remove(n, state, move);
    return *move;
}

int main()
{
    printf("%d\n", lab1(6280));
    printf("%d\n", lab2(100));
    printf("%d\n", lab3("DsTAs", "DsTA"));
    char **mem = (char **)malloc(sizeof(char *) * 3000);
    for (int i = 0; i < 3000; i++)
        mem[i] = (char *)malloc(sizeof(char) * 13);
    int move = lab4(mem, 1);
    for (int i = 0; i < move; i++)
        printf("%s--", mem[i]);



}
