#include "linkedgraph.h"
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	LinkedGraph *graph;

	graph = createLinkedUndirectedGraph(6);
	for (int i = 0 ; i <= 6 ; i++)
		addVertexLG(graph, i);
	addEdgewithWeightLG(graph, 0, 1, 4);
	addEdgewithWeightLG(graph, 0, 2, 3);
	addEdgewithWeightLG(graph, 0, 1, 2);	
	addEdgewithWeightLG(graph, 2, 3, 1);
	addEdgewithWeightLG(graph, 3, 4, 1);
	addEdgewithWeightLG(graph, 3, 5, 5);
	addEdgewithWeightLG(graph, 4, 5, 6);
	displayLinkedGraph(graph);
	
	dfs(graph, 0);
	bfs(graph, 0);
	char visited[graph->currentVertexCount];
	printf("-----recursive DFS-----\n");
	recursiveDFS(graph, 0, visited);
	printf("\n");
	kruskal(graph);
	deleteLinkedGraph(graph);
	// system("leaks a.out");
}
