#include "linkedgraph.h"
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

LinkedGraph* createLinkedGraph(int maxVertexCount, int graphType)
{
    LinkedGraph *graph;
    
    if (maxVertexCount < 0)
        return (NULL);
    graph = (LinkedGraph *)malloc(sizeof(LinkedGraph));
    if (!graph)
        return (NULL);
    graph->maxVertexCount = maxVertexCount;
	graph->currentVertexCount = 0;
    graph->currentEdgeCount = 0;
    graph->graphType = graphType;
    graph->ppAdjEdge = (LinkedList **)calloc(1, sizeof(LinkedList *) * maxVertexCount);
    if (!graph->ppAdjEdge)
        return (NULL);
    graph->pVertex = (int *)calloc(1, sizeof(int) * maxVertexCount);
    if (!graph->pVertex)
        return (NULL);
    return (graph);
}

LinkedGraph* createLinkedUndirectedGraph(int maxVertexCount)
{
	LinkedGraph *graph;
	
	graph = createLinkedGraph(maxVertexCount, GRAPH_UNDIRECTED);
	if (!graph)
		return (NULL);
	return (graph);
}

LinkedGraph* createLinkedDirectedGraph(int maxVertexCount)
{
	LinkedGraph *graph;
	
	graph = createLinkedGraph(maxVertexCount, GRAPH_DIRECTED);
	if (!graph)
		return (NULL);
	return (graph);
}

int isEmptyAG(LinkedGraph *pGraph)
{
    if (!pGraph)
        return (-1);
    return (pGraph->currentVertexCount == 0);
}

int isFullAG(LinkedGraph *pGraph)
{
	if (!pGraph)
		return (-1);
	return (pGraph->currentVertexCount == pGraph->maxVertexCount);
}

int checkVertexValid(LinkedGraph* pGraph, int vertexID)
{
    if (!pGraph || vertexID < 0)
        return (FAIL);
    return (SUCCESS);
}

int addVertexLG(LinkedGraph* pGraph, int vertexID)
{
	if (!checkVertexValid(pGraph, vertexID) || isFullAG(pGraph))
		return (FAIL);
	for (int i = 0 ; i < getMaxVertexCountLG(pGraph) ; i++)
	{
		if (!pGraph->ppAdjEdge[i])
		{
			pGraph->ppAdjEdge[i] = createLinkedList(vertexID);
			pGraph->pVertex[i] = vertexID;
			pGraph->currentVertexCount++;
			return (SUCCESS);
		}
	}
	return (FAIL);
}

int removeVertexLG(LinkedGraph* pGraph, int vertexID)
{
	if (!checkVertexValid(pGraph, vertexID) || isEmptyAG(pGraph))
		return (FAIL);
    for (int i = 0 ; i < pGraph->maxVertexCount ; i++)
		deleteGraphNode(pGraph->ppAdjEdge[i], vertexID);
	pGraph->currentEdgeCount = sumEdgeCountLG(pGraph);
	for (int i = 0 ; i < pGraph->maxVertexCount ; i++)
	{
		if (pGraph->ppAdjEdge[i] && pGraph->ppAdjEdge[i]->vertexID == vertexID)
		{
			deleteLinkedList(pGraph->ppAdjEdge[i]);
			pGraph->ppAdjEdge[i] = NULL;
			pGraph->pVertex[i] = NOT_USED;
			pGraph->currentVertexCount--;
		}
	}
	return (SUCCESS);
}

