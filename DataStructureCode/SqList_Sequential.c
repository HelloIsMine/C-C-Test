#include<stdio.h>
#define MAXSIZE 20
#define OK 1
#define ERORR 0
#define TRUE 1
#define FLASE 0

typedef int status;
typedef int ElemType;

/*线性表顺序存储结构*/
typedef struct {
	ElemType data[MAXSIZE];
	int length;
}SqList;

status getElem(SqList L, int i, ElemType* e)
{
	if (L.length == 0 || i > L.length || i < 1)
		return ERORR;
	*e = L.data[i - 1];
	return OK;
}
//初始化线性表
status InitList(SqList* L)
{
	int i;
	for (i = 0; i < MAXSIZE; i++)
	{
		L->data[i] = i+1;
	}
	L->length = i;
}

int main()
{
	SqList L;
	InitList(&L);
	for (int i = 0; i < MAXSIZE; i++)
	{
		printf("%d\n", L.data[i]);
	}
	printf("L length is %d\n", L.length);

	ElemType e;
	getElem(L, 15, &e);
	printf("e is %d\n", e);

	return 0;
}