#include<stdio.h>
#define MAXSIZE 20
#define OK 1
#define ERORR 0
#define TRUE 1
#define FLASE 0
typedef int Elemtype;
typedef int Status;

typedef struct QueueNode {
	Elemtype data;
	struct QueueNode* next;
}QueueNode, * QueueNodePtr;

typedef struct LinkQueue {
	QueueNodePtr front;
	QueueNodePtr rear;
}LinkQueue;

Status InitQueue(LinkQueue* Q) {
	Q->front = NULL;
	Q->rear = NULL;
	return OK;
}

void Queuelength(LinkQueue Q) {
	if (Q.front == NULL)
	{
		printf("It is an empty queue\n");
		return;
	}
	int length = 0;
	QueueNodePtr p = Q.front;
	while (p) {
		length++;
		p = p->next;
	}
}

Status EnQueue(LinkQueue* Q, Elemtype e) {
	QueueNodePtr p = (QueueNodePtr)malloc(sizeof(QueueNode));
	p->data = e;
	p->next = NULL;
	if (Q->rear == NULL) {
		Q->rear = p;
		Q->front = p;
	}
	else {
		Q->rear->next = p;
		Q->rear = p;
	}
	return OK;
}

Status DeQueue(LinkQueue* Q, Elemtype* e) {
	if (Q->front == NULL) {
		return ERORR;
	}
	else {
		QueueNodePtr p;
		if (Q->front == Q->rear) {
			p = Q->front;
			*e = p->data;
			Q->front = NULL;
			Q->rear = NULL;
			free(p);
		}
		else
		{
			p = Q->front;
			*e = p->data;
			Q->front = p->next;
			free(p);
		}
	}
}

void PrintLinkQueue(LinkQueue Q) {
	if (Q.front == NULL) {
		printf("It is an empty queue\n");
		return;
	}
	QueueNodePtr p = Q.front;
	int pos = 1;
	while (p)
	{
		printf("Queue No.%d is %d\n", pos, p->data);
		p = p->next;
		pos++;
	}
}

int main() {
	LinkQueue Q;
	InitQueue(&Q);
	PrintLinkQueue(Q);
	EnQueue(&Q, 100);
	EnQueue(&Q, 200);
	EnQueue(&Q, 300);
	PrintLinkQueue(Q);
	Elemtype e;
	DeQueue(&Q, &e);
	PrintLinkQueue(Q);
	return 0;
}