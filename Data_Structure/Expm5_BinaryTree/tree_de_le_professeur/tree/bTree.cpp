#ifndef _BITREE_CPP_
#define _BITREE_CPP_
// 二叉?相?的??代?
#include <stdio.h>
#include <stdlib.h>

// 定?存放?据的?型,假?是可以存放多??据的?构体?型
typedef struct
{
	int id;
	int value;
} ElemType;

// 定?二叉?的??
typedef struct tnode
{
	ElemType data;
	struct tnode *lchild;
	struct tnode *rchild;
} bNode;

#include "showGT.h" //展示?和?的API

void cPrintNode(bNode *);

/***-下面的代?是四种不同的构建二叉?的算法，已??入信息的不同而不同 ***/
// 构造二叉?（二叉排序?），?入?度?len的整???value
// value??第0?元素?根的value，后?value依次和根比?，若比根小，就和根的左子?比?；否?和右子?比?；
// 依次?推，若比??遇到左子?或右子??空，?以?value值构建新的???，并????的左子?或右子?。
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
		// 生成新??
		bNode *t = (bNode *)malloc(sizeof(bNode));
		if (!t)
			exit(0);
		t->data.id = idx;
		t->data.value = value[idx];
		t->lchild = t->rchild = NULL;
		cPrintNode(t);

		// 查找新??在二叉?的准确位置
		bNode *q; // p的????
		for (bNode *p = root; p; (value[idx] < p->data.value) ? p = p->lchild : p = p->rchild)
			q = p;
		(value[idx] < q->data.value) ? q->lchild = t : q->rchild = t; // ?新???入二叉?
		printf(", 其父??地址 %lx", q);
	}
	return root;
}

// 构造二叉?,?入?度?len的??edge和value,下?即?????id，
// edge[id]表示???id的??的????的??(0~len-1) ，根??的?????-1
// value????了??的?据域value值
// 算法思想：?每???构造一???，?它?的地址存在一?指???中；然后依据edge??些???接成二叉?
bNode *buildBTreeByEdge(int *value, int *edge, int len)
{
	// 首先需要?查edge??是否代表一棵二叉?：唯一的-1，0~len-1每??至多出?2次,edge[i]!=i.?里省略
	bNode **allnodes = (bNode **)malloc(sizeof(bNode *) * len); // len?指?
	if (!allnodes)
		exit(0);
	for (int i = 0; i < len; ++i)
	{
		allnodes[i] = (bNode *)malloc(sizeof(bNode));
		if (!(allnodes[i]))
			exit(0);
		allnodes[i]->data.id = i;
		allnodes[i]->data.value = value[i];
		allnodes[i]->lchild = allnodes[i]->rchild = NULL;
	}

	bNode *root;
	for (int i = 0; i < len; ++i)
	{ // 二叉?不唯一，左右子?可以互?，优先构造左子?
		if (edge[i] != -1)
			(allnodes[edge[i]]->lchild == NULL) ? allnodes[edge[i]]->lchild = allnodes[i] : allnodes[edge[i]]->rchild = allnodes[i];
		else
			root = allnodes[i];
	}
	return root;
}

// ??算法：构造二叉?,?入?度?len=2n+1的??prelist，二叉?的???量?n
// 先序序列prelist[i],若序列中遇到空??，其值?NULLNODE，prelist中有n+1?NULLNODE
#define NULLNODE -9999
bNode *buildBTreeByPrelist(int *prelist, int len)
{
	bNode *t;
	static int idx = 0; // ??中每次?用自身都需要??的“特殊”?量用???量或全局?量
	if (prelist[idx] == NULLNODE)
	{
		idx++;
		return NULL;
	}
	if (!(t = (bNode *)malloc(sizeof(bNode *))))
		exit(0);
	t->data.value = prelist[idx];
	t->data.id = idx;
	idx++; // 准???prelist[idx]的下一??据构建??,idx?法放入形?列表
	t->lchild = buildBTreeByPrelist(prelist, len);
	t->rchild = buildBTreeByPrelist(prelist, len);
	return t;
} // 如果prelist中的?据?法全部放入到一棵二叉?，如何??？（构造?束后 idx<len-1)
// ??形?列表中?法表示子??的“特征?”?，采用全局?量或???量??理

