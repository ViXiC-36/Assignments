#include <stdio.h>
int Suit(char x)
{
    if (x == 'D')
        return 101;
    if (x == 'C')
        return 102;
    if (x == 'H')
        return 103;
    if (x == 'S')
        return 104;
    else
        return -1;
}
int Levl(char x)
{
    if (x == 'A')
        return 1;
    if ((x >= '2') && (x <= '9'))
        return x - '0';
    if (x == 'T')
        return 10;
    if (x == 'J')
        return 11;
    if (x == 'Q')
        return 12;
    if (x == 'K')
        return 13;
    else
        return -1;
}
void Initialize(int (*nought)[5])
{
    for (int i = 0; i < 5; i++)
    {
        *(*nought + i) = 0;
        *(*(nought + 1) + i) = 0;
    }
}
int main()
{
    int i, j, jj, n, tmp0, tmp1, hand = 0; // n for counting cards;
    char allcards[2][1000] = {{0, 0}};
    int card[2][5] = {{0, 0}};
    int(*p)[5] = card;
    for (i = 1;; i++)
    {
        scanf("%c%c", &allcards[0][i - 1], &allcards[1][i - 1]);
        if ((i % 5 == 1) && (allcards[0][i - 1] == '0'))
            break;
        getchar();
        if (i % 5 == 0)
        {
            getchar(); // not needed when debugging;
            hand++;
        }
    }
    n = 0;
    while (hand)
    {
        for (i = n, j = 0; j < 5; i++, j++)
        {
            card[0][j] = Suit(allcards[0][i]);
            card[1][j] = Levl(allcards[1][i]);
        }
        hand--;
        n += 5;
        /*Illegal*/
        int flag = 1; // flag for illegal;
        for (i = 0; i < 5; i++)
        {
            if (card[0][i] == -1)
            {
                flag = 0;
                break;
            }
            if (card[1][i] == -1)
            {
                flag = 0;
                break;
            }
        }
        for (i = 0; i < 4; i++)
        {
            for (j = i + 1; j < 5; j++)
            {
                if ((card[0][i] == card[0][j]) && (card[1][i] == card[1][j]))
                    flag = 0;
            }
        }
        if (!flag)
        {
            printf("Invalid\n");
            Initialize(p);
            continue;
        }
        /*Sort*/
        for (i = 0; i < 4; i++)
        {
            for (j = i + 1; j < 5; j++)
            {
                if (card[1][i] >= card[1][j])
                {
                    tmp0 = card[0][i];
                    tmp1 = card[1][i];
                    card[0][i] = card[0][j];
                    card[1][i] = card[1][j];
                    card[0][j] = tmp0;
                    card[1][j] = tmp1;
                }
            }
        }
        /*Straight Flush*/
        int flush = 0; // flush means all of one suit;
        j = card[0][0];
        if ((card[0][1] == j) && (card[0][2] == j) && (card[0][3] == j) && (card[0][4] == j))
            flush++;
        int str8 = 0; // straight means in perfet order;
        for (i = 0; i < 4; i++)
        {
            if (card[1][i] + 1 == card[1][i + 1])
                str8++;
            else
                str8 -= 10;
        }
        if ((str8 > 0) && (flush == 1))
        {
            printf("Straight Flush\n");
            Initialize(p);
            continue;
        }
        /*Four of A Kind*/
        // levels already sorted!
        j = card[1][0];  // j is the level of the 1st card;
        jj = card[1][4]; // jj is the level of the 5th card;
        int four_of_a_kind = 0;
        if ((card[1][0] == j) && (card[1][1] == j) && (card[1][2] == j) && (card[1][3] == j))
            four_of_a_kind++;
        if ((card[1][1] == jj) && (card[1][2] == jj) && (card[1][3] == jj) && (card[1][4] == jj))
            four_of_a_kind++;
        if (four_of_a_kind != 0)
        {
            printf("Four of A Kind\n");
            Initialize(p);
            continue;
        }
        /*Full House*/
        int full_house = 0;
        if ((card[1][0] == j) && (card[1][1] == j) && (card[1][2] == j) && (card[1][3] == jj) && (card[1][4] == jj))
            full_house++;
        if ((card[1][4] == jj) && (card[1][3] == jj) && (card[1][2] == jj) && (card[1][1] == j) && (card[1][0] == j))
            full_house++;
        if (full_house == 1)
        {
            printf("Full House\n");
            Initialize(p);
            continue;
        }
        /*Flush*/
        if (flush == 1)
        {
            printf("Flush\n");
            Initialize(p);
            continue;
        }
        /*Straight*/
        if (str8 > 1)
        {
            printf("Straight\n");
            Initialize(p);
            continue;
        }
        /*Three of A Kind*/
        int three_of_a_kind = 0;
        int jjj = card[1][2]; // jjj is the level of the 3rd card;
        if ((card[1][1] == j) && (card[1][2] == j))
            three_of_a_kind++;
        if ((card[1][1] == jjj) && (card[1][3] == jjj))
            three_of_a_kind++;
        if ((card[1][2] == jj) && (card[1][3] == jj))
            three_of_a_kind++;
        if (three_of_a_kind == 1)
        {
            printf("Three of A Kind\n");
            Initialize(p);
            continue;
        }
        /*Two Pairs*/
        int pair = 0;
        for (i = 0; i < 4; i++)
            if (card[1][i] == card[1][i + 1])
                pair++;
        if (pair == 2)
        {
            printf("Two Pairs\n");
            Initialize(p);
            continue;
        }
        /*Pair*/
        if (pair == 1)
        {
            printf("Pair\n");
            Initialize(p);
            continue;
        }
        /*Other*/
        else
        {
            printf("Other\n");
            Initialize(p);
            continue;
        }
    }
    return 0;
}