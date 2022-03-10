#include "arraygraph.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

ArrayGraph* createArrayGraph(int maxVertexCount, int graphType)
{
	ArrayGraph *graph;

	if (maxVertexCount < 0)
		return (NULL);
	graph = (ArrayGraph *)malloc(sizeof(ArrayGraph));
	if (!graph)
		return (NULL);
	graph->maxVertexCount = maxVertexCount;
	graph->currentVertexCount = 0;
	graph->graphType = graphType;
	graph->ppAdjEdge = (int **)calloc(1, sizeof(int *) * maxVertexCount);
	if (!graph->ppAdjEdge)
		return (NULL);
	for (int i = 0 ; i < maxVertexCount ; i++)
	{
		graph->ppAdjEdge[i] = (int *)calloc(1, sizeof(int) * maxVertexCount);
		if (!graph->ppAdjEdge[i])
			return (NULL);
	}
	graph->pVertex = (int *)calloc(1, sizeof(int) * maxVertexCount);
	if (!graph->pVertex)
		return (NULL);
	return (graph);
}

ArrayGraph* createArrayUndirectedGraph(int maxVertexCount)
{
	ArrayGraph *graph;
		
	graph = createArrayGraph(maxVertexCount, GRAPH_UNDIRECTED);
	if (!graph)
		return (NULL);
	return (graph);
}

ArrayGraph* createArrayDirectedGraph(int maxVertexCount)
{
    ArrayGraph *graph;
    
    graph = createArrayGraph(maxVertexCount, GRAPH_DIRECTED);
    if (!graph)
        return (NULL);
    return (graph);
}

int isEmptyAG(ArrayGraph* pGraph)
{
	if (!pGraph)
		return (-1);
	return (pGraph->currentVertexCount == 0);
}

int isFullAG(ArrayGraph *pGraph)
{
	if (!pGraph)
		return (-1);
	return (pGraph->currentVertexCount == pGraph->maxVertexCount);
}

int checkVertexValid(ArrayGraph *pGraph, int vertexID)
{
	if (!pGraph || vertexID < 0 || vertexID >= pGraph->maxVertexCount)
		return (FAIL);
	return (SUCCESS);
}

int addVertexAG(ArrayGraph* pGraph, int vertexID)
{
	if (!checkVertexValid(pGraph, vertexID) || isFullAG(pGraph))
		return (FAIL);
	pGraph->pVertex[vertexID] = USED;
	pGraph->currentVertexCount++;
	return (SUCCESS);
}

int addEdgeAG(ArrayGraph* pGraph, int fromVertexID, int toVertexID)
{
	if (!checkVertexValid(pGraph, fromVertexID) || !checkVertexValid(pGraph, toVertexID))
		return (FAIL);
	pGraph->ppAdjEdge[fromVertexID][toVertexID] = USED;
	if (pGraph->graphType == GRAPH_UNDIRECTED)
		pGraph->ppAdjEdge[toVertexID][fromVertexID] = USED;
	return (SUCCESS);
}

int addEdgewithWeightAG(ArrayGraph* pGraph, int fromVertexID, int toVertexID, int weight)
{
	if (!checkVertexValid(pGraph, fromVertexID) || !checkVertexValid(pGraph, toVertexID) || weight < 0)
		return (FAIL);
	pGraph->ppAdjEdge[fromVertexID][toVertexID] = weight;
	if (pGraph->graphType == GRAPH_UNDIRECTED)
		pGraph->ppAdjEdge[toVertexID][fromVertexID] = weight;
	return (SUCCESS);
}

int removeVertexAG(ArrayGraph* pGraph, int vertexID)
{
	if (!checkVertexValid(pGraph, vertexID))
		return (FAIL);
	pGraph->pVertex[vertexID] = NOT_USED;
	for (int i = 0 ; i < pGraph->maxVertexCount ; i++)
	{
		pGraph->ppAdjEdge[vertexID][i] = NOT_USED;
		pGraph->ppAdjEdge[i][vertexID] = NOT_USED;
	}
	pGraph->currentVertexCount--;
	return (SUCCESS);
}

