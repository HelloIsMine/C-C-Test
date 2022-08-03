#include<stdio.h>

#define MAXSIZE 20
#define OK 1
#define ERORR 0
#define TRUE 1
#define FLASE 0

typedef int status;
typedef int ElemType;

//Define static LinkList Node；
typedef struct
{
	ElemType data;
	int cur;
}Component, StaticLinkList[MAXSIZE];

//Initialize a static linklist;
status InitList(StaticLinkList space)
{
	for (int i = 0; i < MAXSIZE - 1; i++)
	{
		space[i].cur = i + 1;
	}
	space[MAXSIZE - 1].cur = 0;
	space[0].data = 0;
	return OK;
}

//打印静态链表
void PrintList(StaticLinkList L)
{
	int k = MAXSIZE - 1;
	int pos = 1;
	if (!L[k].cur)printf("This is a empty list!\n");
	while (L[k].cur)
	{
		k = L[k].cur;
		printf("第%d个元素是：%d\n", pos, L[k].data);
		pos++;
	}
}

//分配mallc函数
int Malloc_SLL(StaticLinkList space)
{
	int i = space[0].cur;
	if (i)
		space[0].cur = space[i].cur;
	return i;
}

//插入元素到静态链表
status ListInsert(StaticLinkList L, int i, ElemType e)
{
	if (i < 1 || i > ListLength(L) + 1)return ERORR;
	int j = Malloc_SLL(L);
	if (j)
	{
		L[j].data = e;
		int k = MAXSIZE - 1;
		for (int l = 1; l <= i - 1; l++)
		{
			k = L[k].cur;
		}
		L[j].cur = L[k].cur;
		L[k].cur = j;
		L[0].data++;
		return OK;
	}
	return ERORR;
}

//返回List长度
int ListLength(StaticLinkList L)
{
	return L[0].data;
}

//释放节点
void Free_SLL(StaticLinkList space, int k)
{
	space[k].cur = space[0].cur;
	space[0].cur = k;
}

//删除元素
status ListDelete(StaticLinkList L, int i)
{
	if (i < 1 || i > ListLength(L))return ERORR;
	int k = MAXSIZE - 1;
	int pre;
	for (int l = 1; l <= i; l++)//找到第i个元素
	{
		pre = k;
		k = L[k].cur;
	}
	L[pre].cur = L[k].cur;
	Free_SLL(L, k);
	L[0].data--;
	return OK;
}


int main()
{
	StaticLinkList L;
	InitList(L);
	PrintList(L);

	//插入元素
	ListInsert(L, 1, 100);
	ListInsert(L, 2, 200);
	ListInsert(L, 3, 300);
	ListInsert(L, 4, 400);
	ListInsert(L, 5, 500);
	ListInsert(L, 6, 600);
	ListInsert(L, 7, 700);
	ListInsert(L, 8, 800);
	ListInsert(L, 9, 900);
	ListInsert(L, 10, 1000);
	ListInsert(L, 11, 1100);

	PrintList(L);
	printf("长度是%d\n", ListLength(L));

	//删除元素
	ListDelete(L, 5);
	PrintList(L);
	printf("长度是%d\n", ListLength(L));
	return 0;
}