// ??算法(先序遍?)：构造二叉? ，?入先序序列pre和中序序列in，以及??序列各自的上界pu,iu和下界pl,il
bNode *buildBTreeByPI(int *pre, int pl, int pu, int *in, int il, int iu)
{
	printf("\n%d-%d,%d-%d", pl, pu, il, iu);
	int il1, iu1, il2, iu2, pl1, pl2, pu1, pu2; // 根??把中序序列分成??子序列，同?得到先徐序列的??子序列，?是子序列的下?
	if (pu - pl != iu - il)
		exit(0); // ?查?入??
	if (pu - pl < 0)
		return NULL; // 若序列?空，返回空??/空?
	bNode *t = (bNode *)malloc(sizeof(bNode));
	if (!t)
		exit(0);
	t->data.value = pre[pl];
	t->data.id = pl;
	for (int i = il; i <= iu; ++i)
	{
		if (in[i] == pre[pl])
		{
			iu1 = i - 1;
			il1 = il;
			il2 = i + 1;
			iu2 = iu; // 完成中序序列in的切割
			pl1 = pl + 1;
			pu1 = pl + (iu1 - il1 + 1);
			pl2 = pu1 + 1;
			pu2 = pu; // 完成先徐序列pre的切割
		}
	}
	t->lchild = buildBTreeByPI(pre, pl1, pu1, in, il1, iu1);
	t->rchild = buildBTreeByPI(pre, pl2, pu2, in, il2, iu2);
	return t;
}

/*** 二叉?的其它基本操作  ***/
// 查找?定??p的父?? , t非空?，表示已?找到，就不需要???用，直接返回
bNode *parent(bNode *root, bNode *p)
{
	bNode *t = NULL;
	if (!root || root == p)
		return NULL; // 根?父??，空?也?有p的父??

	if (p && (root->lchild == p || root->rchild == p))
		return root;
	if (root->lchild && !t)
		t = parent(root->lchild, p);
	if (root->rchild && !t)
		t = parent(root->rchild, p);
	return t;
}

// 由??的id（可以改成其它?据域的值）查找??，返回??指? 。(先序遍?）
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

// 采用后序遍????。思考：可以用先序遍??？
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

/***-下面的代?是????函? visit() 的不同??方式，???????的?理，函?名通常作?二叉?遍?函?的?? ***/
// 打印某???的信息,依据Elemtype的定?而修改,??版本（不?出存?地址）
void bPrintNode(bNode *a)
{
	printf("\n(id = %2d) = %5d", a->data.id, a->data.value);
}

// 打印某???的信息,依据Elemtype的定?而修改,??版本（?出存?地址）
void cPrintNode(bNode *a)
{
	printf("\n*(addr = %lx):(id=%2d)= %5d", a, a->data.id, a->data.value);
}

// ??函?值，???据域的value值+1
void add1(bNode *a)
{
	a->data.value += 1;
}

/***-下面的代?是??先序遍?、中序遍?和后序遍?的模板，大多?二叉?的操作基于?它?的修改 ***/
// 先序遍?二叉?
void preTraverseTree(bNode *root, void (*ptrf)(bNode *a))
{
	if (root)
	{ // ??出口
		(*ptrf)(root);
		preTraverseTree(root->lchild, (*ptrf));
		preTraverseTree(root->rchild, (*ptrf));
	}
}

// 中序遍?二叉?
void inTraverseTree(bNode *root, void (*ptrf)(bNode *a))
{
	if (root)
	{ // ??出口
		inTraverseTree(root->lchild, (*ptrf));
		(*ptrf)(root);
		inTraverseTree(root->rchild, (*ptrf));
	}
}

