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
	space[0].data = 0;
	for (int i = 0; i < MAXSIZE - 1; i++)
	{
		space[i].cur = i + 1;
		if (i != 0)
		{
			space[i].data = i;
			space[0].data++;
		}
	}
	space[MAXSIZE - 1].cur = 0;
	return OK;
}

//��ӡ��̬����
void PrintList(StaticLinkList L)
{
	int i = L[0].cur;
	int j = 1;
	while (i && j <= L[0].data)
	{
		printf("��%d��Ԫ���ǣ�%d\n", j, L[i].data);
		j++;
		i = L[i].cur;
	}
}

//����mallc����
int Malloc_SLL(StaticLinkList space)
{

}

//����Ԫ�ص���̬����
status ListInsert(StaticLinkList L, int i, ElemType e)
{

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