//#include<stdio.h>
//typedef struct LinkNode{
//	struct LinkNode* next;
//	int data;
//}LinkNode;
//typedef LinkNode* LinkList;
//void change(LinkNode** L) {
//	printf("Inside L is %p\n", L);
//	printf("Inside *L is %d\n", (*L)->data);
//	printf("Inside **L is %d\n", (**L).data);
//}
//
//int main() {
//	LinkList L;
//	L = NULL;
//	L = (LinkList)malloc(sizeof(LinkNode));
//	L->data = 100;
//	printf("outside &L is %p\n", &L);
//	printf("outside &L is %p\n", L);
//	change(&L);
//	return 0;
//}