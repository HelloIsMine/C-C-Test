#include<stdio.h>

#define MAXSIZE 20
#define OK 1
#define ERORR 0
#define TRUE 1
#define FLASE 0

typedef int status;
typedef int ElemType;

//������ʽ���Ա�
typedef struct {
	ElemType e;
	struct Node* next;
}Node;

typedef Node* LinkList;

//int main()
//{
//
//	return 0;
//}