#include <stdio.h>
#include <stdlib.h>
typedef struct Polynomia
{
    int a;
    int e;
    struct Polynomia *next;
} node;
int n, *nn = &n;
node *CreateLinkListFromTail(int key)
{
    node *head, *p = NULL, *rear;
    n = 0;
    char x = ' ';
    head = rear = NULL;
    // while (x != '\n')
    if (key == 0)
    {
        while (x == ' ') // LES DIFFERENCES ICI!
        {
            p = (node *)malloc(sizeof(node));
            scanf("%d%d", &p->a, &p->e);
            (*nn)++;
            p->next = NULL;
            if (!head)
                head = p;
            else
                rear->next = p;
            rear = p;
            scanf("%c", &x);
        }
    }
    else
    {
        while (x == ' ' && scanf("%c", &x) != EOF) // LES DIFFERENCES ICI!
        {
            p = (node *)malloc(sizeof(node));
            scanf("%d%d", &p->a, &p->e);
            (*nn)++;
            p->next = NULL;
            if (!head)
                head = p;
            else
                rear->next = p;
            rear = p;
            scanf("%c", &x);
        }
    }
    p->next = NULL;
    return head;
}
node *Multiply_Merge_Sort(node *poly1, node *poly2, int num)
{
    /*CreateLinkList for Output*/
    node *head, *p = NULL, *rear;
    head = rear = NULL;
    while (num)
    {
        p = (node *)malloc(sizeof(node));
        num--;
        p->next = NULL;
        if (!head)
            head = p;
        else
            rear->next = p;
        rear = p;
    }
    p->next = NULL;
    /*Multiply*/
    p = poly1;
    node *pp = poly2, *q = head;
    while (p)
    {
        pp = poly2;
        while (pp)
        {
            q->a = p->a * pp->a;
            q->e = p->e + pp->e;
            q = q->next;
            pp = pp->next;
        }
        p = p->next;
    }
    /*Merge*/
    p = head;
    while (p)
    {
        pp = p->next;
        while (pp)
        {
            if (p->e == pp->e)
            {
                p->a += pp->a;
                q = p;
                while (q->next != pp)
                    q = q->next;
                /*Delete*/
                q->next = pp->next;
            }
            pp = pp->next;
        }
        p = p->next;
    }
    /*BubbleSort*/
    p = head;
    node *tail = NULL;                // Le plus important!!
    if (p == NULL || p->next == NULL) // zero or one element in the linklist;
        return head;
    while (p != tail)
    {
        while (p->next != tail)
        {
            if (p->e < p->next->e)
            {
                pp = p->next;
                p->next = pp->next;
                pp->next = p;
                if (p == head)
                {
                    head = pp;
                    continue;
                }
                else
                {
                    node *m = head;
                    while (m->next != p) // find the forward pointer of p;
                        m = m->next;
                    m->next = pp;
                    continue; // avoid excess moving of p;
                }
            }
            p = p->next;
        }
        tail = p; // ajust the tail;
        p = head; // initialization
    }
    return head;
}
void PrintfLinkList(node *head)
{
    node *p = head;
    while (p)
    {
        if (p->a != 0)
            printf("%d %d ", p->a, p->e);
        p = p->next;
    }
}
int main()
{
    node *head1, *head2, *head;
    int num = 1, key = 0;
    head1 = CreateLinkListFromTail(key);
    num *= *nn;
    key = 1;
    head2 = CreateLinkListFromTail(key);
    num *= *nn;
    head = Multiply_Merge_Sort(head1, head2, num);
    PrintfLinkList(head);
    return 0;
}