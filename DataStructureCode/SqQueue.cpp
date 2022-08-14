//#include<stdio.h>
//#define MAXSIZE 20
//#define OK 1
//#define ERORR 0
//#define TRUE 1
//#define FLASE 0
//typedef int Elemtype;
//typedef int Status;
//
//typedef struct {
//	Elemtype data[MAXSIZE];
//	int front;
//	int rear;
//}SqQueue;
//
//Status InitQueue(SqQueue* Q) {
//	Q->front = 0;
//	Q->rear = 0;
//	return OK;
//}
//
//void QueueLength(SqQueue Q) {
//	printf("Queue length is %d\n", (Q.rear - Q.front + MAXSIZE) % MAXSIZE);
//}
//
//Status EnQueue(SqQueue* Q, Elemtype e) {
//	if ((Q->rear + 1) % MAXSIZE == Q->front)return ERORR;
//	Q->data[Q->rear] = e;
//	Q->rear = (Q->rear + 1) % MAXSIZE;
//	return OK;
//}
//
//Status DeQueue(SqQueue* Q, Elemtype* e) {
//	if (Q->front == Q->rear)return ERORR;
//	*e = Q->data[Q->front];
//	Q->front = (Q->front+1) % MAXSIZE;
//	return OK;
//}
//
//void PrintQueue(SqQueue Q) {
//	if (Q.front == Q.rear)
//	{
//		printf("It is an empty queue\n");
//		return;
//	}
//	int pos = Q.front;
//	int rank = 1;
//	while (pos%MAXSIZE < Q.rear)
//	{
//		printf("Queue No.%d is %d\n", rank, Q.data[pos]);
//		pos++;
//		rank++;
//	}
//}
//
//int main() {
//	SqQueue Q;
//	InitQueue(&Q);
//	PrintQueue(Q);
//	QueueLength(Q);
//
//	EnQueue(&Q, 100);
//	PrintQueue(Q);
//	QueueLength(Q);
//	EnQueue(&Q, 300);
//	EnQueue(&Q, 600);
//	PrintQueue(Q);
//	Elemtype e;
//	DeQueue(&Q, &e);
//	PrintQueue(Q);
//	QueueLength(Q);
//	return 0;
//}