#ifndef _BITREE_CPP_
#define _BITREE_CPP_
// �G�e?��?��??�N?
#include <stdio.h>
#include <stdlib.h>

// �w?�s��?�u��?��,��?�O�i�H�s��h??�u��?���^?��
typedef struct
{
	int id;
	int value;
} ElemType;

// �w?�G�e?��??
typedef struct tnode
{
	ElemType data;
	struct tnode *lchild;
	struct tnode *rchild;
} bNode;

#include "showGT.h" //�i��?�M?��API

void cPrintNode(bNode *);

/***-�U�����N?�O�|�����P���۫ؤG�e?����k�A�w??�J�H�������P�Ӥ��P ***/
// �۳y�G�e?�]�G�e�Ƨ�?�^�A?�J?��?len����???value
// value??��0?����?�ڪ�value�A�Z?value�̦��M�ڤ�?�A�Y��ڤp�A�N�M�ڪ����l?��?�F�_?�M�k�l?��?�F
// �̦�?���A�Y��??�J�쥪�l?�Υk�l??�šA?�H?value���۫طs��???�A�}????�����l?�Υk�l?�C
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
		// �ͦ��s??
		bNode *t = (bNode *)malloc(sizeof(bNode));
		if (!t)
			exit(0);
		t->data.id = idx;
		t->data.value = value[idx];
		t->lchild = t->rchild = NULL;
		cPrintNode(t);

		// �d��s??�b�G�e?�����̦�m
		bNode *q; // p��????
		for (bNode *p = root; p; (value[idx] < p->data.value) ? p = p->lchild : p = p->rchild)
			q = p;
		(value[idx] < q->data.value) ? q->lchild = t : q->rchild = t; // ?�s???�J�G�e?
		printf(", ���??�a�} %lx", q);
	}
	return root;
}

// �۳y�G�e?,?�J?��?len��??edge�Mvalue,�U?�Y?????id�A
// edge[id]���???id��??��????��??(0~len-1) �A��??��?????-1
// value????�F??��?�u��value��
// ��k��Q�G?�C???�۳y�@???�A?��?���a�}�s�b�@?��???���F�M�Z���uedge??��???�����G�e?
bNode *buildBTreeByEdge(int *value, int *edge, int len)
{
	// �����ݭn?�dedge??�O�_�N��@�ʤG�e?�G�ߤ@��-1�A0~len-1�C??�ܦh�X?2��,edge[i]!=i.?���ٲ�
	bNode **allnodes = (bNode **)malloc(sizeof(bNode *) * len); // len?��?
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
	{ // �G�e?���ߤ@�A���k�l?�i�H��?�Aɬ���۳y���l?
		if (edge[i] != -1)
			(allnodes[edge[i]]->lchild == NULL) ? allnodes[edge[i]]->lchild = allnodes[i] : allnodes[edge[i]]->rchild = allnodes[i];
		else
			root = allnodes[i];
	}
	return root;
}

// ??��k�G�۳y�G�e?,?�J?��?len=2n+1��??prelist�A�G�e?��???�q?n
// ���ǧǦCprelist[i],�Y�ǦC���J���??�A���?NULLNODE�Aprelist����n+1?NULLNODE
#define NULLNODE -9999
bNode *buildBTreeByPrelist(int *prelist, int len)
{
	bNode *t;
	static int idx = 0; // ??���C��?�Φۨ����ݭn??�����S��?�q��???�q�Υ���?�q
	if (prelist[idx] == NULLNODE)
	{
		idx++;
		return NULL;
	}
	if (!(t = (bNode *)malloc(sizeof(bNode *))))
		exit(0);
	t->data.value = prelist[idx];
	t->data.id = idx;
	idx++; // ��???prelist[idx]���U�@??�u�۫�??,idx?�k��J��?�C��
	t->lchild = buildBTreeByPrelist(prelist, len);
	t->rchild = buildBTreeByPrelist(prelist, len);
	return t;
} // �p�Gprelist����?�u?�k������J��@�ʤG�e?�A�p��??�H�]�۳y?���Z idx<len-1)
// ??��?�C��?�k��ܤl??�����S��?��?�A���Υ���?�q��???�q??�z

