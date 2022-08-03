#include<stdio.h>

#define MAXSIZE 20
#define OK 1
#define ERORR 0
#define TRUE 1
#define FLASE 0

typedef int status;
typedef int ElemType;

//Define static LinkList Node��
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

//��ӡ��̬����
void PrintList(StaticLinkList L)
{
	int k = MAXSIZE - 1;
	int pos = 1;
	if (!L[k].cur)printf("This is a empty list!\n");
	while (L[k].cur)
	{
		k = L[k].cur;
		printf("��%d��Ԫ���ǣ�%d\n", pos, L[k].data);
		pos++;
	}
}

//����mallc����
int Malloc_SLL(StaticLinkList space)
{
	int i = space[0].cur;
	if (i)
		space[0].cur = space[i].cur;
	return i;
}

//����Ԫ�ص���̬����
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

//����List����
int ListLength(StaticLinkList L)
{
	return L[0].data;
}

//ɾ��Ԫ��
status ListDelete(StaticLinkList L, int i)
{
	if (i < 1 || i > ListLength(L))return ERORR;
	int k = MAXSIZE - 1;
	int pre;
	for (int l = 1; l <= i; l++)//�ҵ���i��Ԫ��
	{
		pre = k;
		k = L[k].cur;
	}
	L[pre].cur = L[k].cur;
	Free_SLL(L, k);
	L[0].data--;
	return OK;
}

//�ͷŽڵ�
void Free_SLL(StaticLinkList space, int k)
{
	space[k].cur = space[0].cur;
	space[0].cur = k;
}

int main()
{
	StaticLinkList L;
	InitList(L);
	PrintList(L);


	return 0;
}