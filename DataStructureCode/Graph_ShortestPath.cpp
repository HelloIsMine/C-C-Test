#include<iostream>
#include"Graph.h"
#include<vector>
using namespace std;

typedef int PathMatrix[MAXVEX];		  /*���ڴ洢���·���µ�����*/
typedef int ShortPathTable[MAXVEX];								/*���ڴ洢����������·����Ȩֵ��*/

void ShortestPath_Dijkstra(MGraph G, int v0, PathMatrix* p, ShortPathTable* D)
{
	int v, w, k, min;
	int final[MAXVEX];		/*final[w] = 1 ��ʾ��ö���v0��vw�����·��*/
	for (v = 0; v < G.numVertexes; v++)
	{
		final[v] = 0;							  /*ȫ��·����ʼ��Ϊδ֪���·��״̬*/
		(*D)[v] = G.arc[v0][v];													/*����v0�������ߵĶ������Ȩֵ*/
		(*p)[v] = 0;						/*��ʼ��·������pΪ0*/
	}
	(*D)[v0] = 0;
	final[v0] = 1;

	for (v = 1; v < G.numVertexes; v++)
	{
		min = INFINITY;
		for (w = 0; w < G.numVertexes; w++)
		{
			if (!final[w] && (*D)[w] < min)
			{
				k = w;
				min = (*D)[w];
			}
		}
		final[k] = 1;
		for (w = 0; w < G.numVertexes; w++)
		{
			if (!final[w] && (min + G.arc[k][w] < (*D)[w]))
			{
				(*D)[w] = min + G.arc[k][w];
				(*p)[w] = k;
			}
		}
	}
}

int main()
{
	MGraph G;
	CreateGraph(&G);
	PathMatrix p;
	ShortPathTable D;
	ShortestPath_Dijkstra(G, 0, &p, &D);
	return 0;
}