// 后序遍?二叉?
void postTraverseTree(bNode *root, void (*ptrf)(bNode *a))
{
	if (root)
	{ // ??出口
		postTraverseTree(root->lchild, (*ptrf));
		postTraverseTree(root->rchild, (*ptrf));
		(*ptrf)(root);
	}
}

/***-下面的代?用于?索化二叉?：?序遍??果以?表(?式?列)形式?出 ***/
// 以下构成一??式?列，存放二叉?的??的地址，用于?序遍?二叉?
struct qNode
{						// ?列??
	bNode *ptr;			// ?列的??包括的?据域是二叉???的指?
	struct qNode *next; // ?列的下一???，?列是??表
};

typedef struct queue
{
	struct qNode *front;
	struct qNode *rear;
} linkQueue;

// ?二叉?生成?序遍?的?列：分??索化。?入二叉?，?出?列
// ???列?成??表遍?一次，可以???序遍?
// ?算法也可以稍作修改即得到“?序遍?”算法（??一下）
linkQueue *ToHiraQueue(bNode *root)
{
	linkQueue *hQueue = (linkQueue *)malloc(sizeof(linkQueue));
	if (!hQueue)
		exit(0);
	if (!root)
	{
		hQueue->front = NULL;
		hQueue->rear = NULL;
		return hQueue;
	}

	struct qNode *head;												// ?索化?程中的??(不能修改hQueue->front，防止?失)，?尾直接用hQueue->rear
	struct qNode *t = (struct qNode *)malloc(sizeof(struct qNode)); // ?建?列哨兵??（???，不存放有效?据的??）
	if (!t)
		exit(0);
	hQueue->front = hQueue->rear = head = t; // 此?是空?列

	// root入?
	t = (struct qNode *)malloc(sizeof(struct qNode)); // ?建?列??
	if (!t)
		exit(0);
	t->ptr = root; // ?据域?值，指?next可以不用?值(why?)
	hQueue->rear->next = t;
	hQueue->rear = t;

	while (head != hQueue->rear)
	{					   // ?列不空 ,head是哨兵??，?据?效，有效?据?head->next?始
		head = head->next; // 出?（模?出?，因?要返回?索化的?列，所以不能修改?列的?指?)
		// printf("de-%lx,",head->ptr);	//打印?句，??用，查看入?、出??程
		if (head->ptr->lchild)
		{ // head->next存放?据（??）的左孩子非空，构建新?列??，入?
			t = (struct qNode *)malloc(sizeof(struct qNode));
			if (!t)
				exit(0);
			t->ptr = head->ptr->lchild; // 新??的?据域?值
			hQueue->rear->next = t;		// 新??接到?列尾部
			hQueue->rear = t;
			// printf("en-%lx,",t->ptr); //打印?句，??用，查看入?、出??程
		}
		if (head->ptr->rchild)
		{ // head存放?据（??）的右孩子非空，构建新?列??，入?
			t = (struct qNode *)malloc(sizeof(struct qNode));
			if (!t)
				exit(0);
			t->ptr = head->ptr->rchild; // 新??的?据域?值
			hQueue->rear->next = t;		// 新??接到?列尾部
			hQueue->rear = t;
			// printf("en-%lx,",t->ptr);//打印?句，??用，查看入?、出??程
		}
	}
	return hQueue;
} // 思考如何??先序/中序/后序遍?的?索化？并?出?索化后的?列

/*** 下面是一些典型?用 ***/
// 求二叉?的高度/深度
int deepth(bNode *root)
{
	if (!root)
		return 0;
	int d = deepth(root->lchild);
	int n = deepth(root->rchild);
	return (d > n) ? d + 1 : n + 1;
}

// 求二叉?度?2的???目
int node2(bNode *root)
{
	int c = 0;
	if (!root)
		return 0;
	if (root->lchild && root->rchild)
		c = 1;
	return c + node2(root->lchild) + node2(root->rchild);
}

