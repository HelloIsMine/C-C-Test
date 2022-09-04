#include"Search.h"
#include"BinarySortTree.h"
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
	int i;
	int a[10] = { 62, 88, 58, 47 , 35, 73, 51, 99, 37, 93 };
	BiTree T = NULL;
	for (i = 0; i < 10; i++)
	{
		InsertBST(&T, a[i]);
	}


	return 0;
}