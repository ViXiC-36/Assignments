#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int id;
    int value;
} ElemType;

typedef struct tnode
{
    ElemType data;
    struct tnode *lchild;
    struct tnode *rchild;
} bNode, *bTree;

bNode *buildBTreeByValue(int *, int);
bNode *DeleteNode(bNode *, int);
int CommonAncestor(bNode *, int, int);
void GrowthPath(bNode *, int);
int MostDiff(bNode *);
// void preTraverseTree(bNode *, void (*ptrf)(bNode *));
// void inTraverseTree(bNode *, void (*ptrf)(bNode *));
// void postTraverseTree(bNode *, void (*ptrf)(bNode *));
void add1(bNode *a)
{
    a->data.value += 1;
}
void cPrintNode(bNode *a)
{
    printf("\n*(addr = %lx):(id=%2d)= %5d", a, a->data.id, a->data.value);
}

bNode *buildBTreeByValue(int *value, int len)
{
    bNode *root = (bNode *)malloc(sizeof(bNode));
    if (!root)
        exit(0);
    int idx = 0;
    root->data.id = idx;
    root->data.value = value[idx];
    root->lchild = root->rchild = NULL;
    cPrintNode(root);

    for (idx = 1; idx < len; ++idx)
    {
        // 生成新节点
        bNode *t = (bNode *)malloc(sizeof(bNode));
        if (!t)
            exit(0);
        t->data.id = idx;
        t->data.value = value[idx];
        t->lchild = t->rchild = NULL;
        cPrintNode(t);

        // 查找新节点在二叉树的准确位置
        bNode *q; // p的双亲结点
        for (bNode *p = root; p; (value[idx] < p->data.value) ? (p = p->lchild) : (p = p->rchild))
            q = p;
        (value[idx] < q->data.value) ? (q->lchild = t) : (q->rchild = t); // 将新节点链入二叉树
        printf(", The address of the parent node: %lx", q);
    }
    return root;
}

/***-下面的代码是实现先序遍历、中序遍历和后序遍历的模板，大多数二叉树的操作基于对它们的修改 ***/
// 先序遍历二叉树
void preTraverseTree(bNode *root, void (*ptrf)(bNode *a))
{
    if (root)
    { // 递归出口
        (*ptrf)(root);
        preTraverseTree(root->lchild, (*ptrf));
        preTraverseTree(root->rchild, (*ptrf));
    }
}

// 中序遍历二叉树
void inTraverseTree(bNode *root, void (*ptrf)(bNode *a))
{
    if (root)
    { // 递归出口
        inTraverseTree(root->lchild, (*ptrf));
        (*ptrf)(root);
        inTraverseTree(root->rchild, (*ptrf));
    }
}

// 后序遍历二叉树
void postTraverseTree(bNode *root, void (*ptrf)(bNode *a))
{
    if (root)
    { // 递归出口
        postTraverseTree(root->lchild, (*ptrf));
        postTraverseTree(root->rchild, (*ptrf));
        (*ptrf)(root);
    }
}
/*PART 1
DELETE THE CERTAIN NODES
*/
// WITH POSTORDER TRAVERSE TO DESTROY TREE
void DestroyBTree(bNode *root)
{
    if (root->lchild)
    {
        DestroyBTree(root->lchild);
        root->lchild = NULL;
    }
    if (root->rchild)
    {
        DestroyBTree(root->rchild);
        root->rchild = NULL;
    }
    if (!root->lchild && !root->rchild)
        free(root);
}

bNode *locateByVal(bNode *root, int value)
{
    if (!root)
        return NULL;
    if (root->data.value == value)
        return root;
    bNode *t = locateByVal(root->lchild, value);
    if (t)
        return t;
    return locateByVal(root->rchild, value);
}

// delete the nodes with the value "e" and its subtree;
bNode *DeleteNode(bNode *root, int e)
{
    bNode *p = NULL;
    int flag = 0;
    for (p = locateByVal(root, e); p; p = locateByVal(root, e))
    {
        if ((!p) && (!flag))
        { // No more such nodes && for the 1st time
            printf("No such node found!\n");
            return root;
        }
        flag++;
        DestroyBTree(p);
    }
    return root;
}

/*PART 2
FIND THE YOUNGEST COMMON ANCESTOR
*/
bNode *locateByID(bNode *root, int id)
{
    if (!root)
        return NULL;
    if (root->data.id == id)
        return root;
    bNode *t = locateByID(root->lchild, id);
    if (t)
        return t;
    return locateByID(root->rchild, id);
}

// Find the youngest common ancestor
int CommonAncestor(bNode *root, int id1, int id2)
{
    char id1_loc = 'n';
    char id2_loc = 'n';
    bNode *p = NULL;
    for (p = root; id1_loc == id2_loc; (id1_loc == 'l') ? (p = p->lchild) : (p = p->rchild))
    {
        if (locateByID(p->lchild, id1))
            id1_loc = 'l';
        else
            id1_loc = 'r';
        if (locateByID(p->rchild, id2))
            id2_loc = 'r';
        else
            id2_loc = 'l';
        if (id1_loc != id2_loc)
            break;
    }
    // when id1 and id2 have different location, the youngest ancestor is found
    return p->data.id;
}

/*PART 3
FIND THE PATH FROM ROOT TO ID*/
void GrowthPath(bNode *root, int id)
{
    printf("Root(%d)", root->data.id);
    bNode *p = NULL;
    p = root;
    while (p->data.id != id)
    {
        if (locateByID(p->lchild, id))
        {
            printf("->Left(%d)", p->lchild->data.id);
            p = p->lchild;
        }
        else
        {
            printf("->Right(%d)", p->rchild->data.id);
            p = p->rchild;
        }
    }   
}
/*PART 4
GET THE DIFFERENCE OF THE GREATEST VALUE AND THE LEAST VALUE
*/
int FindMax(bNode *root, int max)
{
    int lmax = root->data.value;
    int rmax = root->data.value;
    if (!root->lchild)
        lmax = (max > root->data.value) ? max : root->data.value;
    else
        lmax = FindMax(root->lchild, lmax);
    if (!root->rchild)
        rmax = (max > root->data.value) ? max : root->data.value;
    else
        rmax = FindMax(root->rchild, rmax);
    int temp = (lmax > rmax) ? lmax : rmax;
    max = (max > temp) ? max : temp;
    return max;
}

int FindMin(bNode *root, int min)
{
    int lmin = root->data.value;
    int rmin = root->data.value;
    if (!root->lchild)
        lmin = (min < root->data.value) ? min : root->data.value;
    else
        lmin = FindMin(root->lchild, lmin);
    if (!root->rchild)
        rmin = (min < root->data.value) ? min : root->data.value;
    else
        rmin = FindMin(root->rchild, rmin);
    int temp = (lmin < rmin) ? lmin : rmin;
    min = (min < temp) ? min : temp;
    return min;
}

int MostDiff(bNode *root)
{
    int max = root->data.value;
    max = FindMax(root, max);
    int min = root->data.value;
    min = FindMin(root, min);
    return (max - min);
}
int main()
{
    int val[] = {22, 32, 6, 12, 75, 9, 88, 13, 41, 7, 16, 17};
    int n = 12;

    bNode *t1 = buildBTreeByValue(val, n);
    
    printf("\nMax - Min = %d\n", MostDiff(t1));
    GrowthPath(t1, 11);

    int anc;
    anc = CommonAncestor(t1, 5, 7);
    printf("\nCommon ancestor's id: %d\n", anc);

    DeleteNode(t1, 12);
}