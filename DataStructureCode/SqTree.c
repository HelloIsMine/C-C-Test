#include<stdio.h>

#define MAXSIZE 100
#define OK 1
#define ERORR 0
#define TRUE 1
#define FLASE 0
typedef int Elemtype;
typedef int Status;

typedef struct PTNode {
	Elemtype data;
	int parent;
}PTNode;
//Ë«Ç×±íÊ¾·¨
typedef struct {
	PTNode node[MAXSIZE];
	int r, n;
}PTree;

