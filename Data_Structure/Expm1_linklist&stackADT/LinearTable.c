#include <stdio.h>
#include <stdlib.h>

#define ElemType int // in the situation of integer

typedef struct Pointer
{
    ElemType elem;
    struct Pointer *next;
} node, *list; // define one node of the linklist

node *InitList() // initialize
{
    node *p = (node *)malloc(sizeof(node)); // allocate new space for a head node
    if (!p)
    { // when space allocation failed
        printf("Initialization failed!\n");
        exit(0); // exit(0) means normal quitting while exit(1) means abnormal quitting
    }
    p->next = NULL; // place the pointer to null;
    return p;
}

void ClearList(node *p) // clear up
{
    node *q; // tool
    while (p->next != NULL)
    { // when not ended, delete the nodes 1 by 1
        q = p->next;
        p->next = q->next;
        free(q); // free off the memory of what q points
    }
}

void DestroyList(node *p) // clear up & eliminate the head node
{
    ClearList(p);
    free(p); // head node eliminated
}

int ListLength(list p) // get the length of the list
{
    int count = 0; // parameter
    while (p->next != NULL)
    { // while the linklist does not ended
        count++;
        p = p->next; // tugi e_j
    }
    return count;
}

int ListEmpty(list p) // Empty desuka_j?
{
    if (p->next == NULL)
        return 1; // hai_j
    return 0;     // iie_j
}

int GetElem(list p, int i, ElemType *e) // get the value and the location of the element
{
    int k = 0; // location sign
    while (p = p->next)
    {
        k++;
        if (k == i)
        {                 // located
            *e = p->elem; // save the value
            return k;     // return the location
        }
    }
    return 0;
}

node *LocateElem(list p, ElemType e) // get the address of the element
{
    while (p = p->next)
    {
        if (p->elem == e) // located
            return p;     // return the address of the wanted element
    }
    return NULL; // location not found
}

node *PriorElem(list p, node *q) // get the address of the prior element
{
    while (p->next)
    {
        if (p->next == q) // located
            return p;
        p = p->next; // tugi no_j node_e ni iku_j
    }
    return NULL; // failed
}

node *NextElem(list p, node *q) // get the address of the next element
{
    return q->next;
}

node *ListInsert(list p, int i, ElemType e) // insert an element at the certain location
{
    if (i < 1) // unvalid address
        return NULL;
    for (; p; p = p->next)
    {
        if (--i < 1) // find the location
        {
            node *q = (node *)malloc(sizeof(node)); // allocate space for a new node
            if (!q)                                 // when allocation failed
            {
                printf("Node allocation failed!\n");
                exit(0); // quit
            }
            q->next = p->next;
            p->next = q;
            q->elem = e; // insert!
            return q;    // return the node inserted
        }
    }
    return NULL;
}

int ListDelete(list p, int i, ElemType *e) // delete an element at the certain location
{
    if (i < 1) // unvalid location
        return 0;
    node *q = p;                      // tool
    for (p = p->next; p; p = p->next) // node[q]->node[p]->node->
    {
        if (--i < 1) // find the location
        {
            q->next = p->next; // skip the node p
            *e = p->elem;      // use e to save the value
            free(p);           // destroy the node
            return 1;          // kanryo sita_j
        }
        q = p; // move the pointers to examine the next nodes
    }
    return 0; // shippai sita_j
}

void ListTraverse(list p, void (*pfun)(node *p)) // announce the present contents
{                                                // pfun is used for calling other defined func. inside this func.
    printf("The length of the list: %d\n", ListLength(p));
    while (p = p->next)
        (*pfun)(p); // now the pfun is DebugNode
    printf("\n");
}

void DebugNode(node *p) // to debug a certain node
{                       // a func. waiting to be called...
    printf("node address >> %lx\nnode value == %d\n", p, p->elem);
}

void Add(list p)
{ // add a certain node to a number
    p->elem += 1000;
}

void PrintNode(list p)
{ // print a certain node
    printf("%d ", p->elem);
}

int main()
{
    node *head;                        // head node of the linklist
    void (*pfun)(node *p) = DebugNode; // define the pfun to be DebugNode

    head = InitList(); // create & initialize

    printf("The emptiness of the list: %d\n", ListEmpty(head));

    ListTraverse(head, pfun); // toravaasu_j
    ListInsert(head, 1, 111);
    ListInsert(head, 1, 222);
    ListInsert(head, 1, 333);
    ListInsert(head, 1, 444);
    ListTraverse(head, pfun); // toravaasu_j
    ListInsert(head, 1, 555);
    ListInsert(head, 1, 666);
    ListInsert(head, 1, 777);
    ListInsert(head, 1, 888);
    ListTraverse(head, pfun); // toravaasu_j
    ListInsert(head, 3, 607);
    ListInsert(head, 5, 506);
    ListInsert(head, 7, 405);
    ListInsert(head, 9, 304);
    ListTraverse(head, pfun); // toravaasu_j

    printf("The emptiness of the list: %d\n", ListEmpty(head));

    ElemType ei = 0; // tool
    printf("before aquiring the elem., ei: %d\n", ei);
    GetElem(head, 6, &ei);
    printf("after aquiring the elem., ei: %d\n\n", ei);

    node *q = LocateElem(head, 444);
    if (!q)
        printf("didn't find out");
    else
    {
        q = PriorElem(head, q);
        printf("the prior of the node: %d\n", q->elem);
        printf("the value of the node: %d\n", q->next->elem);
        if (q->next->next)
            printf("the next of the node: %d\n\n", NextElem(head, q->next)->elem);
        printf("\n");
    }

    printf("before deleting, ei: %d\n", ei);
    if (ListDelete(head, 4, &ei) == 1)

        printf("after deleting, ei: %d\n\n", ei);
    else
        printf("deleting failed!\n");
    ListTraverse(head, pfun);

    printf("every elem. adds to 1000\n");
    ListTraverse(head, Add);
    printf("new linklist:\n");
    ListTraverse(head, PrintNode); // print the new linklist

    DestroyList(head);
    // ClearList(head);
    //  ListEmpty(head);
    //  ListLength(head);
    //  GetElem(head, 6, 43);,m
    //  LocateElem(head, 43);

    // PriorElem(head, q);       // get the prior element
    // NextElem(head, q);        // get the next element
    // ListInsert(head, 9, 111); // insert a node
    // ListDelete(head, 7, 76);  // delete a node
    // ListTraverse(head, pfun); // traverse the whole list
}