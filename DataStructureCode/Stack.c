#include<stdio.h>
#define MAXSIZE 20
#define OK 1
#define ERORR 0
#define TRUE 1
#define FLASE 0
typedef char Elemtype;
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
char* transferSpress(char* s) {
	int i = 0;
	char outPut[30];
	int j = 0;
	SqStack S;
	InitSqStack(&S);
	Elemtype e;
	while (*s != '\0') {
		if (*s == 32) {
			outPut[j++] = ' ';
			s++;
			continue;
		}
		if (*s >= 48 && *s <= 57) {
			outPut[j++] = *s++;
			outPut[j++] = ' ';
			continue;
		}
		if (s[i] == '(') {
			Push(&S, *s++);
		}
		else if (*s == '+' || *s == '-') {
			if (S.top >-1 && S.data[S.top] == '*' || S.data[S.top] == '/') {
				while (S.top > -1)
				{
					Pop(&S, &outPut[j++]);
					outPut[j++] = ' ';
				}
			}
			Push(&S, *s++);			
		}
		else if (*s == ')') {
			while (S.data[S.top] != '(')
			{
				Pop(&S, &outPut[j++]);
				outPut[j++] = ' ';
			}
			Pop(&S, &e);
			s++;
		}
		else if (*s == '*' || *s == '/') {
			Push(&S, *s++);
		}
	}
	while (S.top > -1)
	{
		Pop(&S, &outPut[j++]);
		outPut[j++] = ' ';
	}
	outPut[j] = '\0';
	return outPut;
}

//��׺���ʽ������



int main() {
	/*SqStack s;
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
	printf("this is %dwhat\n", '9');*/
	char s[] = "5+2*(2-6)+3";
	printf("It is %s\n", s);
	printf("It is %s\n", transferSpress(s));
	return 0;
}