int removeEdgeAG(ArrayGraph* pGraph, int fromVertexID, int toVertexID)
{
	if (!checkVertexValid(pGraph ,fromVertexID) || !checkVertexValid(pGraph, toVertexID))
		return (FAIL);
	pGraph->ppAdjEdge[fromVertexID][toVertexID] = NOT_USED;
	if (pGraph->graphType == GRAPH_UNDIRECTED)
		pGraph->ppAdjEdge[toVertexID][fromVertexID] = NOT_USED;
	return (SUCCESS);
}

void displayArrayGraph(ArrayGraph *graph)
{
	printf("maxVertexCount : %d\n", graph->maxVertexCount);
	printf("currentVertexCount : %d\n", graph->currentVertexCount);
	printf("graphType : %s\n", graph->graphType == 1 ? "Undirected" : "Direceted");
	printf("-------ppAdjEdge-------\n");
	for (int i = 0 ; i < graph->maxVertexCount ; i++)
	{
		for (int j = 0 ; j < graph->maxVertexCount ; j++)
			printf("%d ", graph->ppAdjEdge[i][j]);
		printf("\n");
	}
	printf("-------pVertex-------\n");
	for (int i = 0 ; i < graph->maxVertexCount ; i++)
		printf("%d ", graph->pVertex[i]);
	printf("\n");
}

void deleteArrayGraph(ArrayGraph* pGraph)
{
	if (!pGraph)
		return ;
	for (int i = 0 ; i < pGraph->maxVertexCount ; i++)
		free(pGraph->ppAdjEdge[i]);
	free(pGraph->ppAdjEdge);
	free(pGraph->pVertex);
	pGraph->maxVertexCount = 0;
	pGraph->currentVertexCount = 0;
	pGraph->graphType = 0;
	free(pGraph);
}

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
 * dijkstra() : 최단경로 알고리즘 (1)
 * 
 * pGraph : 그래프 포인터
 */
/**
 * 0 1 2 3 4 5
 * 0 : 0 1 4 99 99 99
 * 1 : 0 1 3 99 99 99
 * 2 : 0 1 3 4 99 99
 * 3 : 0 1 3 4 12 7
 * 5 : 0 1 3 4 11 7
 * 4 : ;
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
				if (pGraph->ppAdjEdge[minPos][j] && pGraph->ppAdjEdge[minPos][j] + distance[minPos] < distance[j])
					distance[j] = pGraph->ppAdjEdge[minPos][j] + distance[minPos];
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

/**
 * floydWarshall() - 최단경로 알고리즘 (2)
 * 
 * pGraph : graph 포인터
 */
void floydWarshall(ArrayGraph *pGraph)
{
	printf("---FloydWarshall Algorithm---\n");
	int result[pGraph->currentVertexCount][pGraph->currentVertexCount];

	// 초기화
	for (int i = 0 ; i < pGraph->currentVertexCount ; i++)
		for (int j = 0 ; j < pGraph->currentVertexCount ; j++) {
			if (i == j)
				result[i][j] = 0;
			else if (!pGraph->ppAdjEdge[i][j])
				result[i][j] = INT16_MAX;
			else
				result[i][j] = pGraph->ppAdjEdge[i][j];
		}
	// k = 경유 노드
	for (int k = 0 ; k < pGraph->currentVertexCount ; k++)
	 	// i = 출발 노드
		for (int i = 0 ; i < pGraph->currentVertexCount ; i++)
			// j = 도착 노드
			for (int j = 0; j < pGraph->currentVertexCount ; j++)
			{
				if (result[i][k] + result[k][j] < result[i][j])
					result[i][j] = result[i][k] + result[k][j];
			}
	
	// 결과 출력
	for (int i = 0 ; i < pGraph->currentVertexCount ; i++)
	{
		for (int j = 0 ; j < pGraph->currentVertexCount ; j++)
			printf("%3d ", result[i][j]);
		printf("\n");
	}
}