int addEdgeLG(LinkedGraph* pGraph, int fromVertexID, int toVertexID)
{
    ListNode toVertex;
	ListNode fromVertex;

    if (!checkVertexValid(pGraph, fromVertexID) || !checkVertexValid(pGraph, toVertexID))
        return (FAIL);
    toVertex.vertexID = toVertexID;
	toVertex.weight = 0;
	for (int i = 0 ; i < pGraph->maxVertexCount ; i++)
	{
		if (!pGraph->ppAdjEdge[i])
			continue ;
		if (pGraph->ppAdjEdge[i]->vertexID == fromVertexID)
    		addLLElement(pGraph->ppAdjEdge[i], pGraph->ppAdjEdge[i]->currentElementCount, toVertex);
	}
	if (pGraph->graphType == GRAPH_UNDIRECTED)
	{
		fromVertex.vertexID = fromVertexID;
		fromVertex.weight = 0;
		for (int i = 0 ; i < pGraph->maxVertexCount ; i++)
		{
			if (!pGraph->ppAdjEdge[i])
				continue ;
			if (pGraph->ppAdjEdge[i]->vertexID == toVertexID)
    			addLLElement(pGraph->ppAdjEdge[i], pGraph->ppAdjEdge[i]->currentElementCount, fromVertex);
		}
	}
    pGraph->currentEdgeCount++;
	return (SUCCESS);
}

int addEdgewithWeightLG(LinkedGraph* pGraph, int fromVertexID, int toVertexID, int weight)
{
	ListNode toVertex;
	
	if (!checkVertexValid(pGraph, fromVertexID) || !checkVertexValid(pGraph, toVertexID) || weight < 0)
		return (FAIL);
	toVertex.vertexID = toVertexID;
	toVertex.weight = weight;
	for (int i = 0 ; i < pGraph->maxVertexCount ; i++)
	{
		if (!pGraph->ppAdjEdge[i])
			continue ;
		if (pGraph->ppAdjEdge[i]->vertexID == fromVertexID)
    		addLLElement(pGraph->ppAdjEdge[i], pGraph->ppAdjEdge[i]->currentElementCount, toVertex);
	}
    if (pGraph->graphType == GRAPH_UNDIRECTED)
    {
        ListNode fromVertex;
        fromVertex.vertexID = fromVertexID;
        fromVertex.weight = weight;
		for (int i = 0 ; i < pGraph->maxVertexCount ; i++)
		{
			if (!pGraph->ppAdjEdge[i])
				continue ;
			if (pGraph->ppAdjEdge[i]->vertexID == toVertexID)
    			addLLElement(pGraph->ppAdjEdge[i], pGraph->ppAdjEdge[i]->currentElementCount, fromVertex);
		}
    }
	pGraph->currentEdgeCount++;
	return (SUCCESS);
}

int findGraphNodePosition(LinkedList* pList, int vertexID)
{
    ListNode *temp;
	int pos;

	if (!pList || vertexID < 0)
		return (FAIL);
    temp = pList->headerNode.pLink;
    pos = 0;
    while (temp)
	{
		if (temp->vertexID == vertexID)
			return (pos);
		temp = temp->pLink;
		pos++;
	}
	return (-1);
}

int removeEdgeLG(LinkedGraph* pGraph, int fromVertexID, int toVertexID)
{
	int pos;

	if (!checkVertexValid(pGraph, fromVertexID) || !checkVertexValid(pGraph, toVertexID))
		return (FAIL);
	for (int i = 0 ; i < getMaxVertexCountLG(pGraph) ; i++)
		if (pGraph->ppAdjEdge[i] && pGraph->ppAdjEdge[i]->vertexID == fromVertexID)
			deleteGraphNode(pGraph->ppAdjEdge[i], toVertexID);
	if (pGraph->graphType == GRAPH_UNDIRECTED)
		for (int i = 0 ; i < getMaxVertexCountLG(pGraph) ; i++)
			if (pGraph->ppAdjEdge[i] && pGraph->ppAdjEdge[i]->vertexID == toVertexID)
				deleteGraphNode(pGraph->ppAdjEdge[i], fromVertexID);
	pGraph->currentEdgeCount = sumEdgeCountLG(pGraph);
	return (SUCCESS);
}

void deleteGraphNode(LinkedList* pList, int delVertexID)
{
	if (!pList)
		return ;
	int pos = -1;
	while (TRUE)
	{
		pos = findGraphNodePosition(pList, delVertexID);
		if (pos < 0)
			break ;
		removeLLElement(pList, pos);
	}
}

