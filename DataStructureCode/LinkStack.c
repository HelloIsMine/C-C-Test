//#include<stdio.h>
//#define MAXSIZE 20
//#define OK 1
//#define ERORR 0
//#define TRUE 1
//#define FLASE 0
//typedef int Elemtype;
//typedef int status;
//
//typedef struct {
//	Elemtype data;
//	struct StackNode* next;
//}StackNode, * LinkStackPtr;
//
//typedef struct LinkStack {
//	LinkStackPtr top;
//	int count;
//}LinkStack;
//
//status Push(LinkStack* S, Elemtype e) {
//	LinkStackPtr s = (LinkStackPtr)malloc(sizeof(StackNode));
//	s->data = e;
//	s->next = S->top;
//	S->top = s;
//	S->count++;
//	return OK;
//}
//
//status Pop(LinkStack* S, Elemtype* e) {
//	if (S->count == 0) {
//		return ERORR;
//	}
//	LinkStackPtr p = S->top;
//	*e = p->data;
//	S->top = p->next;
//	free(p);
//	S->count--;
//	return OK;
//}
//
//PrintLinkStack(LinkStack S) {
//	if (S.top == NULL)
//		printf("It is an empty stack\n");
//	LinkStackPtr p = S.top;
//	int cnt = 1;
//	while (p)
//	{
//		printf("No.%d elem is %d\n", cnt, p->data);
//		p = p->next;
//		cnt++;
//	}
//}
//
//status ClearLinkStack(LinkStack* S) {
//	if (S->top == NULL)
//		return OK;
//	LinkStackPtr p = S->top;
//	while (p) {
//		S->top = p->next;
//		free(p);
//		p = S->top;
//	}
//	S->top = NULL;
//	return OK;
//}
//
//int main() {
//	LinkStack S;
//	Elemtype e;
//	S.count = 0;
//	S.top = NULL;
//	PrintLinkStack(S);
//	Push(&S, 10000);
//	PrintLinkStack(S);
//	Push(&S, 2000);
//	PrintLinkStack(S);
//	Push(&S, 300);
//	PrintLinkStack(S);
//	Push(&S, 6);
//	PrintLinkStack(S);
//	Push(&S, 48);
//	PrintLinkStack(S);
//	Pop(&S, &e);
//	PrintLinkStack(S);
//	ClearLinkStack(&S);
//	PrintLinkStack(S);
//	return 0;
//}