// 求二叉?度?1的???目
int node1(bNode *root)
{
	int c = 0;
	if (!root)
		return 0;
	if ((!root->lchild && root->rchild) || (root->lchild && !root->rchild))
		c = 1;
	return c + node1(root->lchild) + node1(root->rchild);
}

// 求二叉?度?0的???目 (?子???目）
int node0(bNode *root)
{
	if (!root)
		return 0;
	if (!root->lchild && !root->rchild)
		return 1;
	return node0(root->lchild) + node0(root->rchild);
}

// 求二叉?度?0的???目的value之和
int value0(bNode *root)
{
	if (!root)
		return 0;
	if (!root->lchild && !root->rchild)
		return root->data.value;
	return value0(root->lchild) + value0(root->rchild);
}

int main()
{
	int val[] = {22, 32, 6, 12, 75, 9, 88, 13, 41, 7, 16, 17};
	int n = 12;

	printf("\n??二叉?生成 value:");
	bNode *t1 = buildBTreeByValue(val, n); // ??由值??生成二叉?
	preTraverseTree(t1, add1);			   // ??先序遍?
	inTraverseTree(t1, cPrintNode);		   // ??中序遍?
	postTraverseTree(t1, cPrintNode);	   // ??后?遍?
	/*	DestroyBTree(t1);

		printf("\n??二叉?生成 edge :");
		int edge[7]={5,6,6,1,2,2,-1}; //增加???
		t1 = buildBTreeByEdge(val,edge,n); //??由值??和?生成二叉?
		preTraverseTree(t1,bPrintNode); //??先序遍?
		inTraverseTree(t1,add1);  //??中序遍?
		postTraverseTree(t1,cPrintNode);//??后?遍?
		DestroyBTree(t1);

		printf("\n??二叉?生成 Prelist:");
		int prelist[15]={17,32,41,-9999,-9999,-9999,13,7,-9999,-9999,16,22,-9999,-9999,-9999};
		t1 = buildBTreeByPrelist(prelist,15);
		preTraverseTree(t1,cPrintNode); //??先序遍?
		inTraverseTree(t1,cPrintNode);  //??中序遍?
		postTraverseTree(t1,bPrintNode);//??后?遍?

		//???序?索化
		printf("\n???序?索化:");
		linkQueue *qlist =  ToHiraQueue(t1);
		for(struct qNode *p = qlist->front;p!=qlist->rear;p = p->next)
			printf("%d, ",p->next->ptr->data.value); //打印?索化?表
		printf("\n");

		//????查找和求父??
		printf("\n????查找和求父??:");
		bNode *tn = locateByID(t1,2);
		if (!tn)
			printf("\n?找到??");
		else{
			cPrintNode(tn);
			printf("\n父???：");
			tn=parent(t1,tn);
			if (!tn)
				printf("?找到");
			else
				cPrintNode(tn);
		}
		DestroyBTree(t1);

		//??先序序列和中序序列构造二叉?
		printf("\n??二叉?生成 PI:");
		int pre[]={17,32,41,13,7,16,22};
		int in[]={41,32,17,7,13,22,16};
		t1=buildBTreeByPI(pre,0,n-1,in,0,n-1);
		if (t1){
			preTraverseTree(t1,cPrintNode); //??先序遍?
			inTraverseTree(t1,cPrintNode);  //??中序遍?
			postTraverseTree(t1,cPrintNode);//??后?遍?
		}
	*/
	saveTree(t1, "sg.html");

	// 典型?用??
	printf("\n?高度 %d ", deepth(t1));
	printf("\n?度?2的???目 %d ", node2(t1));
	printf("\n?度?0的???目 %d ", node0(t1));
	printf("\n?度?1的???目 %d ", node1(t1));
	printf("\n?度?0的??value之和 %d ", value0(t1));

	DestroyBTree(t1);
	return 1;
}

#endif