void displayLinkedGraph(LinkedGraph* pGraph)
{
	ListNode *temp;

	printf("maxVertexCount : %d\n", getMaxVertexCountLG(pGraph));
	printf("currentVertexCount : %d\n", getVertexCountLG(pGraph));
	printf("currentEdgeCount : %d\n", getEdgeCountLG(pGraph));
	printf("graphType : %s\n", getGraphTypeLG(pGraph) == 1 ? "Undirected" : "Directed");
	printf("-----ppAdjEdge-----\n");
    for (int i = 0 ; i < pGraph->maxVertexCount; i++)
    {
		if (!pGraph->ppAdjEdge[i])
			continue ;
		printf("ID %d : ", pGraph->ppAdjEdge[i]->vertexID);
	    temp = pGraph->ppAdjEdge[i]->headerNode.pLink;
		if (!temp)
			printf("Empty List");
        while (temp)
        {
            printf("%d -> ", temp->vertexID);
            temp = temp->pLink;
        }
	    printf("\n");
    }
	printf("-----pVertex-----\n");
	for (int i = 0 ; i < getMaxVertexCountLG(pGraph) ; i++)
		printf("%d ", pGraph->pVertex[i]);
	printf("\n");
}

int sumEdgeCountLG(LinkedGraph *pGraph)
{
	int edgeCount = 0;

	if (!pGraph)
		return (-1);
	for (int i = 0 ; i < getMaxVertexCountLG(pGraph) ; i++)
	{
		if (!pGraph->ppAdjEdge[i])
			continue ;
		edgeCount += pGraph->ppAdjEdge[i]->currentElementCount;
	}
	return (edgeCount);
}

int getEdgeCountLG(LinkedGraph* pGraph)
{
    if (!pGraph)
		return (-1);
	return (pGraph->currentEdgeCount);
}

int getVertexCountLG(LinkedGraph* pGraph)
{
	if (!pGraph)
		return (-1);
	return (pGraph->currentVertexCount);
}

int getMaxVertexCountLG(LinkedGraph* pGraph)
{
	if (!pGraph)
		return (-1);
	return (pGraph->maxVertexCount);
}

int getGraphTypeLG(LinkedGraph* pGraph)
{
	if (!pGraph)
		return (-1);
	return (pGraph->graphType);
}

void deleteLinkedGraph(LinkedGraph* pGraph)
{
	for (int i = 0 ; i < getMaxVertexCountLG(pGraph) ; i++)
	{
		if (!pGraph->ppAdjEdge[i])
			continue ;
		removeVertexLG(pGraph, pGraph->ppAdjEdge[i]->vertexID);
	}
	sumEdgeCountLG(pGraph);
	assert(getVertexCountLG(pGraph) == 0);
	assert(getEdgeCountLG(pGraph) == 0);
	free(pGraph->ppAdjEdge);
	pGraph->ppAdjEdge = NULL;
	free(pGraph->pVertex);
	pGraph->pVertex = NULL;
	pGraph->graphType = 0;
	pGraph->maxVertexCount = 0;
	free(pGraph);
}

int main(void)
{
	LinkedGraph *graph;
	
	graph = createLinkedDirectedGraph(5);
	addVertexLG(graph, 10);
	addVertexLG(graph, 20);
	addVertexLG(graph, 30);
	addVertexLG(graph, 40);
	addVertexLG(graph, 50);
	displayLinkedGraph(graph);

	addEdgeLG(graph, 10, 20);
	addEdgeLG(graph, 20, 50);
	addEdgeLG(graph, 30, 40);
	addEdgeLG(graph, 20, 30);
	addEdgeLG(graph, 10, 40);
	displayLinkedGraph(graph);
	
	removeEdgeLG(graph, 10, 20);
	removeEdgeLG(graph, 30, 40);
	displayLinkedGraph(graph);

	removeVertexLG(graph, 10);
	removeVertexLG(graph, 30);
	removeVertexLG(graph, 50);
	displayLinkedGraph(graph);

	deleteLinkedGraph(graph);
	// system("leaks a.out");
}
