//#include<iostream>
//#include"Graph.h"
//#include<vector>
//using namespace std;
//
//typedef int PathMatrix[MAXVEX];		  /*用于存储最短路径下的数组*/
//typedef int ShortPathTable[MAXVEX];								/*用于存储到各点的最短路径的权值和*/
//typedef int PathMaTrix_Double[MAXVEX][MAXVEX];
//typedef int ShortPathTable_Double[MAXVEX][MAXVEX];
///*
//1.迪卡斯特拉算法
//*/
//void ShortestPath_Dijkstra(MGraph G, int v0, PathMatrix* p, ShortPathTable* D)
//{
//	int v, w, k, min;
//	int final[MAXVEX];		/*final[w] = 1 表示求得顶点v0到vw的最短路径*/
//	for (v = 0; v < G.numVertexes; v++)
//	{
//		final[v] = 0;							  /*全部路径初始化为未知最短路径状态*/
//		(*D)[v] = G.arc[v0][v];													/*将与v0点有连线的顶点加上权值*/
//		(*p)[v] = 0;						/*初始化路径数组p为0*/
//	}
//	(*D)[v0] = 0;
//	final[v0] = 1;
//
//	for (v = 1; v < G.numVertexes; v++)
//	{
//		min = INFINITY;
//		for (w = 0; w < G.numVertexes; w++)
//		{
//			if (!final[w] && (*D)[w] < min)
//			{
//				k = w;
//				min = (*D)[w];
//			}
//		}
//		final[k] = 1;
//		for (w = 0; w < G.numVertexes; w++)
//		{
//			if (!final[w] && (min + G.arc[k][w] < (*D)[w]))
//			{
//				(*D)[w] = min + G.arc[k][w];
//				(*p)[w] = k;
//			}
//		}
//	}
//}
//
///*
//2.弗洛伊德算法-Floyd 算法
//*/
//void ShortestPath_Floyd(MGraph G, PathMaTrix_Double* p, ShortPathTable_Double* D)
//{
//	int v, w, k;
//	for (v = 0; v < G.numVertexes; v++)
//	{
//		for (w = 0; w < G.numVertexes; w++)
//		{
//			(*D)[v][w] = G.arc[v][w];
//			(*p)[v][w] = w;
//		}
//	}
//	for (k = 0; k < G.numVertexes; k++)
//	{
//		for (v = 0; v < G.numVertexes; v++)
//		{
//			for (w = 0; w < G.numVertexes; w++)
//			{
//				if ((*D)[v][w] > (*D)[v][k] + (*D)[k][w])
//				{
//					(*D)[v][w] = (*D)[v][k] + (*D)[k][w];
//					(*p)[v][w] = (*p)[v][k];
//				}
//			}
//		}
//	}
//}
//
//int main()
//{
//	MGraph G;
//	CreateGraph(&G);
//	PathMatrix p;
//	ShortPathTable D;
//	ShortestPath_Dijkstra(G, 0, &p, &D);
//	return 0;
//}