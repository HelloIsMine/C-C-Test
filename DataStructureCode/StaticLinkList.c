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
	return OK;
}

//��ӡ��̬����
void PrintList(StaticLinkList L)
{
	
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
	if (i < 1)return ERORR;
	int j = Malloc_SLL(L);
	if (j)
	{
		L[j].data = e;
		int k = MAXSIZE - 1;
		for (int l = 1; l < i - 1; l++)
		{
			k = L[k].cur;
		}
		L[j].cur = L[k].cur;
		L[k].cur = j;
		return OK;
	}
	return ERORR;
}

//ɾ��Ԫ��
status ListDelete(StaticLinkList L, int i)
{

}

//�ͷŽڵ�
void Free_SLL(StaticLinkList space, int k)
{

}

int ListLength(StaticLinkList L)
{

}

int main()
{
	StaticLinkList L;
	InitList(L);
	PrintList(L);


	return 0;
}