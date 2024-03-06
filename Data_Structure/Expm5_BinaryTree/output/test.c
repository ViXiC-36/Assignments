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

int FindMax(bNode *root, int max)
{
    int lmax = root->data.value;
    int rmax = root->data.value;
    if (!root->lchild)
        lmax = (max > root->data.value) ? max : root->data.value;
    else
    {
        lmax = FindMax(root->lchild, lmax);
    }

    if (!root->rchild)
        rmax = (max > root->data.value) ? max : root->data.value;
    else
    {
        rmax = FindMax(root->rchild, rmax);
    }
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

bNode *buildBTreeByValue(int *value, int len)
{
    bNode *root = (bNode *)malloc(sizeof(bNode));
    if (!root)
        exit(0);
    int idx = 0;
    root->data.id = idx;
    root->data.value = value[idx];
    root->lchild = root->rchild = NULL;
    // cPrintNode(root);

    for (idx = 1; idx < len; ++idx)
    {
        // 生成新节点
        bNode *t = (bNode *)malloc(sizeof(bNode));
        if (!t)
            exit(0);
        t->data.id = idx;
        t->data.value = value[idx];
        t->lchild = t->rchild = NULL;
        // cPrintNode(t);

        // 查找新节点在二叉树的准确位置
        bNode *q; // p的双亲结点
        for (bNode *p = root; p; (value[idx] < p->data.value) ? (p = p->lchild) : (p = p->rchild))
            q = p;
        (value[idx] < q->data.value) ? (q->lchild = t) : (q->rchild = t); // 将新节点链入二叉树
        printf(", The address of the parent node: %lx\n", q);
    }
    return root;
}

int main()
{
    int val[] = {22, 32, 6, 12, 75, 9, 88, 13, 41, 7, 16, 17};
    int n = 12;

    // printf("\n测试二叉树生成 value:");
    bNode *t1 = buildBTreeByValue(val, n); // 测试由值数组生成二叉树
    int w = FindMax(t1, t1->data.value);
    int u = FindMin(t1, t1->data.value);
    printf("%d %d", w, u);
    // preTraverseTree(t1, add1);             // 测试先序遍历
    // inTraverseTree(t1, cPrintNode);        // 测试中序遍历
    // postTraverseTree(t1, cPrintNode);      // 测试后续遍历
    //	DestroyBTree(t1);
}