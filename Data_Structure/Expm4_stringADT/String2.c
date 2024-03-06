#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    char *str;
    int length;
} Hstring;

Hstring *StrInit(Hstring *, char *);
void StrDestroy(Hstring *);
void StrClear(Hstring *);
int StrLength(char *);
int *KMPnext(Hstring *);
int Getnextval(Hstring *, int *, int);
int *KMPnextval(Hstring *, int *);
int StrMatch(Hstring *, char *);
Hstring *SubStr(Hstring *, int, int);
Hstring *StrReplace(Hstring *, char *, char *);
Hstring *StrConcat(Hstring *, Hstring *);
void StrTraverse(Hstring *);

int main()
{
    Hstring *a = NULL;
    Hstring *b = NULL;
    Hstring *c = NULL;
    Hstring *d = NULL;
    Hstring *e = NULL;

    a = StrInit(a, "abbabaaabababbabababaaaaabababaababa");
    b = StrInit(b, "abaabababa");
    c = StrInit(c, "ababaa");
    d = StrInit(d, "Chemical ");
    e = StrInit(e, "Hype Boy!");

    // StrClear();
    // StrLength();

    int match_start = StrMatch(a, c->str);
    if (match_start == -1)
        printf("Matching not found!\n");
    else
    {
        printf("%s\n", a->str);
        for (int i = 0; i < match_start; i++)
            printf(" ");
        printf("%s\n", c->str);
    }
    printf("\n");

    Hstring *f = NULL;
    f = SubStr(b, 4, 5);
    StrTraverse(f);
    printf("\n");

    StrTraverse(b);
    b = StrReplace(b, "aba", "ba");
    StrTraverse(b);
    printf("\n");

    StrTraverse(d);
    StrTraverse(e);
    d = StrConcat(d, e);
    StrTraverse(d);

    StrDestroy(a);
    StrDestroy(b);
    StrDestroy(c);
    StrDestroy(d);
    StrDestroy(e);
    StrDestroy(f);
}

Hstring *StrInit(Hstring *s, char *txt)
{
    int i;
    s = (Hstring *)malloc(sizeof(Hstring));
    s->str = (char *)malloc(sizeof(char));
    for (i = 0; txt[i] != 0; i++)
        s->str[i] = txt[i];
    s->str[i] = 0; // the signal of ending
    s->length = i;
    return s;
}

void StrClear(Hstring *s) // make all the characters to be \0
{
    s->str[0] = 0; // ending signal at the very beginning
    s->length = 0;
}

void StrDestroy(Hstring *s)
{
    StrClear(s);
    free(s);
}

int StrLength(char *s)
{
    int i;
    for (i = 0; s[i] != 0; i++)
        continue;
    return i;
}

int *KMPnext(Hstring *p) // process a pattern ztring
{
    int *next = (int *)malloc(sizeof(int) * (1 + p->length));
    next[0] = -1; // count the s from 1 instead of 0
    next[1] = 0;
    next[2] = 1;
    int i = 3;
    int k;
    for (; i <= p->length; i++)
    {
        k = next[i - 1];
        if (p->str[k - 1] != p->str[i - 2])
        {
            k = 1;
            if (p->str[k - 1] != p->str[i - 2])
            {
                k = next[k];
                next[i] = 1;
            }
            else
                next[i] = k + 1;
        }
        else
        {
            next[i] = k + 1;
        }
    }
    // for (i = 0; i <= p->length; i++)
    //     printf("%d ", next[i]);
    return next;
}

int Getnextval(Hstring *p, int *next, int i)
{
    if (i <= 1)
        return next[1];
    if (p->str[i - 1] != p->str[next[i] - 1])
        return next[i];
    else
        return Getnextval(p, next, next[i]);
}

int *KMPnextval(Hstring *p, int *next) // Process a pattern string
{
    int *nextval = (int *)malloc(sizeof(int) * (1 + p->length));
    nextval[0] = -1; // count from 1 instead of 0
    nextval[1] = 0;
    int i = 2;
    for (; i <= p->length; i++)
        nextval[i] = Getnextval(p, next, i);
    // for (i = 0; i <= p->length; i++)
    //     printf("%d ", nextval[i]);
    // printf("\n");
    return nextval;
}

int StrMatch(Hstring *s, char *txt)
{
    Hstring *sub = NULL;
    sub = StrInit(sub, txt);
    int *next = NULL;
    next = KMPnext(sub);
    int *nextval = NULL;
    nextval = KMPnextval(sub, next);

    int i = 0, j = 0; // i for main string, j for pattern string
    while ((i < s->length) && (j < sub->length))
    {
        if ((j == -1) || (s->str[i] == sub->str[j]))
        {
            i++;
            j++;
        }
        else
        {
            j = nextval[j + 1] - 1;
        }
    }
    if (j >= sub->length)
        return (i - sub->length); // return where the match begins in the main string
    else
        return -1; // failed
}

Hstring *StrConcat(Hstring *a, Hstring *b)
{
    Hstring *c = NULL;
    c = StrInit(c, a->str);
    c->length = a->length + b->length; // update the length
    int i;
    for (i = 0; i < a->length; i++)
        c->str[i] = a->str[i]; // put a in c
    for (; i < c->length; i++)
        c->str[i] = b->str[i - a->length]; // concat b after
    c->str[i] = 0;                         // the signal of ending
    return c;
}

Hstring *SubStr(Hstring *s, int loc, int len)
{
    Hstring *sub = NULL;
    sub = StrInit(sub, " ");
    sub->length = len;
    int i;
    for (i = 0; i < len; i++)
        sub->str[i] = s->str[i + loc];
    sub->str[i] = 0; // the signal of ending
    return sub;
}

Hstring *StrReplace(Hstring *s, char *old, char *new)
{
    Hstring *t = NULL;
    t = StrInit(t, s->str); // copy s, process t
    int loc[256];
    int times = 0; // times is the number of replaceable location
    int i, movement;
    movement = StrLength(new) - StrLength(old);
    loc[times] = StrMatch(t, old);
    while (loc[times] != -1)
    {
        /*Move, then fill in*/
        if (movement >= 0) // rightward
            for (i = t->length - 1; i >= loc[times]; i--)
                t->str[i + movement] = t->str[i]; // make room for new parts
        else                                      // leftward
            for (i = loc[times]; i < t->length; i++)
                t->str[i] = t->str[i - movement]; // make room for new parts
        for (i = 0; i < StrLength(new); i++)
            t->str[i + loc[times]] = 1; // fill in the new parts
        t->length = StrLength(t->str);  // update the length
        t->str[t->length] = 0;          // update the signal of ending
        /*Search for next replaceable location*/
        times++;
        loc[times] = StrMatch(t, old);
    }
    for (i = 0; i < times; i++)
        for (movement = 0; movement < StrLength(new); movement++)
            t->str[loc[i] + movement] = new[movement]; // fill in the new parts
    return t;
}

void StrTraverse(Hstring *s)
{
    printf("%s(%d)\n", s->str, s->length);
}