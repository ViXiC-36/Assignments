#include <stdio.h>
#include <stdlib.h>

#define STACK_INIT_SIZE 100
#define STACK_INCREMENT 10

typedef int ElemType;

typedef struct SequenceStack
{
    ElemType *top;
    ElemType *btm;
    int stacksize;
} *SqStack, sequencestack;

unsigned int_stacksize;
int *S_int_top;
int *S_int_btm;

SqStack InitStack(SqStack S)
{ // initialize the stack return the address of the stack
    S->btm = (ElemType *)malloc(STACK_INIT_SIZE * sizeof(ElemType));
    if (!S->btm)
        exit(0);
    S->top = S->btm;
    S->stacksize = STACK_INIT_SIZE;
    return S;
}

int StackEmpty(SqStack S)
{ // return 1 when empty otherwise 0
    if (S->btm == S->top)
        return 1;
    return 0;
}

int GetTop(SqStack S, ElemType *e)
{ // return 1 when the top elem, which is e, is aquired. return 0 when the stack is empty
    if (S->btm == S->top)
        return 0;
    *e = *(S->top - 1);
    return 1;
}

int Pop(SqStack S, ElemType *e)
{ // return 1 when successful otherwise 0
    if (S->btm == S->top)
        return 0;
    S->top--;
    *e = *S->top;
    return 1;
}

int Push(SqStack S, ElemType e)
{ // return 1 when successful otherwise 0. if the stack is full, create more space to store the new elem.
    if (S->top - S->btm >= S->stacksize)
    {
        ElemType *tmp = (ElemType *)realloc(S->btm, sizeof(ElemType) * (STACK_INCREMENT + S->stacksize));
        if (!tmp)
            return 0;
        S->btm = tmp;
        S->top = S->btm + S->stacksize;
        S->stacksize += STACK_INCREMENT;
    }
    *(S->top) = e;
    S->top++;
    return 1;
}

int StackLength(SqStack S)
{ // the present length (instead of the size) of the stack
    return (S->top - S->btm);
}

void ClearStack(SqStack S)
{ // clear up
    S->top = S->btm;
}

void DestroyStack(SqStack S)
{ // destroy the storage which was allocated in the first place
    free(S->btm);
}

/*tugi wa_j definitions of other types of stacks*/

unsigned char_stacksize;
char *S_char_top;
char *S_char_btm;

typedef struct node
{
    int data[10];
    float x, y;
} tnode;

unsigned tnode_stacksize;
tnode *S_tnode_top;
tnode *S_tnode_btm;

int main()
{
    SqStack Sint = (SqStack *)malloc(sizeof(SqStack));
    
    InitStack(Sint);
    // InitStack(Schar);
    // InitStack(Stnode);

    // test the integer stack

    int x = 0;
    if (Pop(Sint, &x))
        printf("Popping achieved %d\n", x);
    else
        printf("Stack empty! Nothing pops out.\n");

    printf("Now %d element(s) inside the stack\n", StackLength(Sint));

    if (StackEmpty(Sint))
        printf("Stack is empty.\n");

    Push(Sint, 212);
    printf("Now %d element(s) inside the stack\n", StackLength(Sint));

    Push(Sint, 434);
    Push(Sint, 656);
    printf("Now %d element(s) inside the stack\n", StackLength(Sint));

    if (Pop(Sint, &x))
        printf("Popping achieved %d\n", x);
    else
        printf("Stack empty! Nothing pops out.\n");
    printf("Now %d element(s) inside the stack\n", StackLength(Sint));

    if (StackEmpty(Sint))
        printf("Stack empty! Can't get top.\n");
    else if (GetTop(Sint, &x))
        printf("Now the top element is %d\n", x);
    printf("Now %d element(s) inside the stack\n", StackLength(Sint));

    DestroyStack(Sint);
}