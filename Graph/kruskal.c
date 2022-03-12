#include "linkedgraph.h"
#include <stdlib.h>
#include <stdio.h>

typedef struct edge
{
	int from;
	int to;
	int weight;
}edge;

/**
 * find() : x의 루트 노드를 찾아서 리턴한다.
 * 
 * x : 루트 노드를 찾을 원소
 * root : 루트 노드를 표시한 배열
 */
int find(int x, int root[])
{
    if (root[x] == x)
        return x;
    else
    	return find(root[x], root);
}

/**
 * unionParent() : Union-Parent 알고리즘
 * 
 * return : TRUE / FALSE
 * x : x의 노드 번호
 * y : y의 노드 번호
 * root : 루트 노드를 표시한 배열
 * 
 * 사이클을 형성하는지 루트 노드 비교를 통해 검사
 */
int unionParent(int x, int y, int root[])
{
    x = find(x, root);
    y = find(y, root);
	if (x == y)
		return (FALSE);
	root[y] = x;
	return (TRUE);
}

/**
 * sortEdge() : Edge 정렬
 * 
 * return : None
 * sortedEdge : 정렬할 Edge들의 배열
 * size : sortedEdge 배열의 크기
 * 
 * 가중치를 기준으로 정렬을 수행한다.
 */
void sortEdge(edge *sortedEdge, int size)
{
	int min;

	for (int i = 0 ; i < size - 1 ; i++)
	{
		min = i;
		for (int j = i + 1 ; j < size ; j++)
		{
			if (sortedEdge[min].weight > sortedEdge[j].weight)
				min = j;
		}
		if (i != min)
		{
			edge temp;

			temp = sortedEdge[min];
			sortedEdge[min] = sortedEdge[i];
			sortedEdge[i] = temp;
		}
	}
}

/**
 * Kruskal() - MST 알고리즘
 * 
 * return : None
 * pGraph : LinkedGraph 포인터
*/
void kruskal(LinkedGraph *pGraph)
{
	printf("---Kruskal Algorithm---\n");
	int root[pGraph->currentVertexCount];
	edge sortedEdge[pGraph->currentEdgeCount];
	int j = 0;

	// Union-Find를 위한 root 배열 초기화
	for (int i = 0 ; i < pGraph->currentVertexCount ; i++)
		root[i] = i;
	
	// Edge 저장
	for (int i = 0 ; i < pGraph->currentVertexCount ; i++)
	{
		ListNode *node = NULL;

		node = pGraph->ppAdjEdge[i]->headerNode.pLink;
		while (node)
		{
			sortedEdge[j].from = i;
			sortedEdge[j].to = node->vertexID;
			sortedEdge[j].weight = node->weight;
			node = node->pLink;
			j++;
		}
	}
	
	// Edge 정렬 (가중치)
	sortEdge(sortedEdge, pGraph->currentEdgeCount);

	int sum = 0;
	int edgeCount = 0;
	for (int i = 0 ; i < pGraph->currentEdgeCount ; i++)
	{
		// 같은 부모를 가지고 있지 않다면 (사이클이 없다면)
		if (unionParent(sortedEdge[i].from, sortedEdge[i].to, root))
		{
			sum += sortedEdge[i].weight;
			edgeCount++;

			// Minimum Spanning Tree는 정확히 노드 개수 - 1 개의 간선을 가진다.
			if (edgeCount == pGraph->currentVertexCount - 1)
				break ;
		}
	}

	// MST의 간선 가중치의 합을 출력
	printf("sum : %d\n", sum);
}
