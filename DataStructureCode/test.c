#include<stdio.h>
int a, b;
a = 30;
void change(int *x)
{
	x = &b;
}

//int main()
//{
//	int* p = &a;
//	printf("p value is %d\n", p);
//	printf("*p value is %d\n", *p);
//	change(p);
//	printf("p value is %d\n", p);
//	printf("*p value is %d\n", *p);
//
//	return 0;
//}