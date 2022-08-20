//¶ş²æÊ÷±éÀú
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#define MAXSIZE 100
#define OK 1
#define ERORR 0
#define TRUE 1
#define FLASE 0
typedef char Elemtype;
typedef int Status;

typedef struct BiNode {
	Elemtype data;
	struct BiNode* lChild;
	struct BiNode* rChild;
}BiNode, * BiTree;

void PreOrderTraverse(BiTree T) {
	if (T->data = NULL) {
		return;
	}
	printf("%d", T->data);
	PreOrderTraverse(T->lChild);
	PreOrderTraverse(T->rChild);
}

void InOrderTraverse(BiTree T) {
	if (T->data = NULL)
		return;
	InOrderTraverse(T->lChild);
	printf("%d", T->data);
	InOrderTraverse(T->rChild);

}

void PostOrderTraverse(BiTree T) {
	if (T->data = NULL)
		return;
	PostOrderTraverse(T->lChild);
	PostOrderTraverse(T->rChild);
	printf("%d", T->data);
}

void CreateBiTree(BiTree* T) {
	char ch;
	scanf("%c", &ch);
	if (ch == '#')
		*T = NULL;
	else
	{
		*T = (BiTree)malloc(sizeof(BiNode));
		(*T)->data = ch;
		CreateBiTree(&(*T)->lChild);
		CreateBiTree(&(*T)->rChild);
	}

}

int main()
{
	BiTree T;
	CreateBiTree(&T);
	PreOrderTraverse(T);
	return 0;
}