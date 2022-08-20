#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#define MAXSIZE 100
#define OK 1
#define ERORR 0
#define TRUE 1
#define FLASE 0
typedef char Elemtype;
typedef int Status;
typedef enum { link, Thread } PointerTag;

typedef struct BiThreadNode {
	Elemtype data;
	struct BiThreadNode* lchild, * rchild;
	PointerTag LTag;
	PointerTag RTag;
}BiThreadNode, *BiThreadTree;

BiThreadTree pre;

void inThreading(BiThreadTree T) 
{
	if (T) {
		inThreading(T->lchild);
		if (!T->lchild) 
		{
			T->LTag = Thread;
			T->lchild = pre;
		}
		if (!pre->rchild) 
		{
			pre->RTag = Thread;
			pre->rchild = T;
		}
		pre = T;
		inThreading(T->rchild);
	}
}

void CreateBiTree(BiThreadTree* T) {
	char ch;
	scanf("%c", &ch);
	if (ch == '#') {
		*T = NULL;
	}
	else
	{
		*T = (BiThreadTree)malloc(sizeof(BiThreadNode));
		(*T)->data = ch;
		CreateBiTree(&(*T)->lchild);
		CreateBiTree(&(*T)->rchild);
	}
}


Status InOrderTraverse_Thr(BiThreadTree T)
{
	BiThreadTree p;
	p = T->lchild;
	while (p != T)
	{
		while (p->LTag == link)
		{
			p = p->lchild;
		}
		printf("%d", p->data);
		
		while (p->RTag == Thread && p->rchild != T)
		{
			p = p->rchild;
			printf("%d", p->data);
		}

		p = p->rchild;
	}
}

int main() {
	BiThreadTree T;
	pre = (BiThreadTree)malloc(sizeof(BiThreadNode));
	CreateBiTree(&T);
	pre->lchild = T;
	pre->LTag = link;
	pre->rchild = NULL;
	inThreading(T);


	return 0;
}