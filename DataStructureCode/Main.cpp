#include"Search.h"
#include"BinarySortTree.h"
#include"Sort.h"
using namespace std;

int main()
{
	/*
	≤‚ ‘Ï≥≤®ƒ«∆ı≤È’“∑Ω∑®
	*/
	/*int a[] = { 0,1,16,24,35,47,59,62,73,88,99,0 };
	int b = Fibonacci_Search(a, 10, 47);
	cout << b << endl;*/

	/*
	∂˛≤Ê ˜≈≈–Ú ˜
	*/
	/*int i;
	int a[10] = { 62, 88, 58, 47 , 35, 73, 51, 99, 37, 93 };
	BiTree T = NULL;
	for (i = 0; i < 10; i++)
	{
		InsertBST(&T, a[i]);
	}*/


	/*
	∆Ω∫‚∂˛≤Ê ˜
	*/
	/*int i;
	int a[10] = { 3, 2, 1, 4, 5, 6, 7, 10, 9, 8 };
	BiTree T = NULL;
	int taller;
	for (i = 0; i < 10; i++)
	{
		InsertAVL(&T, a[i], &taller);
	}*/


	/*
	≈≈–Ú
	*/
	SqL L;
	for (int i = 10; i > 0; i--) {
		L.data[10 - i] = i;
	}
	L.length = 10;

	//≤Â»Î≈≈–Ú
	PrintList(L);
	//InsertSort(&L);
	ShellSort(&L);
	PrintList(L);



	return 0;
}