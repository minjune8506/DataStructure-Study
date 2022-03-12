#include "arraygraph.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int found(int distance[], int visited[], int vertexCount)
{
	int min;
	int minPos;

	min = INT32_MAX;
	for (int i = 0 ; i < vertexCount ; i++)
	{
		if (distance[i] < min && !visited[i])
		{
			min = distance[i];
			minPos = i;
		}
	}
	return minPos;
}

/**
 * dijkstra() : 최단경로 알고리즘
 * 
 * pGraph : 그래프 포인터
 * start : 시작 노드
 * end : 종료 노드
 */
void dijkstra(ArrayGraph *pGraph, int start, int end)
{
	printf("---Dijkstra Algorithm---\n");
	int distance[pGraph->currentVertexCount];
	int visited[pGraph->currentVertexCount];
	int minPos;

	memset(visited, FALSE, sizeof(visited));
	visited[start] = TRUE;
	for (int i = 0 ; i < pGraph->currentVertexCount ; i++)
	{
		if (start == i)
			distance[i] = 0;
		else if (!pGraph->ppAdjEdge[start][i])
			distance[i] = INT32_MAX;
		else
			distance[i] = pGraph->ppAdjEdge[start][i];
	}
	for (int i = 0 ; i < pGraph->currentVertexCount - 1 ; i++)
	{
		minPos = found(distance, visited, pGraph->maxVertexCount);
		visited[minPos] = TRUE;
		for (int j = 0 ; j < pGraph->currentVertexCount ; j++)
		{
			if (!visited[j])
				if (pGraph->ppAdjEdge[minPos][j] && distance[minPos] + pGraph->ppAdjEdge[minPos][j] < distance[j])
					distance[j] = distance[minPos] + pGraph->ppAdjEdge[minPos][j];
		}
	}
	for (int i = 0 ; i < pGraph->currentVertexCount ; i++)
		printf("%d ", distance[i]);
	printf("\n");
	if (distance[end] == INT32_MAX)
		printf("%d -> Cannot Reach -> %d\n",start,end);
	else
		printf("%d -> %d Shortest Distance : %d\n", start, end, distance[end]);
}
