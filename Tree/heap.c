#include "heap.h"

heap *createHeap(int maxElementCount)
{
	heap *pHeap;
	
	pHeap = (heap *)malloc(sizeof(heap));
	if (!pHeap)
		return (NULL);
	pHeap->maxElementCount = maxElementCount;
	pHeap->currentElementCount = 0;
	pHeap->rootNode = (heapNode *)malloc(sizeof(heapNode) * maxElementCount);
	if (!pHeap->rootNode)
		return (NULL);
	return (pHeap);
}
	
void deleteHeap(heap *pHeap)
{
	if (!pHeap)
		return ;
	for (int i = 0 ; i < pHeap->currentElementCount ; i++)
	{
		pHeap->rootNode[i].data = 0;
		pHeap->currentElementCount--;
	}
	pHeap->maxElementCount = 0;
	free(pHeap->rootNode);
	free(pHeap);
}

int isHeapFull(heap *pHeap)
{
	if (!pHeap)
		return (-1);
	return (pHeap->currentElementCount >= pHeap->maxElementCount - 1);
}

void swap(int *a, int *b)
{
	int tmp;
	tmp = *a;
	*a = *b;
	*b = tmp;
}

void insertMaxHeapNode(heap *pHeap, heapNode element)
{
	if (!pHeap || isHeapFull(pHeap))
		return ;
	pHeap->currentElementCount++;
	int i = pHeap->currentElementCount;
	pHeap->rootNode[pHeap->currentElementCount] = element;
	while ((i != 1) && pHeap->rootNode[i / 2].data < element.data)
	{
		swap(&pHeap->rootNode[i / 2].data, &pHeap->rootNode[i].data);
		i /= 2;
	}
}

int isHeapEmpty(heap *pHeap)
{
	if (!pHeap || pHeap->currentElementCount == 0)
		return (TRUE);
	return (FALSE);
}

int deleteMaxHeapNode(heap *pHeap)
{
	heapNode result;

	if (!pHeap || isHeapEmpty(pHeap))
		return (-1);
	swap(&pHeap->rootNode[1].data, &pHeap->rootNode[pHeap->currentElementCount].data);
	result = pHeap->rootNode[pHeap->currentElementCount];
	pHeap->rootNode[pHeap->currentElementCount].data = 0;
	pHeap->currentElementCount--;
	int parent = 1;
	int child = 2;
	while (child <= pHeap->currentElementCount)
	{
		if (child <= pHeap->currentElementCount)
		{
			if (child + 1 <= pHeap->currentElementCount && pHeap->rootNode[child].data < pHeap->rootNode[child + 1].data)
				child++;
		}
		if (pHeap->rootNode[parent].data < pHeap->rootNode[child].data)
			swap(&pHeap->rootNode[parent].data, &pHeap->rootNode[child].data);
		parent = child;
		child = parent * 2;
	}
	return (result.data);
}

int deleteMinHeapNode(heap *pHeap)
{
	heapNode result;

	if (!pHeap || isHeapEmpty(pHeap))
		return (-1);
	swap(&pHeap->rootNode[1].data, &pHeap->rootNode[pHeap->currentElementCount].data);
	result = pHeap->rootNode[pHeap->currentElementCount];
	pHeap->rootNode[pHeap->currentElementCount].data = 0;
	pHeap->currentElementCount--;
	display(pHeap);
	int parent = 1;
	int child = 2;
	while (child <= pHeap->currentElementCount)
	{
		if (child <= pHeap->currentElementCount)
		{
			if (child + 1 <= pHeap->currentElementCount && pHeap->rootNode[child].data > pHeap->rootNode[child + 1].data)
				child++;
		}
		if (pHeap->rootNode[parent].data > pHeap->rootNode[child].data)
			swap(&pHeap->rootNode[parent].data, &pHeap->rootNode[child].data);
		parent = child;
		child = parent * 2;
	}
	return (result.data);
}

void insertMinHeapNode(heap *pHeap, heapNode element)
{
	if (!pHeap || isHeapFull(pHeap))
		return ;
	pHeap->currentElementCount++;
	int i = pHeap->currentElementCount;
	pHeap->rootNode[pHeap->currentElementCount] = element;
	while ((i != 1) && pHeap->rootNode[i / 2].data > element.data)
	{
		swap(&pHeap->rootNode[i / 2].data, &pHeap->rootNode[i].data);
		i /= 2;
	}
}

void display(heap *pHeap)
{
	printf("currentElementCount : %d\n", pHeap->currentElementCount);
	printf("maxElementCount : %d\n", pHeap->maxElementCount);
	for (int i = 0 ; i <= pHeap->currentElementCount ; i++)
		printf("%d ", pHeap->rootNode[i].data);
	printf("\n");
}

int main(void)
{
	heap *maxHeap;
	heapNode element;

	maxHeap = createHeap(10);
	element.data = 30;
	insertMinHeapNode(maxHeap, element);
	display(maxHeap);
	element.data = 20;
	insertMinHeapNode(maxHeap, element);
	display(maxHeap);
	element.data = 40;
	insertMinHeapNode(maxHeap, element);
	display(maxHeap);
	element.data = 10;
	insertMinHeapNode(maxHeap, element);
	display(maxHeap);
	element.data = 24;
	insertMinHeapNode(maxHeap, element);
	display(maxHeap);
	element.data = 34;
	insertMinHeapNode(maxHeap, element);
	display(maxHeap);
	element.data = 46;
	insertMinHeapNode(maxHeap, element);
	display(maxHeap);
	printf("%d\n", deleteMinHeapNode(maxHeap));
	display(maxHeap);

	deleteHeap(maxHeap);
	maxHeap=NULL;
	system("leaks a.out");
}
//      46
//   24    40
// 10 20  30 34

//      20
//   24    34
// 30 46  40 
