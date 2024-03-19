#include <stdio.h>
#include <stdlib.h>
typedef struct Node
{
    int num;
    struct Node *next;
} node;
node *CreateLinkListFromTail(void)
{
    node *head, *p, *rear;
    int num;
    char x = ' ';
    head = rear = NULL;
    while (x != '\n')
    {
        p = (node *)malloc(sizeof(node));
        scanf("%d", &num);
        p->next = NULL;
        p->num = num;
        if (!head)
            head = p;
        else
            rear->next = p;
        rear = p;
        scanf("%c", &x);
    }
    p->next = NULL;
    return head;
}
node *ReverseLinkList(node *head, int left, int right)
{
    if (left == right)
        return head;
    int ajust = 0, flag = right;
    if (left == 1)
        ajust = 1;
    node *p = head;
    while (left > 2) // Find the lHS one;
    {
        p = p->next;
        left--;
        right--;
    }
    node *q = p->next;
    p->next = NULL;        // koko made disconnect the part after the left-th
    while (q && right > 1) // reverse
    {
        node *m = q;
        q = q->next;
        m->next = p->next;
        p->next = m;
        right--;
    }
    while (p->next) // re-connect the apart ones;
        p = p->next;
    if (q)
        p->next = q;
    if (ajust == 1)
    {
        p = head;
        head = p->next;
        node *q = head;
        while (flag > 2)
        {
            q = q->next;
            flag--;
        }
        p->next = q->next;
        q->next = p;
    }
    return head;
}
void PrintfLinkList(node *head)
{
    node *p = head;
    while (p)
    {
        printf("%d ", p->num);
        p = p->next;
    }
}
int main()
{
    node *head;
    int left, right;
    head = CreateLinkListFromTail();
    scanf("%d%d", &left, &right);
    head = ReverseLbinkList(head, left, right);
    PrintfLinkList(head);
    return 0;
}