#include "arraygraph.h"
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    ArrayGraph *undirected;
    undirected =  createArrayUndirectedGraph(6);
	displayArrayGraph(undirected);
	
	printf("isEmptyArrayGraph : %s\n", isEmptyAG(undirected) ? "True" : "False");
	for (int i = 0 ; i < 6 ; i++)
		addVertexAG(undirected, i);
	displayArrayGraph(undirected);
	
	addEdgewithWeightAG(undirected, 0, 1, 1);
	addEdgewithWeightAG(undirected, 0, 2, 4);
	addEdgewithWeightAG(undirected, 1, 2, 2);
	addEdgewithWeightAG(undirected, 2, 3, 1);
	addEdgewithWeightAG(undirected, 3, 4, 8);
	addEdgewithWeightAG(undirected, 3, 5, 3);
	addEdgewithWeightAG(undirected, 4, 5, 4);

	displayArrayGraph(undirected);
	dijkstra(undirected, 0, 5);
	deleteArrayGraph(undirected);
	// system("leaks a.out");
}
