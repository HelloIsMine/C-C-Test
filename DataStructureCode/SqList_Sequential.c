//#include<stdio.h>
//#define MAXSIZE 20
//#define OK 1
//#define ERORR 0
//#define TRUE 1
//#define FLASE 0
//
//typedef int status;
//typedef int ElemType;
//
///*���Ա�˳��洢�ṹ*/
//typedef struct {
//	ElemType data[MAXSIZE];
//	int length;
//}SqList;
//
////��ȡ���Ա��i��Ԫ��
//status getElem(SqList L, int i, ElemType* e)
//{
//	if (L.length == 0 || i > L.length || i < 1)
//		return ERORR;
//	*e = L.data[i - 1];
//	return OK;
//}
////��ʼ�����Ա�
//status InitList(SqList* L)
//{
//	int i;
//	for (i = 0; i < 15; i++)
//	{
//		L->data[i] = i+1;
//	}
//	L->length = i;
//}
//
//void PrintSqList(SqList L)
//{
//	for (int i = 0; i < L.length; i++)
//	{
//		printf("No.%d is %d\n", i+1, L.data[i]);
//	}
//}
//
////������Ա�
//status ClearList(SqList* L)
//{
//	L->length = 0;
//	return OK;
//}
//
////��λĳ��Ԫ���������Ա���λ��
//int LocateElem(SqList L, ElemType e)
//{
//	if (L.length == 0)
//		return ERORR;
//	for (int i = 0; i < L.length; i++)
//	{
//		if (L.data[i] == e)
//			return i + 1;
//	}
//	return ERORR;
//}
//
////����Ԫ��
//status ListInsert(SqList* L, int i, ElemType e)
//{
//	if (i > L->length + 1 || i > MAXSIZE || L->length+1 > MAXSIZE)
//		return ERORR;
//	else if (i == L->length+1)
//	{
//		L->data[i-1] = e;
//	}
//	else {
//		int tmp = L->length;
//		while (tmp > i)
//		{
//			L->data[tmp] = L->data[tmp - 1];
//			tmp--;
//		}
//		L->data[i - 1] = e;
//	}
//	L->length++;
//	return OK;
//}
//
////ɾ�����Ա���Ԫ��
//status ListDelete(SqList* L, int i, ElemType *e)
//{
//	if (i > L->length || i < 1)
//		return  ERORR;
//	int pos = i;
//	*e = L->data[i - 1];
//	while (pos <= L->length-1)
//	{
//		L->data[pos-1] = L->data[pos];
//		pos++;
//	}
//	L->length--;
//	return OK;
//}
//
////�������Ա���
//int ListLength(SqList L)
//{
//	return L.length;
//}
//
////ȡ�����Ա�Ĳ���
//void unionLists(SqList* La, SqList Lb)
//{
//	int La_len, Lb_len, i;
//	ElemType e;
//	La_len = ListLength(*La);
//	Lb_len = ListLength(Lb);
//	for (int i = 1; i <= Lb_len; i++)
//	{
//		getElem(Lb, i, &e);
//		if (!LocateElem(*La, e))
//			ListInsert(La, ++La_len, e);
//	}
//}
//
////int main()
////{
////	SqList L;
////	//InitList
////	InitList(&L);
////	PrintSqList(L);
////	printf("L length is %d\n", ListLength(L));
////	ElemType e = -1;
////
////	//getElem
////	//getElem(L, 15, &e);
////	//printf("e is %d\n", e);
////	////LocateElem
////	//printf("e location is %d\n", LocateElem(L, 100));
////
////	//ListInsert
////	/*printf("After Insert status is %d\n" ,ListInsert(&L, 20, 15));
////	for (int i = 0; i < 20; i++)
////	{
////		printf("%d\n", L.data[i]);
////	}
////	printf("L length is %d\n", L.length);*/
////
////	//ListDelete
////	/*printf("ListDelete is %d\n", ListDelete(&L, 10, &e));
////	printf("Deleted element is %d\n", e);
////	PrintSqList(L);*/
////
////	//unionLists
////	SqList L2;
////	InitList(&L2);
////	L2.data[5] = 100;
////	unionLists(&L, L2);
////	PrintSqList(L);
////	printf("L length is %d\n", ListLength(L));
////	return 0;
////}