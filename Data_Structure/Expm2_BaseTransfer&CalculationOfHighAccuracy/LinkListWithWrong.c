#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct node{
    struct node *lc,*rc,*fa;
    int data;
    int sz; //size����ʾ�����Ĵ�С
    int depth; //��ʾ�������
}node;

node *root;

int num;
node *ptr[120];

//����Ĺ��ܣ�insert�½�һ����㣬�������������i����㵽��i+1�����֮�䡣
//getLCA ����u,v����������������

void insert(node *now,int pos){ //���뵽���������pos�����͵�pos+1�����֮��(��Ŵ�1��ʼ)
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
    if(lsize <= pos) {//��߽��͹�pos���ˣ�����ǲ��뵽��ߣ��ݹ���ȥ
            insert(now->lc,pos);
        
        }else{ //��߽�㲻��pos����˵���ǲ��뵽�ұߣ���ô�Ҽ�װ������ߵĽ��͸�
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
