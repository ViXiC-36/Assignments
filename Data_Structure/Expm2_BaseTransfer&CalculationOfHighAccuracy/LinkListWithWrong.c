#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct node{
    struct node *lc,*rc,*fa;
    int data;
    int sz; //size，表示子树的大小
    int depth; //表示结点的深度
}node;

node *root;

int num;
node *ptr[120];

//程序的功能：insert新建一个结点，放入中序遍历第i个结点到第i+1个结点之间。
//getLCA 返回u,v两点的最近公共祖先

void insert(node *now,int pos){ //插入到中序遍历第pos个结点和第pos+1个结点之间(编号从1开始)
    if(root == NULL){
        root = (node*)malloc(sizeof(node));
        root->lc = root->rc = NULL;
        root->sz = 1;
        root->data = ++num;
        root->depth = 1;
        ptr[num] = root;
        return;
    }
    if(pos == 0 && now->lc == NULL){
        node *son = (node*)malloc(sizeof(node));
        now->lc = son;
        son -> sz = 1;
        son -> data = ++num;
        son -> depth = now ->depth + 1;
        ptr[num] = son;
    }else if(pos == now->sz && now->rc == NULL){
        node *son = (node*)malloc(sizeof(node));
        now -> lc = son;
        son -> sz = 1;
        son -> data = ++num;
        son -> depth = now->depth+1;
        ptr[num] = son;
    }else {
        int lsize = (now->lc == NULL) ? 0:now->lc->sz; 
    int rsize = (now->rc == NULL) ? 0:now->lc->sz;
    if(lsize <= pos) {//左边结点就够pos个了，结果是插入到左边，递归下去
            insert(now->lc,pos);
        
        }else{ //左边结点不够pos个，说明是插入到右边，那么我假装无视左边的结点和根
        rsize = (now->rc == NULL) ? 0:now->lc->sz;
            insert(now->rc,pos-lsize-1);
        }
    }
}

node* getLCA(node *u,node *v){
    if(u->depth < v->depth){
        node *temp = u;
        u = v;
        v = temp;
    }
    while(u->depth > v->depth) u = u->fa;
    while(u != v) u = u->fa,v = v->fa;
    return u;
}

int main(){
    insert(root,0);
    insert(root,0);
    insert(root,1);
    insert(root,0);
    insert(root,4);
    node * ans = getLCA(ptr[4],ptr[5]); // ans = 1;
    printf("%d\n",ans->data);
    return 0;
}
