#include "heap.h"
#include <stdlib.h>
#include <stdio.h>

/**
 * createHeap() - Heap 생성
 * 
 * return : 생성된 Heap의 주소
 * maxElement : 최대 원소 갯수
 */
heap *createHeap(int maxElementCount)
{
	heap *pHeap;
	
	pHeap = (heap *)malloc(sizeof(heap));
	if (!pHeap)
		return (NULL);
	pHeap->maxElementCount = maxElementCount;
	pHeap->currentElementCount = 0;
	pHeap->pElement = (heapNode *)malloc(sizeof(heapNode) * maxElementCount);
	if (!pHeap->pElement)
		return (NULL);
	return (pHeap);
}

/**
 * deleteHeap() - Heap 제거
 * 
 * return : None
 * pHeap : Heap의 포인터
 */
void deleteHeap(heap *pHeap)
{
	if (!pHeap)
		return ;
	for (int i = 0 ; i < pHeap->maxElementCount ; i++)
		pHeap->pElement[i].data = 0;
	pHeap->currentElementCount = 0;
	pHeap->maxElementCount = 0;
	free(pHeap->pElement);
	free(pHeap);
}

/**
 * isHeapFull() - Heap이 가득 찼는지 확인
 * 
 * return : True (1) / False (0)
 * pHeap : Heap의 포인터
 */
int isHeapFull(heap *pHeap)
{
	if (!pHeap)
		return (-1);
	return (pHeap->currentElementCount >= pHeap->maxElementCount - 1);
}

/**
 * isHeapEmpty() - Heap이 비었는지 확인
 * 
 * return : True (1) / False (0)
 * pHeap : Heap의 포인터
 */
int isHeapEmpty(heap *pHeap)
{
	if (!pHeap)
		return (-1);
	return (pHeap->currentElementCount == 0);
}

/**
 * swap() - swap data
 */
void swap(int *a, int *b)
{
	int tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

/**
 * insertMaxHeapNode() - Max Heap에 Node 추가
 * 
 * return : 0 (EXIT_SUCCESS) / 1 (EXIT_FAILURE)
 * pHeap : Heap의 포인터
 * element : 추가할 노드
 */
int insertMaxHeapNode(heap *pHeap, heapNode element)
{
	if (!pHeap || isHeapFull(pHeap))
		return (EXIT_FAILURE);
	pHeap->currentElementCount++;
	int i = pHeap->currentElementCount;
	pHeap->pElement[i] = element;
	while ((i != 1) && pHeap->pElement[i / 2].data < element.data)
	{
		swap(&pHeap->pElement[i / 2].data, &pHeap->pElement[i].data);
		i /= 2;
	}
	return (EXIT_SUCCESS);
}

/**
 * deleteMaxHeapNode() - Max Heap의 Root Node 반환
 * 
 * return : Root Node의 data
 * pHeap : Heap의 포인터
 */
int deleteMaxHeapNode(heap *pHeap)
{
	int result;

	if (!pHeap || isHeapEmpty(pHeap))
		return (-1);
	swap(&pHeap->pElement[1].data, &pHeap->pElement[pHeap->currentElementCount].data);
	result = pHeap->pElement[pHeap->currentElementCount].data;
	pHeap->pElement[pHeap->currentElementCount].data = 0;
	pHeap->currentElementCount--;
	int parent = 1;
	int child = 2;
	while (child <= pHeap->currentElementCount)
	{
		if (child < pHeap->currentElementCount)
			if (pHeap->pElement[child].data < pHeap->pElement[child + 1].data)
				child++;
		if (pHeap->pElement[parent].data < pHeap->pElement[child].data)
			swap(&pHeap->pElement[parent].data, &pHeap->pElement[child].data);
		parent = child;
		child = parent * 2;
	}
	return (result);
}

/**
 * insertMinHeapNode() - Min Heap에 Node 추가
 * 
 * return : 0 (EXIT_SUCCESS) / 1 (EXIT_FAILURE)
 * pHeap : Heap의 포인터
 * element : 추가할 노드
 */
int insertMinHeapNode(heap *pHeap, heapNode element)
{
	if (!pHeap || isHeapFull(pHeap))
		return (EXIT_FAILURE);
	pHeap->currentElementCount++;
	int i = pHeap->currentElementCount;
	pHeap->pElement[i] = element;
	while ((i != 1) && pHeap->pElement[i / 2].data > element.data)
	{
		swap(&pHeap->pElement[i / 2].data, &pHeap->pElement[i].data);
		i /= 2;
	}
	return (EXIT_SUCCESS);
}

/**
 * deleteMinHeapNode() - Min Heap의 Root Node 반환
 * 
 * return : Root Node의 data
 * pHeap : Heap의 포인터
 */
int deleteMinHeapNode(heap *pHeap)
{
	heapNode result;

	if (!pHeap || isHeapEmpty(pHeap))
		return (-1);
	swap(&pHeap->pElement[1].data, &pHeap->pElement[pHeap->currentElementCount].data);
	result = pHeap->pElement[pHeap->currentElementCount];
	pHeap->pElement[pHeap->currentElementCount].data = 0;
	pHeap->currentElementCount--;
	int parent = 1;
	int child = 2;
	while (child <= pHeap->currentElementCount)
	{
		if (child < pHeap->currentElementCount)
			if (pHeap->pElement[child].data > pHeap->pElement[child + 1].data)
				child++;
		if (pHeap->pElement[parent].data > pHeap->pElement[child].data)
			swap(&pHeap->pElement[parent].data, &pHeap->pElement[child].data);
		parent = child;
		child = parent * 2;
	}
	return (result.data);
}

void display(heap *pHeap)
{
	printf("currentElementCount : %d\n", pHeap->currentElementCount);
	printf("maxElementCount : %d\n", pHeap->maxElementCount);
	for (int i = 0 ; i <= pHeap->currentElementCount ; i++)
		printf("%d ", pHeap->pElement[i].data);
	printf("\n");
}