// ??��k(���ǹM?)�G�۳y�G�e? �A?�J���ǧǦCpre�M���ǧǦCin�A�H��??�ǦC�U�۪��W��pu,iu�M�U��pl,il
bNode *buildBTreeByPI(int *pre, int pl, int pu, int *in, int il, int iu)
{
	printf("\n%d-%d,%d-%d", pl, pu, il, iu);
	int il1, iu1, il2, iu2, pl1, pl2, pu1, pu2; // ��??�⤤�ǧǦC����??�l�ǦC�A�P?�o����}�ǦC��??�l�ǦC�A?�O�l�ǦC���U?
	if (pu - pl != iu - il)
		exit(0); // ?�d?�J??
	if (pu - pl < 0)
		return NULL; // �Y�ǦC?�šA��^��??/��?
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
			iu2 = iu; // �������ǧǦCin������
			pl1 = pl + 1;
			pu1 = pl + (iu1 - il1 + 1);
			pl2 = pu1 + 1;
			pu2 = pu; // �������}�ǦCpre������
		}
	}
	t->lchild = buildBTreeByPI(pre, pl1, pu1, in, il1, iu1);
	t->rchild = buildBTreeByPI(pre, pl2, pu2, in, il2, iu2);
	return t;
}

/*** �G�e?���䥦�򥻾ާ@  ***/
// �d��?�w??p����?? , t�D��?�A��ܤw?���A�N���ݭn???�ΡA������^
bNode *parent(bNode *root, bNode *p)
{
	bNode *t = NULL;
	if (!root || root == p)
		return NULL; // ��?��??�A��?�]?��p����??

	if (p && (root->lchild == p || root->rchild == p))
		return root;
	if (root->lchild && !t)
		t = parent(root->lchild, p);
	if (root->rchild && !t)
		t = parent(root->rchild, p);
	return t;
}

// ��??��id�]�i�H�令�䥦?�u�쪺�ȡ^�d��??�A��^??��? �C(���ǹM?�^
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

// ���ΦZ�ǹM????�C��ҡG�i�H�Υ��ǹM??�H
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

/***-�U�����N?�O????��? visit() �����P??�覡�A???????��?�z�A��?�W�q�`�@?�G�e?�M?��?��?? ***/
// ���L�Y???���H��,���uElemtype���w?�ӭק�,??�����]��?�X�s?�a�}�^
void bPrintNode(bNode *a)
{
	printf("\n(id = %2d) = %5d", a->data.id, a->data.value);
}

// ���L�Y???���H��,���uElemtype���w?�ӭק�,??�����]?�X�s?�a�}�^
void cPrintNode(bNode *a)
{
	printf("\n*(addr = %lx):(id=%2d)= %5d", a, a->data.id, a->data.value);
}

// ??��?�ȡA???�u�쪺value��+1
void add1(bNode *a)
{
	a->data.value += 1;
}

/***-�U�����N?�O??���ǹM?�B���ǹM?�M�Z�ǹM?���ҪO�A�j�h?�G�e?���ާ@��_?��?���ק� ***/
// ���ǹM?�G�e?
void preTraverseTree(bNode *root, void (*ptrf)(bNode *a))
{
	if (root)
	{ // ??�X�f
		(*ptrf)(root);
		preTraverseTree(root->lchild, (*ptrf));
		preTraverseTree(root->rchild, (*ptrf));
	}
}

// ���ǹM?�G�e?
void inTraverseTree(bNode *root, void (*ptrf)(bNode *a))
{
	if (root)
	{ // ??�X�f
		inTraverseTree(root->lchild, (*ptrf));
		(*ptrf)(root);
		inTraverseTree(root->rchild, (*ptrf));
	}
}

