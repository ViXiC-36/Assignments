#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
    int n, i, j, flag, type;
    int idt, tempvote;
    char namet[30] = {'\0'};
    flag = 0;
    int vote[100] = {0};
    struct candidate
    {
        int id;
        char name[30];
    };
    scanf("%d", &n);
    struct candidate cand[n];
    struct candidate tempcand;
    for (i = 0; i < n; i++)
    {
        scanf("%d %s", &cand[i].id, cand[i].name);
    }
    while (flag == 0)
    {
        scanf("%d", &type);
        switch (type)
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
                if ((strcmp(namet, cand[i].name)) == 0)
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
    for (i = 0; i < n - 1; i++)
    {
        for (j = i + 1; j < n; j++)
        {
            if (vote[i] > vote[j])
            {
                tempcand = cand[i];
                tempvote = vote[i];
                cand[i] = cand[j];
                vote[i] = vote[j];
                cand[j] = tempcand;
                vote[j] = tempvote;
            }
        }
    }
    for (i = 0; i < n - 1; i++)
    {
        for (j = i + 1; j < n; j++)
        {
            if (vote[j] == vote[i])
            {
                if (cand[i].id < cand[j].id)
                {
                    tempcand = cand[j];
                    cand[j] = cand[i];
                    cand[i] = tempcand;
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