#include "linkedgraph.h"
#include "linkedstack.h"
#include "linkeddeque.h"
#include <stdio.h>

/**
 * dfs() - Depth-First Search
 * 
 * return : None
 * pGraph : LinkedGraph의 포인터
 * start : 시작 정점의 번호
 * 
 * Stack과 반복문을 이용한 DFS 구현
 */
void dfs(LinkedGraph *pGraph, int start)
{
	LinkedStack *stack;
	StackNode element;
	StackNode *temp;
	int id;
	char visited[pGraph->currentVertexCount];

	printf("----------DFS----------\n");
	stack = createLinkedStack();
	element.data = pGraph->pVertex[start];
	pushLS(stack, element);
	visited[pGraph->pVertex[start]] = TRUE;
	while (!isLinkedStackEmpty(stack))
	{
		temp = popLS(stack);
		printf("%d ", temp->data);
		for (int i = 0 ; i < pGraph->ppAdjEdge[temp->data]->currentElementCount ; i++)
		{
			id = getLLElement(pGraph->ppAdjEdge[temp->data], i)->vertexID;
			if (visited[id] != TRUE)
			{
				element.data = id;
				pushLS(stack, element);
				visited[id] = TRUE;
			}
		}
	}
	printf("\n");
}

/**
 * recursiveDFS() - Depth-First Search
 * 
 * return : None
 * pGraph : LinkedGraph의 포인터
 * start : 시작 정점의 번호
 * visited : 방문했는지 표시하는 배열
 * 
 * 재귀를 이용한 DFS 구현
 */
void recursiveDFS(LinkedGraph *pGraph, int start, char visited[])
{
	visited[pGraph->pVertex[start]] = TRUE;
	printf("%d ", pGraph->pVertex[start]);
	for (int i = 0 ; i < pGraph->ppAdjEdge[start]->currentElementCount ; i++)
	{
		int data = getLLElement(pGraph->ppAdjEdge[start], i)->vertexID;
		if (visited[pGraph->pVertex[data]] != TRUE)
			recursiveDFS(pGraph, data, visited);
	}
}

/**
 * bfs() - Breadth-Frist Search
 * 
 * return : None
 * pGraph : LinkedGraph의 포인터
 * start : 시작 정점의 번호
 * 
 * Queue를 이용한 너비 우선 탐색
 */
void bfs(LinkedGraph *pGraph, int start)
{
	LinkedDeque *pDequeue;
	DequeNode element;
	DequeNode *temp;
	int id;
	char visited[pGraph->currentVertexCount];
	
	printf("----------BFS----------\n");
	pDequeue = createLinkedDeque();
	element.data = pGraph->pVertex[start];
	insertRearLD(pDequeue, element);
	visited[pGraph->pVertex[start]] = TRUE;
	while(!isLinkedDequeEmpty(pDequeue))
	{
		temp = deleteFrontLD(pDequeue);
		printf("%d ", temp->data);
		for (int i = 0 ; i < pGraph->ppAdjEdge[temp->data]->currentElementCount ; i++)
		{
			id = getLLElement(pGraph->ppAdjEdge[temp->data], i)->vertexID;
			if (visited[id] != TRUE)
			{
				element.data = id;
				insertRearLD(pDequeue, element);
				visited[id] = TRUE;
			}
		}
	}
	printf("\n");
}