// �Z�ǹM?�G�e?
void postTraverseTree(bNode *root, void (*ptrf)(bNode *a))
{
	if (root)
	{ // ??�X�f
		postTraverseTree(root->lchild, (*ptrf));
		postTraverseTree(root->rchild, (*ptrf));
		(*ptrf)(root);
	}
}

/***-�U�����N?�Τ_?���ƤG�e?�G?�ǹM??�G�H?��(?��?�C)�Φ�?�X ***/
// �H�U�ۦ��@??��?�C�A�s��G�e?��??���a�}�A�Τ_?�ǹM?�G�e?
struct qNode
{						// ?�C??
	bNode *ptr;			// ?�C��??�]�A��?�u��O�G�e???����?
	struct qNode *next; // ?�C���U�@???�A?�C�O??��
};

typedef struct queue
{
	struct qNode *front;
	struct qNode *rear;
} linkQueue;

// ?�G�e?�ͦ�?�ǹM?��?�C�G��??���ơC?�J�G�e?�A?�X?�C
// ???�C?��??��M?�@���A�i�H???�ǹM?
// ?��k�]�i�H�y�@�ק�Y�o�졧?�ǹM?����k�]??�@�U�^
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

	struct qNode *head;												// ?����?�{����??(����ק�hQueue->front�A����?��)�A?��������hQueue->rear
	struct qNode *t = (struct qNode *)malloc(sizeof(struct qNode)); // ?��?�C��L??�]???�A���s�񦳮�?�u��??�^
	if (!t)
		exit(0);
	hQueue->front = hQueue->rear = head = t; // ��?�O��?�C

	// root�J?
	t = (struct qNode *)malloc(sizeof(struct qNode)); // ?��?�C??
	if (!t)
		exit(0);
	t->ptr = root; // ?�u��?�ȡA��?next�i�H����?��(why?)
	hQueue->rear->next = t;
	hQueue->rear = t;

	while (head != hQueue->rear)
	{					   // ?�C���� ,head�O��L??�A?�u?�ġA����?�u?head->next?�l
		head = head->next; // �X?�]��?�X?�A�]?�n��^?���ƪ�?�C�A�ҥH����ק�?�C��?��?)
		// printf("de-%lx,",head->ptr);	//���L?�y�A??�ΡA�d�ݤJ?�B�X??�{
		if (head->ptr->lchild)
		{ // head->next�s��?�u�]??�^�����Ĥl�D�šA�۫طs?�C??�A�J?
			t = (struct qNode *)malloc(sizeof(struct qNode));
			if (!t)
				exit(0);
			t->ptr = head->ptr->lchild; // �s??��?�u��?��
			hQueue->rear->next = t;		// �s??����?�C����
			hQueue->rear = t;
			// printf("en-%lx,",t->ptr); //���L?�y�A??�ΡA�d�ݤJ?�B�X??�{
		}
		if (head->ptr->rchild)
		{ // head�s��?�u�]??�^���k�Ĥl�D�šA�۫طs?�C??�A�J?
			t = (struct qNode *)malloc(sizeof(struct qNode));
			if (!t)
				exit(0);
			t->ptr = head->ptr->rchild; // �s??��?�u��?��
			hQueue->rear->next = t;		// �s??����?�C����
			hQueue->rear = t;
			// printf("en-%lx,",t->ptr);//���L?�y�A??�ΡA�d�ݤJ?�B�X??�{
		}
	}
	return hQueue;
} // ��Ҧp��??����/����/�Z�ǹM?��?���ơH�}?�X?���ƦZ��?�C

/*** �U���O�@�Ǩ嫬?�� ***/
// �D�G�e?������/�`��
int deepth(bNode *root)
{
	if (!root)
		return 0;
	int d = deepth(root->lchild);
	int n = deepth(root->rchild);
	return (d > n) ? d + 1 : n + 1;
}

