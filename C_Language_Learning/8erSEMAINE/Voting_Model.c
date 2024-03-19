#include <stdio.h>
#include <stdlib.h>
int main()
{
    int n, i, j, flag, c;
    int idt, tempid, tempvote;
    char namet[30], tempname[30];
    flag = 0;
    int *vote;
    struct candidate
    {
        int id;
        char name[30];
    };
    scanf("%d", &n);
    vote = (int *)malloc(n * sizeof(int));
    vote = {0};
    struct candidate cand[n];
    for (i = 0; i < n; i++)
    {
        scanf("%d %s", &cand[i].id, cand[i].name);
    }
    while (flag == 0)
    {
        scanf("%d", &c);
        switch (c)
        {
        case 0:
            scanf("%d", &idt);
            for (i = 0; i < n; i++)
            {
                if (idt == cand[i].id)
                {
                    vote[i] += 1;
                }
            };
            break;
        case 1:
            scanf("%s", namet);
            for (i = 0; i < n; i++)
            {
                if (namet == cand[i].name)
                {
                    vote[i] += 1;
                }
            };
            break;
        case 10:
            flag = 1;
            break;
        }
    }
    for (i = 0; i < n - 1; i++) // insertion sort
    {
        for (j = i + 1; j > 1; j--)
        {
            if (vote[j] < vote[j - 1])
            {
                tempvote = vote[j - 1];
                vote[j - 1] = vote[j];
                vote[j] = tempvote;
                tempid = cand[j - 1].id;
                cand[j - 1].id = cand[j].id;
                cand[j].id = tempid;
                tempname[30] = cand[j - 1].name[30];
                cand[j - 1].name[30] = cand[j].name[30];
                cand[j].name[30] = tempname[30];
            }
            else if (vote[j] == vote[j - 1])
            {
                if (cand[j].id > cand[j - 1].id)
                {
                    tempid = cand[j - 1].id;
                    cand[j - 1].id = cand[j].id;
                    cand[j].id = tempid;
                    tempname[30] = cand[j - 1].name[30];
                    cand[j - 1].name[30] = cand[j].name[30];
                    cand[j].name[30] = tempname[30];
                }
            }
        }
    }
    for (i = n - 1; i > -1; i--)
    {
        printf("%d %s %d\n", cand[i].id, cand[i].name, vote[i]);
    }
    return 0;
}