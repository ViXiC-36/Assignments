#include <cstdint>
#include <iostream>
#include <fstream>
#include <bitset>

// #define LENGTH 3
#define MAXLEN 100
#define STUDENT_ID_LAST_DIGIT 9

int16_t lab1(int16_t n)
{
    int IsOdd = 1;
    IsOdd = IsOdd & n;
    if (IsOdd)
        n = n;
    else
        n = ~n + 1;
    int count = 16;
    for (int i = 0, testbit = 1; i < 16; i++, testbit = testbit << 1)
    {
        if (testbit & n)
            count--;
    }
    return (count + STUDENT_ID_LAST_DIGIT);
}

int16_t lab2(int16_t n)
{
    if (n == 1)
        return 3;
    int direction = 1;
    int f_n = 3;
    int testnum = 3;
    int flip = 0;
    for (int i = 1; i < n; i++, flip = 0)
    {
        f_n = f_n + f_n;
        if (direction)
            f_n = f_n + 2;
        else
            f_n = f_n - 2;
        while (f_n > 4096)
            f_n = f_n - 4096;
        // done updating the f_n
        testnum = f_n;
        while (testnum > 0)
            testnum = testnum - 8;
        if (testnum == 0) // being the multiple of 8
            flip++;
        testnum = f_n - 8;
        while (testnum >= 1000)
            testnum = testnum - 1000;
        while (testnum >= 100)
            testnum = testnum - 100;
        while (testnum >= 10)
            testnum = testnum - 10;
        if (testnum == 0) // last digit in decimal being 8
            flip++;
        if (flip > 0)
        {
            if (direction == 1)
                direction = 0;
            else if (direction == 0)
                direction = 1;
        }
    }
    return f_n;
}

int16_t lab3(char a[], char b[])
{
    int diff = 999;
    int i = 0;
    do
    {
        diff = a[i] - b[i];
        i++;
        if (diff != 0)
            break;
    } while (a[i - 1] & b[i - 1]);
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
    state[*move][16 - n] = '0';
    (*move)++;
    //***
    for (int i = 0; i < 17; i++)
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
    state[*move][16 - n] = '1';
    (*move)++;
    //***
    for (int i = 0; i < 17; i++)
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
    for (int i = 0; i < 16; i++)
        state[0][i] = '0'; // first state
    state[0][16] = 0;      // ending signal
    Remove(n, state, move);
    return *move;
}

int MUL_(int a, int b)
{
    int c = 0;
    for (int i = 0; i < b; i++)
        c = c + a;
    return c;
}

int main()
{
    std::fstream file;
    file.open("test.txt", std::ios::in);

    // lab1
    int16_t n = 0;
    std::cout << "===== lab1 =====" << std::endl;
    for (int i = 0; i < LENGTH; ++i)
    {
        file >> n;
        std::cout << lab1(n) << std::endl;
    }

    // lab2
    std::cout << "===== lab2 =====" << std::endl;
    for (int i = 0; i < LENGTH; ++i)
    {
        file >> n;
        std::cout << lab2(n) << std::endl;
    }

    // lab3
    std::cout << "===== lab3 =====" << std::endl;
    char s1[MAXLEN];
    char s2[MAXLEN];
    for (int i = 0; i < LENGTH; ++i)
    {
        file >> s1 >> s2;
        std::cout << lab3(s1, s2) << std::endl;
    }

    // lab4
    std::cout << "===== lab4 =====" << std::endl;
    int16_t move;
    for (int i = 0; i < LENGTH; ++i)
    {
        file >> n;
        char **mem = (char **)malloc(MUL_(sizeof(char *), 3000));
        for (int i = 0; i < 3000; i++)
            mem[i] = (char *)malloc(MUL_(sizeof(char), 17));
        move = lab4(mem, n);
        for (int j = 0; j < move; ++j)
        {
            std::cout << mem[j] << std::endl;
        }
    }

    file.close();
    return 0;
}