// �D�G�e?��?2��???��
int node2(bNode *root)
{
	int c = 0;
	if (!root)
		return 0;
	if (root->lchild && root->rchild)
		c = 1;
	return c + node2(root->lchild) + node2(root->rchild);
}

// �D�G�e?��?1��???��
int node1(bNode *root)
{
	int c = 0;
	if (!root)
		return 0;
	if ((!root->lchild && root->rchild) || (root->lchild && !root->rchild))
		c = 1;
	return c + node1(root->lchild) + node1(root->rchild);
}

// �D�G�e?��?0��???�� (?�l???�ء^
int node0(bNode *root)
{
	if (!root)
		return 0;
	if (!root->lchild && !root->rchild)
		return 1;
	return node0(root->lchild) + node0(root->rchild);
}

// �D�G�e?��?0��???�ت�value���M
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

	printf("\n??�G�e?�ͦ� value:");
	bNode *t1 = buildBTreeByValue(val, n); // ??�ѭ�??�ͦ��G�e?
	preTraverseTree(t1, add1);			   // ??���ǹM?
	inTraverseTree(t1, cPrintNode);		   // ??���ǹM?
	postTraverseTree(t1, cPrintNode);	   // ??�Z?�M?
	/*	DestroyBTree(t1);

		printf("\n??�G�e?�ͦ� edge :");
		int edge[7]={5,6,6,1,2,2,-1}; //�W�[???
		t1 = buildBTreeByEdge(val,edge,n); //??�ѭ�??�M?�ͦ��G�e?
		preTraverseTree(t1,bPrintNode); //??���ǹM?
		inTraverseTree(t1,add1);  //??���ǹM?
		postTraverseTree(t1,cPrintNode);//??�Z?�M?
		DestroyBTree(t1);

		printf("\n??�G�e?�ͦ� Prelist:");
		int prelist[15]={17,32,41,-9999,-9999,-9999,13,7,-9999,-9999,16,22,-9999,-9999,-9999};
		t1 = buildBTreeByPrelist(prelist,15);
		preTraverseTree(t1,cPrintNode); //??���ǹM?
		inTraverseTree(t1,cPrintNode);  //??���ǹM?
		postTraverseTree(t1,bPrintNode);//??�Z?�M?

		//???��?����
		printf("\n???��?����:");
		linkQueue *qlist =  ToHiraQueue(t1);
		for(struct qNode *p = qlist->front;p!=qlist->rear;p = p->next)
			printf("%d, ",p->next->ptr->data.value); //���L?����?��
		printf("\n");

		//????�d��M�D��??
		printf("\n????�d��M�D��??:");
		bNode *tn = locateByID(t1,2);
		if (!tn)
			printf("\n?���??");
		else{
			cPrintNode(tn);
			printf("\n��???�G");
			tn=parent(t1,tn);
			if (!tn)
				printf("?���");
			else
				cPrintNode(tn);
		}
		DestroyBTree(t1);

		//??���ǧǦC�M���ǧǦC�۳y�G�e?
		printf("\n??�G�e?�ͦ� PI:");
		int pre[]={17,32,41,13,7,16,22};
		int in[]={41,32,17,7,13,22,16};
		t1=buildBTreeByPI(pre,0,n-1,in,0,n-1);
		if (t1){
			preTraverseTree(t1,cPrintNode); //??���ǹM?
			inTraverseTree(t1,cPrintNode);  //??���ǹM?
			postTraverseTree(t1,cPrintNode);//??�Z?�M?
		}
	*/
	saveTree(t1, "sg.html");

	// �嫬?��??
	printf("\n?���� %d ", deepth(t1));
	printf("\n?��?2��???�� %d ", node2(t1));
	printf("\n?��?0��???�� %d ", node0(t1));
	printf("\n?��?1��???�� %d ", node1(t1));
	printf("\n?��?0��??value���M %d ", value0(t1));

	DestroyBTree(t1);
	return 1;
}

#endif
