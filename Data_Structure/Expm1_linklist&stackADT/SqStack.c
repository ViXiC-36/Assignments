#include <stdio.h>
#include <stdlib.h>

#define STACK_INIT_SIZE 100 // define in the 1st place
#define STACK_INCREMENT 10

unsigned int_stacksize; // situ. int
int *int_stacktop_ptr;  // top ptr
int *int_stackbase_ptr; // base poiter

#define InitStack(stack)                                                      \
    stack##_stackbase_ptr = (stack *)malloc(sizeof(stack) * STACK_INIT_SIZE); \
    if (stack##_stackbase_ptr)                                                \
    {                                                                         \
        stack##_stacktop_ptr = stack##_stackbase_ptr;                         \
        stack##_stacksize = STACK_INIT_SIZE;                                  \
    }                                                                         \
    else                                                                      \
        exit(0)
// allocate space, initialize the stack if allocation achieved, else quit
#define StackEmpty(stack) stack##_stacktop_ptr == stack##_stackbase_ptr ? 1 : 0
// judge if empty
#define GetTop(stack, e) stack##_stacktop_ptr == stack##_stackbase_ptr ? 0 : (e = *(stack##_stacktop_ptr - 1), 1)
// get the top when the stack is not empty
#define ClearStack(stack) stack##_stacktop_ptr = stack##_stackbase_ptr
// clear up the stack
#define DestroyStack(stack) free(stack##_stackbase_ptr)
// clear up then free up the space occupied
#define StackLength(stack) stack##_stacktop_ptr - stack##_stackbase_ptr
// get the length
#define Pop(stack, e) (stack##_stackbase_ptr == stack##_stacktop_ptr) ? 0 : (e = *(--stack##_stacktop_ptr), 1)
// pop out the top if the stack is not empty
#define Push(stack, e)                                                                                                         \
    if (stack##_stacktop_ptr - stack##_stackbase_ptr >= stack##_stacksize)                                                     \
    {                                                                                                                          \
        stack##_stackbase_ptr = (stack *)realloc(stack##_stacktop_ptr, sizeof(stack) * (stack##_stacksize + STACK_INCREMENT)); \
        if (!stack##_stackbase_ptr)                                                                                            \
            exit(0);                                                                                                           \
        stack##_stacktop_ptr = stack##_stackbase_ptr + stack##_stacksize;                                                      \
        stack##_stacksize += STACK_INCREMENT;                                                                                  \
    }                                                                                                                          \
    *(stack##_stacktop_ptr++) = e
// push in a new element. when the stack is full then expand the size before pushing

/*tugi wa_j definitions of other types of stacks*/

unsigned char_stacksize;  // situ. char
char *char_stacktop_ptr;  // top
char *char_stackbase_ptr; // base

typedef struct node
{ // define the form of the struct node, which is an element of the stack
    int data[10];
    float x, y; // whateverrrrrr
} tnode;

unsigned tnode_stacksize;   // situ. struct node
tnode *tnode_stacktop_ptr;  // top
tnode *tnode_stackbase_ptr; // base

int main()
{
    InitStack(int);
    InitStack(char);
    InitStack(tnode); // shuushika_j

    // test the integer stack

    int x = 0;
    char c = 'i';
    tnode node;
    if (Pop(int, x))
        printf("Popping achieved %d\n", x);
    else
        printf("Stack empty! Nothing pops out.\n");

    printf("Now %d element(s) inside the stack\n", StackLength(int));

    if (StackEmpty(int))
        printf("Stack is empty.\n");

    Push(int, 212);
    printf("Now %d element(s) inside the stack\n", StackLength(int));

    Push(int, 434);
    Push(int, 656);
    printf("Now %d element(s) inside the stack\n", StackLength(int));

    if (Pop(int, x))
        printf("Popping achieved %d\n", x);
    else
        printf("Stack empty! Nothing pops out.\n");
    printf("Now %d element(s) inside the stack\n", StackLength(int));

    if (StackEmpty(int))
        printf("Stack empty! Can't get top.\n");
    else if (GetTop(int, x))
        printf("Now the top element is %d\n", x);
    printf("Now %d element(s) inside the stack\n", StackLength(int));

    DestroyStack(int);
}