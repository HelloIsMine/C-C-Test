//#define _CRT_SECURE_NO_WARNINGS
//
//#include<stdio.h>
//#define MAXSIZE 100
//#define OK 1
//#define ERORR 0
//#define TRUE 1
//#define FLASE 0
//typedef char Elemtype;
//typedef int Status;
//typedef enum { link, Thread } PointerTag;
//
//typedef struct BiThreadNode {
//	Elemtype data;
//	struct BiThreadNode* lchild, * rchild;
//	PointerTag LTag;
//	PointerTag RTag;
//}BiThreadNode, *BiThreadTree;
//
//BiThreadTree pre;
//
//void inThreading(BiThreadTree T) 
//{
//	if (T) {
//		inThreading(T->lchild);
//		if (!T->lchild) 
//		{
//			T->LTag = Thread;
//			T->lchild = pre;
//		}
<<<<<<< HEAD
//		if (pre && !pre->rchild) 
=======
//		if (!pre->rchild) 
>>>>>>> 3453c824bcd265bd469002b0759a5d13deb48638
//		{
//			pre->RTag = Thread;
//			pre->rchild = T;
//		}
//		pre = T;
//		inThreading(T->rchild);
//	}
//}
//
//void CreateBiTree(BiThreadTree* T) {
//	char ch;
//	scanf("%c", &ch);
//	if (ch == '#') {
//		*T = NULL;
//	}
//	else
//	{
//		*T = (BiThreadTree)malloc(sizeof(BiThreadNode));
<<<<<<< HEAD
//		(*T)->LTag = link;
//		(*T)->RTag = link;
=======
>>>>>>> 3453c824bcd265bd469002b0759a5d13deb48638
//		(*T)->data = ch;
//		CreateBiTree(&(*T)->lchild);
//		CreateBiTree(&(*T)->rchild);
//	}
//}
//
<<<<<<< HEAD
////中序线索化
=======
//
>>>>>>> 3453c824bcd265bd469002b0759a5d13deb48638
//Status InOrderTraverse_Thr(BiThreadTree T)
//{
//	BiThreadTree p;
//	p = T->lchild;
//	while (p != T)
//	{
//		while (p->LTag == link)
//		{
//			p = p->lchild;
//		}
//		printf("%d", p->data);
//		
//		while (p->RTag == Thread && p->rchild != T)
//		{
//			p = p->rchild;
//			printf("%d", p->data);
//		}
//
//		p = p->rchild;
//	}
<<<<<<< HEAD
//	return OK;
//}
//
////前序线索化
//Status PreOrderTraverse_Thr(BiThreadTree T)
//{
//	return OK;
//}
//
//int main() {
//	BiThreadTree T, p;
//	p = (BiThreadTree)malloc(sizeof(BiThreadNode));
//	CreateBiTree(&T);
//	p->lchild = T;
//	p->LTag = link;
//	inThreading(T);
//	p->LTag = Thread;
//	p->rchild = pre;
//	pre->RTag = Thread;
//	pre->rchild = p;
//	InOrderTraverse_Thr(p);
=======
//}
//
//int main() {
//	BiThreadTree T;
//	pre = (BiThreadTree)malloc(sizeof(BiThreadNode));
//	CreateBiTree(&T);
//	pre->lchild = T;
//	pre->LTag = link;
//	pre->rchild = NULL;
//	inThreading(T);
//
//
>>>>>>> 3453c824bcd265bd469002b0759a5d13deb48638
//	return 0;
//}