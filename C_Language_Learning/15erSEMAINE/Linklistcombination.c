#include <stdio.h>
#include <stdlib.h>
typedef struct student
{
    int No;
    int score;
    struct student *next;
} node;
node *CreateLinklistFromTail(int n)
{
    node *head, *p = NULL, *rear;
    head = rear = NULL;
    while (n > 0)
    {
        p = (node *)malloc(sizeof(node));
        scanf("%d", &p->No);
        scanf("%d", &p->score);
        p->next = NULL;
        //printf("%d", head);
        if (!head)/*head == null || (int)0, !head == 1*/
            head = p;
        else
            rear->next = p;
        rear = p;
        n--;
    }
    p->next = NULL;
    return head;
}
node *Combine_Sort(node *headn, node *headm, int n)
{
    /*Combination*/
    node *p = headn;
    while (n > 1)
    {
        p = p->next;
        n--;
    }
    p->next = headm;
    /*BubbleSort*/
    p = headn;
    node *tail = NULL;                // Le plus important!!
    if (p == NULL || p->next == NULL) // zero or one element in the linklist;
        return headn;
    while (p != tail)
    {
        while (p->next != tail)
        {
            if (p->No > p->next->No)
            {
                node *pp = p->next;
                p->next = pp->next;
                pp->next = p;
                if (p == headn)
                {
                    headn = pp;
                    continue;
                }
                else
                {
                    node *m = headn;
                    while (m->next != p) // find the forward pointer of p;
                        m = m->next;
                    m->next = pp;
                    continue; // avoid excess moving of p;
                }
            }
            p = p->next;
        }
        tail = p;  // ajust the tail;
        p = headn; // initialization
    }
    return headn;
}
void PrintfLinkList(node *head)
{
    node *p = head;
    while (p)
    {
        printf("%d %d\n", p->No, p->score);
        p = p->next;
    }
}
int main()
{
    int n, m;
    node *headn, *headm, *head;
    scanf("%d%d", &n, &m);
    headn = CreateLinklistFromTail(n);
    headm = CreateLinklistFromTail(m);
    head = Combine_Sort(headn, headm, n);
    PrintfLinkList(head);
    return 0;
}