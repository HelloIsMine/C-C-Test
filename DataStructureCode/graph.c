#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
typedef char VertexType;
typedef int EdgeType;
#define MAXVEX 100
#define INFINITY 65535
#define MAX 100
typedef int Boolean;
Boolean visited[MAX];

typedef int Elemtype;
typedef int Status;
#define MAXSIZE 20
#define OK 1
#define ERORR 0
#define TRUE 1
#define FALSE 0

typedef struct {
	Elemtype data[MAXSIZE];
	int front;
	int rear;
}SqQueue;

Status EnQueue(SqQueue* Q, Elemtype e) {
	if ((Q->rear + 1) % MAXSIZE == Q->front)return ERORR;
	Q->data[Q->rear] = e;
	Q->rear = (Q->rear + 1) % MAXSIZE;
	return OK;
}

Status DeQueue(SqQueue* Q, Elemtype* e) {
	if (Q->front == Q->rear)return ERORR;
	*e = Q->data[Q->front];
	Q->front = (Q->front+1) % MAXSIZE;
	return OK;
}

Status QueueEmpty(SqQueue Q)
{
	if (Q.front == Q.rear)
		return TRUE;
	return FALSE;
}

Status InitQueue(SqQueue* Q) {
	Q->front = 0;
	Q->rear = 0;
	return OK;
}

/*1.Adjacency Matrix*/
typedef struct
{
	VertexType vexs[MAXVEX];
	EdgeType arc[MAXVEX][MAXVEX];
	int numVertexes, numEdges;
}MGraph;

void CreateGraph(MGraph *G)
{
	printf("请输入顶点数和边数: \n");
	int i, j, k, w;
	scanf("%d, %d", &G->numVertexes, &G->numEdges);
	printf("Please enter the number of vexs\n");
	scanf("%c", G->vexs);
	for (i = 0; i < G->numVertexes; i++)
		scanf("%c",  &G->vexs[i]);
	for (i = 0; i < G->numVertexes; i++)
	{
		for (j = 0; j < G->numVertexes; j++)
		{
			G->arc[i][j] = INFINITY;
		}
	}
	printf("Please enter the Edges info:\n");
	for (k = 0; k < G->numEdges; k++)
	{
		printf("Please enter info edges:\n");
		scanf("%d, %d, %d", &i, &j, &w);
		G->arc[i][j] = w;
		G->arc[j][i] = G->arc[i][j];
	}
	
}

/*Adjacency Matrix Search*/
void DFSM(MGraph G, int i)
{
	int j;
	visited[i] = 1;
	printf("%c\n", G.vexs[i]);
	for (j = 0; j < G.numVertexes; j++)
	{
		if (G.arc[i][j] == 1 && !visited[j])
			DFSM(G, j);
	}
}

void DFSMTraverse(MGraph G)
{
	int i;
	for (i = 0; i < G.numVertexes; i++)
		visited[i] = 0;
	for (i = 0; i < G.numVertexes; i++)
	{
		if (!visited[i])
			DFSM(G, i);
	}
}

void BFSMTraverse(MGraph G)
{
	int i, j;
	SqQueue Q;
	for (i = 0; i < G.numVertexes; i++)
		visited[i] = 0;
	InitQueue(&Q);
	for (i = 0; i < G.numVertexes; i++)
	{
		if (!visited[i])
		{
			visited[i] = 1;
			printf("%c\n", G.vexs[i]);
			EnQueue(&Q, i);
			while (!QueueEmpty(Q))
			{
				DeQueue(&Q, &i);
				for (j = 0; j < G.numVertexes; j++)
				{
					if (G.arc[i][j] == 1 && !visited[j])
					{
						visited[j] = 1;
						EnQueue(&Q, j);
						printf("%c\n", G.vexs[j]);
					}
				}
			}
		}
	}
}



/*2.Adjacency List*/
typedef struct EdgeNode
{
	int adjavex;
	EdgeType weight;
	struct EdgeNode* next;
}EdgeNode;

typedef struct VertexNode
{
	VertexType data;
	EdgeNode* firstedge;
}VertexNode, AdjList[MAXVEX];

typedef struct
{
	AdjList adjList;
	int numVertexes, numEdges;
}GraphAdjList;

void CreateALGraph(GraphAdjList* G)
{
	int i, j, k;
	EdgeNode* e;
	printf("Please enter number of vexes and edges:\n");
	scanf("%d, %d", &G->numVertexes, &G->numEdges);
	scanf("%c", &i);//Filter the '\n'
	printf("Please input the vertex info\n");
	for (i = 0; i < G->numVertexes; i++)
	{
		scanf("%c",  & G->adjList[i].data);
		G->adjList[i].firstedge = NULL;
	}
	for (k = 0; k < G->numEdges; k++)
	{
		printf("Now please input the edge info\n");
		scanf("%d, %d", &i, &j);
		e = (EdgeNode*)malloc(sizeof(EdgeNode));
		e->adjavex = j;
		e->next = G->adjList[i].firstedge;
		G->adjList[i].firstedge = e;

		e = (EdgeNode*)malloc(sizeof(EdgeNode));
		e->adjavex = i;
		e->next = G->adjList[j].firstedge;
		G->adjList[j].firstedge = e;
	}

}

void DFSL(GraphAdjList G, int i)
{
	EdgeNode* p;
	visited[i] = 1;
	printf("%c\n", G.adjList[i].data);
	p = G.adjList[i].firstedge;
	while (p)
	{
		if (!visited[p->adjavex])
			DFSL(G, p->adjavex);
		p = p->next;
	}
}

void DFSLTraverse(GraphAdjList G)
{
	int i;
	for (i = 0; i < G.numVertexes; i++)
		visited[i] = 0;
	for (i = 0; i < G.numVertexes; i++)
	{
		if (!visited[i])
			DFSL(G, i);
	}
}

void BFSLTraverse(GraphAdjList G)
{
	int i;
	EdgeNode* p;
	SqQueue Q;
	for (i = 0; i < G.numVertexes; i++)
		visited[i] = FALSE;
	InitQueue(&Q);
	for (i = 0; i < G.numVertexes; i++)
	{
		if (!visited[i])
		{
			visited[i] = TRUE;
			printf("%c\n", G.adjList[i].data);
			EnQueue(&Q, i);
			while (!QueueEmpty(Q))
			{
				DeQueue(&Q, &i);
				p = G.adjList[i].firstedge;
				while (p)
				{
					if (!visited[p->adjavex])
					{
						visited[p->adjavex] = TRUE;
						printf("%c\n", G.adjList[p->adjavex].data);
						EnQueue(&Q, p->adjavex);
					}
					p = p->next;
				}
			}
		}
	}
}

int main()
{
	/*1.Adjacency Matrix*/
	/*MGraph G;
	CreateGraph(&G);
	DFSMTraverse(G);
	printf("XXXXXXXXXXXXX\n");
	BFSMTraverse(G);*/

	/*2.Adjacency List*/
	/*GraphAdjList G;
	CreateALGraph(&G);
	DFSLTraverse(G);
	printf("XXXXXXXXXXXXX\n");
	BFSLTraverse(G);*/
	return 0;
}
