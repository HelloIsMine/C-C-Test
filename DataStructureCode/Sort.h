#include<iostream>
using namespace std;

struct SqL
{
	int data[10];
	int length;
};

void PrintList(SqL L) {
	for (int i = 0; i < L.length;i++) {
		cout << "L[" << i << "]" << "==" << L.data[i] << endl;
	}
}

void Swap(SqL* L, int i, int j) {
	int temp = L->data[i];
	L->data[i] = L->data[j];
	L->data[j] = temp;
}

/*
优化版的冒泡排序
稳定性好
*/
void BubbleSort2(SqL* L) {
	int needSwap = 1;
	for (int i = 0; i < L->length-1 && needSwap; i++) {
		needSwap = 0;
		for (int j = 0; j < L->length - 1; j++) {
			if (L->data[j] > L->data[j + 1]) {
				Swap(L, j, j + 1);
				needSwap = 1;
			}
		}
	}
}

/*
选择排序
稳定性不好
*/

void SelectSort(SqL* L) {
	for (int i = 0; i < L->length - 1; i++) {
		int minIndex = i;
		for (int j = i+1; j < L->length; j++) {
			if (L->data[minIndex] > L->data[j]) {
				minIndex = j;
			}
		}
		Swap(L, minIndex, i);
	}
}

/*
插入排序

最好的时间复杂度：比较n-1次temp < L->data[j-1]；
最坏的时间复杂度：倒序,如{6,5,4,3,2,1},比较2,3,4,5,6,即2~n，所以时间复杂度为（n+4)(n-1)/2

*/

void InsertSort(SqL* L) {
	for (int i = 1; i < L->length; i++) {
		int temp = L->data[i];
		int j = i;
		while (j > 0 && temp < L->data[j-1])
		{
			L->data[j] = L->data[j - 1];
			j--;
		}
		L->data[j] = temp;
	}
}