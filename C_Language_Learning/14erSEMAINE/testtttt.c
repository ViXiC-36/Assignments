#include <stdio.h>
#include <stdlib.h>
int main ()
{
    int a, key = 0;
    key = scanf("%d", &a);
    printf("%d %d", a, key);
    return 0;
}
// typedef struct node
// {
//     int data;
//     struct node *next;
// } node, *linklist;

// // node *startlist(node *l){//初始化单链表 并设置为空表
// //     l=(node *)malloc(sizeof(node));
// //     l->next=NULL;
// //     return l;
// // }

// void creatfromhead(node *l)
// { // 利用头插法建立单链表
//     node *p;
//     node *r = l;
//     int i;
//     scanf("%d", &i);
//     for (int j = 0; j < i; j++)
//     {
//         p = (node *)malloc(sizeof(node));
//         scanf("%d", &p->data);
//         p->next = r->next;
//         r->next = p;
//     }
// }

// void creatfromtail(node *l)
// { // 利用尾插法建立单链表
//     node *p;
//     node *r = l;
//     int i;
//     scanf("%d", &i);
//     for (int j = 0; j < i; j++)
//     {
//         p = (node *)malloc(sizeof(node)); // 建立一个新结点
//         scanf("%d", &p->data);
//         r->next = p;
//         r = p;
//     }
//     r->next = NULL;
// }

// void out(node *l)
// { // 输出链表
//     node *p = l->next;
//     while (p)
//     {
//         printf("%d ", p->data);
//         p = p->next;
//     }
// }

// void reverse(node *l, int left, int right)
// { // 翻转链表
//     node *p = l;
//     while (left > 1)
//     { // 找到需要翻转局部的最左边的前一个结点 记为p

//         p = p->next;
//         left--;
//         right--;
//     }
//     node *q = p->next; // 将p 后面的节点分离
//     p->next = NULL;
//     while (q && right > 0)
//     { // 将 right-left+1 个节点通过头插法接在p的后面 即局部反转
//         node *m = q;
//         q = q->next;
//         m->next = p->next;
//         p->next = m;
//         right--;
//     }
//     // 将分离的两个链表接在一起
//     while (p->next)
//     {
//         //      printf("%d",p->data);
//         p = p->next;
//     }
//     if (q)
//     {
//         //      printf("%d",q->data);
//         p->next = q;
//     }
// }

// int main()
// {
//     node *l, *m;
//     l = (node *)malloc(sizeof(node)); // 建立一个头结点 并动态分配存储空间
//     l->next = NULL;
//     creatfromtail(l);
//     int left, right;
//     scanf("%d %d", &left, &right);
//     reverse(l, left, right);
//     out(l);
//     return 0;
// }