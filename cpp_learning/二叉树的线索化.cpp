//#include<iostream>
//using namespace std;
//
//typedef int ElemType;
//void visit(ThreadNode *q);
//typedef struct ThreadNode
//{
//	ElemType data;
//	ThreadNode* lChild, * rChild;
//	int ltag, rtag;
//}ThreadNode, *ThreadTree;
//
//ThreadNode* pre = NULL;
//
////中序遍历二叉树设置成线索二叉树
//void InThread(ThreadTree T)
//{
//	if (T != NULL)
//	{
//		InThread(T->lChild);
//		visit(T);
//		InThread(T->rChild);
//	}
//}
//
//void visit(ThreadNode* q)
//{
//	if (q->lChild == NULL) {
//		q->lChild = pre;
//		q->ltag = 1;
//	}
//	if (pre != NULL && pre->rChild == NULL) {
//		pre->rChild = q;
//		pre->rtag = 1;
//	}
//	pre = q;
//}
//
//void CreateInThread(ThreadTree T) {
//	pre = NULL;
//	if (T != NULL) {
//		InThread(T);
//		if (pre->rChild == NULL)
//			pre->rtag = 1;
//	}
//}
//
//void test01()
//{
//	
//}
//
//int main()
//{
//	//1.中序遍历
//	test01();
//	return 0;
//}