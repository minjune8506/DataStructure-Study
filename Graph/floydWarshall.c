#include "arraygraph.h"
#include <stdio.h>
#include <stdlib.h>
/**
 * floydWarshall() - 최단경로 알고리즘
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
