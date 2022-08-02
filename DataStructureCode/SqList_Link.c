//#include<stdio.h>
//#include<time.h>
//#define MAXSIZE 20
//#define OK 1
//#define ERORR 0
//#define TRUE 1
//#define FLASE 0
//
//typedef int status;
//typedef int ElemType;
//
////定义链式线性表
//typedef struct {
//	ElemType data;
//	struct Node* next;
//}Node;
//
//typedef Node* LinkList;
//
////获取元素
//status GetElem(LinkList L, int i, ElemType* e)
//{
//	int j;
//	LinkList p;
//	p = L->next;
//	j = 1;
//	while (p && j < i)
//	{
//		p = p->next;
//		++j;
//	}
//	if (!p || j > i)
//	{
//		return ERORR;
//	}
//	*e = p->data;
//	return OK;
//}
//
////插入元素
//status ListInsert(LinkList* L, int i, ElemType e)
//{
//	int j = 1;
//	LinkList p, s;
//	p = *L;
//	while (p && j < i)
//	{
//		p = p->next;
//		j++;
//	}
//	if (!p || j > i)
//	{
//		return ERORR;
//	}
//	s = (LinkList)malloc(sizeof(Node));
//	s->next = p->next;
//	p->next = s;
//	s->data = e;
//	return OK;
//}
//
////删除元素
//status ListDelete(LinkList* L, int i, ElemType *e)
//{
//	int j = 1;
//	LinkList p, q;
//	p = *L;
//	while (p && j < i)
//	{
//		p = p->next;
//		++j;
//	}
//	if (!p || j > i)
//	{
//		return ERORR;
//	}
//	q = p->next;
//	p->next = q->next;
//	*e = q->data;
//	free(q);
//	return OK;
//}
//
////单链表的整表创建-头插法
//void CreateListHead(LinkList* L, int n)
//{
//	LinkList p;
//	*L = (LinkList)malloc(sizeof(Node));
//	srand(time(0));
//	(*L)->next = NULL;
//	for (int i = 0; i < n; ++i)
//	{
//		p = (LinkList)malloc(sizeof(Node));
//		p->data = i+1;
//		p->next = (*L)->next;
//		(*L)->next = p;
//	}
//}
//
////单链表的创建-尾插法
//void CreateListTail(LinkList* L, int n)
//{
//	LinkList p, r;
//	*L = (LinkList)malloc(sizeof(Node));
//	srand(time(0));
//	(*L)->next = NULL;
//	r = *L;
//	for (int i = 0; i < n; ++i)
//	{
//		p = (LinkList)malloc(sizeof(Node));
//		p->data = i+1;
//		r->next = p;
//		r = p;
//	}
//	r->next = NULL;
//}
//
////单链表的整表清除
//status ClearList(LinkList *L)
//{
//	LinkList p, q;
//	p = (*L)->next;
//	while (p)
//	{
//		q = p;
//		p = p->next;
//		free(q);
//	}
//	(*L)->next = NULL;
//	return OK;
//}
//
////打印链表数据
//void PrintList(LinkList L)
//{
//	LinkList p;
//	p = L->next;
//	int j = 1;
//	if (!p)
//		printf("是个空表");
//	while (p)
//	{
//		printf("第%d个元素是：%d\n", j, p->data);
//		j++;
//		p = p->next;
//	}
//}
//
//int main()
//{
//	LinkList L;
//	ElemType e;
//	//头插法创建
//	/*CreateListHead(&L, 10);
//	PrintList(L);*/
//
//	//尾插法创建
//	CreateListTail(&L, 10);
//	PrintList(L);
//
//	//插入元素
//	ListInsert(&L, 3, 110);
//	PrintList(L);
//
//	//删除元素
//	ListDelete(&L, 3, &e);
//	PrintList(L);
//
//	//清空链表
//	ClearList(&L);
//	PrintList(L);
//
//	return 0;
//}