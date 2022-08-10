#include<stdio.h>
#define MAXSIZE 20
#define OK 1
#define ERORR 0
#define TRUE 1
#define FLASE 0
typedef int Elemtype;
typedef int status;
typedef struct {
	Elemtype data[MAXSIZE];
	int top;
}SqStack;

status InitSqStack(SqStack *s)
{
	s->top = -1;
	return OK;
}

status Push(SqStack* s, Elemtype e)
{
	if (s->top >= MAXSIZE - 1)
		return ERORR;
	s->top++;
	s->data[s->top] = e;
	return OK;
}

status Pop(SqStack* s, Elemtype* e)
{
	if (s->top == -1) {
		return ERORR;
	}
	*e = s->data[s->top];
	s->top--;
	return OK;
}

void PrintSqStack(SqStack* s)
{
	if (s->top == -1)
		printf("this is an empty stack.\n");
	for (int i = 0; i <= s->top; i++) {
		printf("No.%d elem is %d\n", i+1, s->data[i]);
	}
}

/*Application: ����������ʽ*/
//��׺���ʽת��׺���ʽ
//��׺���ʽ������



int main() {
	SqStack s;
	Elemtype e;
	InitSqStack(&s);
	PrintSqStack(&s);
	Push(&s, 10000);
	Push(&s, 20000);
	Push(&s, 22);
	Push(&s, 424);
	Push(&s, 7474);
	PrintSqStack(&s);
	Pop(&s, &e);
	printf("deleted elem is %d\n", e);
	PrintSqStack(&s);
	return 0;
}