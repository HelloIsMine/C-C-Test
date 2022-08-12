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

/*Application: 四则运算表达式*/
//中缀表达式转后缀表达式
char* transferSpress(char* s) {
	int i = 0;
	char outPut[100];
	int j = 0;
	SqStack S;
	InitSqStack(&S);
	char e;
	while (*s != '\0') {
		if (*s >= 48 && *s <= 57) {
			outPut[j++] = *s++;
			continue;
		}
		outPut[j] = ' ';
		if (s[i] == '(') {
			Push(&S, *s++);
		}
		else if (*s == '+' || *s == '-') {
			if (S.top >-1 && S.data[S.top] == '*' || S.data[S.top] == '/') {
				while (S.top > -1 && S.data[S.top] != '(')
				{
					Pop(&S, &outPut[++j]);
					outPut[++j] = ' ';
				}
			}
			j++;
			Push(&S, *s++);	
		}
		else if (*s == ')') {
			while (S.data[S.top] != '(')
			{
				Pop(&S, &outPut[++j]);
				outPut[++j] = ' ';
			}
			Pop(&S, &e);
			s++;
		}
		else if (*s == '*' || *s == '/') {
			Push(&S, *s++);
			outPut[++j] = ' ';
		}
	}
	while (S.top > -1)
	{
		outPut[j++] = ' ';
		Pop(&S, &outPut[j++]);
	}
	outPut[j] = '\0';
	return outPut;
}

//后缀表达式的运算
double* CalculateSpress(char* s) {
	SqStack S;
	InitSqStack(&S);
	int m, n;
	double total;
	while (*s != '\0') {
		if (*s >= 48 && *s <= 57) {
			Push(&S, *s++);
		}
		else if (*s == '*') {
			Pop(&S, &m);
			Pop(&S, &n);
			if (S.top == -1) {
				return m * n;
			}
			  total = m * n;
			Push(&S, total);
		}
		else if (*s == '+') {
			Pop(&S, &m);
			Pop(&S, &n);
			if (S.top == -1) {
				return m + n;
			}
			total = m + n;
			Push(&S, total);
		}
		else if (*s == '-') {
			Pop(&S, &m);
			Pop(&S, &n);
			if (S.top == -1) {
				return n-m;
			}
			total = n-m;
			Push(&S, total);
		}
		else if (*s == '/') {
			Pop(&S, &m);
			Pop(&S, &n);
			if (S.top == -1) {
				return n/m;
			}
			total = n/m;
			Push(&S, total);
		}
		s++;
	}
	return;
}


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
	char s[] = "9+3/(2*3+4)";
	printf("It is %s\n", s);
	printf("It is %s\n", transferSpress(s));

	//printf("sum is %d\n", CalculateSpress(s));
	return 0;
}